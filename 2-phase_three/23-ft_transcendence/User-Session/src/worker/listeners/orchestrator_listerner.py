import redis
import os
import asyncio
import json
import logging

from rooms.models import Match, Room
from asgiref.sync import sync_to_async
from players.models import Player, MatchPlayer
from channels.layers import get_channel_layer

redis_client = redis.Redis(host=os.environ.get("REDIS_HOST", "localhost"), port=int(os.environ.get("REDIS_PORT", 6379)), db=0, decode_responses=True)

logger = logging.getLogger(__name__)

class OrchestratorListener:
    def __init__(self):
        self.queue_name = "game-sync-session-queue"
        self.running_tasks = set()

    @sync_to_async
    def increment_stage(self, match):
        if match.room:
            match.room.stage = match.stage
            match.room.save()
            logger.info(f"INCREMENT STAGE Match {match.id} stage: {match.stage}, Room {match.room.id} stage: {match.room.stage}")
        else:
            logger.error(f"Error | {OrchestratorListener.__name__} | increment_stage | Match {match.id} | Room not found.")

    @sync_to_async
    def update_stage_tournament_ended(self, match):
        match.room.stage = 0
        match.room.save()

    @sync_to_async
    def update_bracket_position(self, player):
        if player.bracketsPosition % 2 == 0:
            new_position = player.bracketsPosition // 2
        else:
            new_position = (player.bracketsPosition + 1) // 2
        player.bracketsPosition = new_position
        if player.bracketsPosition % 2 == 0:
            player.profileColor = 1
        else:
            player.profileColor = 0
        player.save()
        logger.info(f"UPDATE POSITION Player {player.id} {player.name}, Position {player.bracketsPosition}")

    async def process_game_sync(self, message):
        logger.info(f"\033[93mOrchestrator recebeu mensagem {message}\033[0m")
        try:
            data = json.loads(message)
        except json.JSONDecodeError as e:
            return logger.error(f"Error | {OrchestratorListener.__name__} | process_game_sync | {e}")

        match = await Match.objects.filter(id=data["matchId"]).afirst()
        if (match is None):
            return logger.error(f"Error | {OrchestratorListener.__name__} | process_game_sync | {e}")

        if data["type"] == "game-created":
            logger.info(f"{OrchestratorListener.__name__} | game-created | Match {match.id} | Game {match.gameId}.")
            match.gameId = data["gameId"]

        if data["type"] == "game-started":
            logger.info(f"{OrchestratorListener.__name__} | game-started | Match {match.id} | Game {match.gameId}.")
            match.status = 2

        if data["type"] == "game-over":
            logger.info(f"{OrchestratorListener.__name__} | game-over | Match {match.id} | Game {match.gameId}.")
            players = await sync_to_async(list)(
                match.players_in_match.select_related("player").all()
            )

            for player in players:
                player_data = next((p for p in data["players"] if p["id"] == player.player.id), None)
                if player_data:
                    player.position = player_data["rank"]
                    await sync_to_async(player.save)()

            match.status = 3
            match.winner = data["winner"]

            if (match.nextMatch is not None):
                next_match = await Match.objects.filter(id=match.nextMatch).afirst()
                winner = await Player.objects.filter(id=match.winner).afirst()
                if next_match is not None and winner is not None:
                    await MatchPlayer.objects.acreate(match=next_match, player=winner)

                    as_players = await MatchPlayer.objects.filter(match=next_match).acount()
                    if as_players == 2:
                        next_match.status = 1
                        await self.increment_stage(next_match)
                        channel_layer = get_channel_layer()

                        match_players = MatchPlayer.objects.filter(match=next_match).select_related('player')

                        asyncio.create_task(self.send_sync_match_message(channel_layer, next_match, match_players))
                        await next_match.asave()
                    await self.update_bracket_position(winner)
            else:
                await self.update_stage_tournament_ended(match)

            logger.info(f"Finished | {OrchestratorListener.__name__} | game-over | Match {match.id} | Game {match.gameId}.")

        await match.asave()

    async def listen(self):
        while True:
            await asyncio.sleep(1)
            message = {}
            message = redis_client.lpop(self.queue_name)
            if message is None:
                continue
            await self.process_game_sync(message)
    
    async def send_sync_match_message(self, channel_layer, next_match, match_players):
        logger.info(f"Starting | {OrchestratorListener.__name__} | {self.send_sync_match_message.__name__}.")
        while True:
            logger.info(f"Waiting user enter in the room.")
            players_connected = await match_players.filter(player__isConnected=True).acount()
            total_players = await match_players.acount()

            if players_connected == total_players:
                break

            await asyncio.sleep(5)
        
        players_list = [
            {"id": match_player.player.id}
            async for match_player in match_players
        ]

        await channel_layer.group_send(
            f"room_{next_match.room.code}",
            {
                "type": "sync.match",
                "matches": [
                    {
                        "id": next_match.id,
                        "players": players_list,
                    }
                ],
            },
        )