import redis
import json
import os
import logging

from games_worker.game_core.game_session import GameSession
from games_app.models.game_model import GameModel
from games_app.models.player_model import PlayerModel
from games_app.models.score_model import ScoreModel
from asgiref.sync import sync_to_async
import asyncio

logger = logging.getLogger(__name__)
redis_client = redis.Redis(host=os.environ.get("REDIS_HOST", "localhost"), port=int(os.environ.get("REDIS_PORT", 6379)), db=0, decode_responses=True)

class GameMakerListener:
    def __init__(self):
        self.game_sessions = {}
        self.queue_name = "create-game-queue"
        self.sync_session_queue = "game-sync-session-queue"
        self.running_tasks = set()

    async def create_game(self, message):
        logging.info(f"\033[32mgame core recebeu msg: {message}\033[0m")
        data = json.loads(message)
        game_session = await sync_to_async(GameModel.objects.create)(
            status=0, matchId=data["matchId"], roomId=data["roomId"],
            isSinglePlayer=data["isSinglePlayer"], created_by=data["ownerId"], stage=data['stage']
        )

        players = []
        for player in data["players"]:
            players.append({"id": player["id"], "color": player["color"]})
            try:
                py = await sync_to_async(PlayerModel.objects.filter(id=player["id"]).first)()
                if (py is None):
                    py = await sync_to_async(PlayerModel.objects.create)(id=player["id"],name=player["name"], gameId=game_session, color=player["color"])
                score = await sync_to_async(ScoreModel.objects.create)(playerId=py, gameId=game_session)
            except Exception as e:
                logger.error(f"\033[31mError creating player {player['id']}: {str(e)}\033[0m")
                await sync_to_async(game_session.delete)()
                return None
        task = None
        try:
            await sync_to_async(game_session.save)()
            game_job = GameSession(players, game_session.id, data["roomId"], data["roomType"])
            self.game_sessions[data["roomId"]] = game_job
            redis_client.rpush(
                self.sync_session_queue,
                json.dumps({
                    "type": "game-created",
                    "matchId": game_session.matchId,
                    "gameId": game_session.id
                })
            )
            await asyncio.sleep(1)
            task = asyncio.create_task(game_job.startGame())
            self.running_tasks.add(task)
            task.add_done_callback(self.running_tasks.discard)
        except Exception as e:
            logger.error(f"\033[31mError creating player {player['id']}: {str(e)}\033[0m")
            await sync_to_async(game_session.delete)()
            task.cancel()
            self.running_tasks.discard(task)
            return None
        return game_job

    async def listen(self):
        while True:
            await asyncio.sleep(1)
            message = redis_client.lpop(self.queue_name)
            if message is None:
                continue
            await self.create_game(message)

    async def wait_for_tasks(self):
        if self.running_tasks:
            await asyncio.wait(self.running_tasks)