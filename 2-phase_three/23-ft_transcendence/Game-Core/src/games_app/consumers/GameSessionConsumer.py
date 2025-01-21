import logging
import json
import redis

from channels.generic.websocket import AsyncWebsocketConsumer
from channels.layers import get_channel_layer
from asgiref.sync import sync_to_async
from games_app.models.game_model import GameModel
from games_app.models.player_model import PlayerModel
from games_app.models.score_model import ScoreModel
from games_app.repositories.game_repository import GameRepository

logger = logging.getLogger(__name__)

redis_client = redis.Redis(host='redis', port=6379, db=0)

class GameSessionConsumer(AsyncWebsocketConsumer):

    async def connect(self):
        self.gameId = self.scope['url_route']['kwargs']['game_id']
        cookies_header = dict(self.scope['headers']).get(b'cookie', b'').decode('utf-8')
        cookies = dict(item.split("=") for item in cookies_header.split("; ") if "=" in item)
        self.userId = cookies.get("userId")
        self.game_channel = f"game_session_{self.gameId}"
        self.player_channel = f"{self.game_channel}_{self.userId}"

        if not self.userId or not self.gameId:
            await self.close(code=400)
            return

        logger.info(f"{GameSessionConsumer.__name__} | criando conexao | User {self.userId} conectando ao game {self.gameId}.")

        try:
            user = await GameRepository.get_player_by_id_and_by_game_id(self.userId, self.gameId)
            if user is None:
                logger.info(f"{self.__class__.__name__} | User {self.userId} disconnected from game {self.gameId} - User not found.")
                await self.close(code=204)
                return

            await GameRepository.update_player_connected_status(user.id, True)

            await self.channel_layer.group_add(
                self.game_channel,
                self.channel_name
            )

            await self.accept()

            scores = await GameRepository.get_players_in_game(self.gameId)
            players = [score.playerId for score in scores]
            for player in players:
                await self.channel_layer.group_send(
                self.game_channel,
                {
                    "type": "update_score",
                    "playerColor": player.color,
                    "playerScore": player.score,
                    "expiry": 0.02
                }
                )
            logger.info(f"{GameSessionConsumer.__name__} | Usuario conectado com sucesso")
        except Exception as e:
            logger.error(f"{GameSessionConsumer.__name__} | Error | {e}")
            await self.close()

    async def disconnect(self, close_code):
        user = await GameRepository.get_player_by_id_and_by_game_id(self.userId, self.gameId)
        if user is not None:
            await GameRepository.update_player_connected_status(user.id, False)
        
        await self.channel_layer.group_discard(
            self.game_channel,
            self.channel_name
        )

    async def receive(self, text_data):
        data = json.loads(text_data)
        direction = data.get('direction')

        user = await GameRepository.get_player_by_id_and_by_game_id(self.userId, self.gameId)

        directions_by_color = {
            "0": ["w", "s"],
            "1": ["w", "s"],
            "2": ["a", "d"],
            "3": ["a", "d"],
        }

        if user.color in directions_by_color and direction in directions_by_color[user.color]:
            move = {
                "userId": self.userId,
                "direction": 1 if direction in ["w", "d"] else -1
            }
            message = {'type': 'player.move', "move": move}
            redis_client.rpush(self.player_channel, json.dumps(message))

    async def game_update(self, event):
        response = json.loads(event["game_state"])
        await self.send(
            text_data=json.dumps({
                "type": event["type"],
                "game_state": json.dumps(response)
            })
        )

        redis_client.ltrim(self.player_channel, -3, -1)
    
    async def update_score(self, event):
        await self.send(text_data=json.dumps(event))

    async def game_finished(self, event):
        await self.send(text_data=json.dumps(event))