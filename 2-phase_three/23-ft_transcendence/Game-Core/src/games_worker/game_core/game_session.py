import json
import redis
import random
import asyncio
import os
import logging
import math

from channels.layers import get_channel_layer
from asgiref.sync import sync_to_async
from django.utils import timezone
from django.db.models import F

# Game Settings imports
from games_worker.utils.game_config import GameConfig, GameStatus
from games_worker.utils.ball import Ball
from games_worker.utils.player import Player
from games_app.models.game_model import GameModel
from games_app.models.player_model import PlayerModel
from games_app.models.score_model import ScoreModel
from django.db.models import Case, When, Value
from games_app.repositories.game_repository import GameRepository

logger = logging.getLogger(__name__)


redis_client = redis.Redis(host=os.environ.get("REDIS_HOST", "localhost"), port=int(os.environ.get("REDIS_PORT", 6379)), db=0, decode_responses=True)

class GameSession:
	def __init__(self, players, gameId, roomId, roomType):
		self.sync_session_queue = "game-sync-session-queue"
		self.game_status = GameStatus.WAITING
		self.roomId = roomId
		self.roomType = roomType
		self.channel_layer = get_channel_layer()
		self.tasks_movement_player = []
		self.gameId = gameId
		self.game = f"game_session_{gameId}"
		self.numberOfPlayers = len(players)
		self.last_player_hit = None
		self.game_repository = GameRepository()

		self.players = {}
		orientations = ["left", "right", "top", "bottom"]
		for index, player in enumerate(players):
			if self.numberOfPlayers == 4:
				position = GameConfig.multiplayer_positions[index]
			else:
				position = GameConfig.player_positions[index]
			orientation = orientations[index]
			self.players[player["id"]] = Player(player["id"], player["color"], position["x"], position["y"], orientation)
			if self.numberOfPlayers == 4 and index >= 2:
				self.players[player["id"]].width = GameConfig.multiplayer_width
				self.players[player["id"]].height = GameConfig.multiplayer_height

		self.ball = Ball()
		if self.numberOfPlayers == 4:
			self.ball.x = GameConfig.screen_height / 2
		self.ball_direction = {
			"x": GameConfig.ball_speed_x,
			"y": GameConfig.ball_speed_y
		}

	async def add_player_channels(self):
		for player in self.players.values():
			task = self.tasks_movement_player.append(asyncio.create_task(self.process_player_move(player)))
			self.tasks_movement_player.append(task)

	async def move_bot(self):
		players = (list)(self.players.values())
		player = next(filter(lambda player: player.orientation == "right", players), None)
		direction = 0
		while(True):
			if self.game_status == GameStatus.PLAYING:
				future_y = self.ball.y + (self.ball_direction["y"] / self.ball_direction["x"]) * (player.x - self.ball.x)
				future_y += random.uniform(-5, 5)
				if future_y > player.y:
					direction = 1
				elif future_y < player.y:
					direction = -1
			else:
				direction = 0

			start_time = asyncio.get_event_loop().time()
			while asyncio.get_event_loop().time() - start_time < 1:
				player.y += direction * GameConfig.player_speed
				if player.y < -(GameConfig.field_height / 2 - GameConfig.player_height / 2):
					player.y = -(GameConfig.field_height / 2 - GameConfig.player_height / 2)
				elif player.y > GameConfig.field_height / 2 - GameConfig.player_height / 2:
					player.y = GameConfig.field_height / 2 - GameConfig.player_height / 2
				await asyncio.sleep(0.15)

	async def move_ball(self):
		self.ball.x += self.ball_direction["x"]
		self.ball.y += self.ball_direction["y"]

	async def check_screen_collision(self, y):
		if y <= -(GameConfig.field_height / 2 - GameConfig.ball_size) or y >= GameConfig.field_height / 2 - GameConfig.ball_size:
			self.ball_direction["y"] *= -1

	async def check_player_collision(self, x, y):
		for player in self.players.values():
			if player.orientation in ["left", "right"]:
				if (
					abs(self.ball.x - player.x) <= GameConfig.player_width / 2 + GameConfig.ball_size
					and (abs(self.ball.y - player.y) <= GameConfig.player_height / 2
					or math.sqrt((player.x - self.ball.x)**2 + (player.y - self.ball.y)**2) <= GameConfig.max_distance_ball_player)
				):
					self.ball_direction["x"] *= -1
					self.last_player_hit = player
					field_width = GameConfig.field_width
					if self.numberOfPlayers == 4:
						field_width = GameConfig.multiplayer_field_width
					if abs(self.ball.y - player.y) <= GameConfig.player_height / 2:
						self.ball.x = self.ball.x / abs(self.ball.x) * (field_width / 2 - GameConfig.player_width - GameConfig.ball_size)
					elif math.sqrt((player.x - self.ball.x)**2 + (player.y - self.ball.y)**2) <= GameConfig.max_distance_ball_player:
						if (self.ball.y > player.y and self.ball_direction["y"] < 0
							or self.ball.y < player.y and self.ball_direction["y"] > 0
						):
							self.ball_direction["y"] *= -1
						self.ball.x += self.ball_direction["x"]
						self.ball.y += self.ball_direction["y"]
			elif player.orientation in ["top", "bottom"]:
				if (
					abs(self.ball.y - player.y) <= GameConfig.multiplayer_height / 2 + GameConfig.ball_size
					and (abs(self.ball.x - player.x) <= GameConfig.multiplayer_width / 2
					or math.sqrt((player.x - self.ball.x)**2 + (player.y - self.ball.y)**2) <= GameConfig.max_distance_ball_player)
				):
					self.ball_direction["y"] *= -1
					self.last_player_hit = player
					if abs(self.ball.x - player.x) <= GameConfig.multiplayer_width / 2:
						self.ball.y = self.ball.y / abs(self.ball.y) * (GameConfig.multiplayer_field_width / 2 - GameConfig.multiplayer_height - GameConfig.ball_size)
					elif math.sqrt((player.x - self.ball.x)**2 + (player.y - self.ball.y)**2) <= GameConfig.max_distance_ball_player:
						if (self.ball.x > player.x and self.ball_direction["x"] < 0
							or self.ball.x < player.x and self.ball_direction["x"] > 0
						):
							self.ball_direction["x"] *= -1
						self.ball.x += self.ball_direction["x"]
						self.ball.y += self.ball_direction["y"]

	async def ball_reset(self):
		self.ball.x = 0
		self.ball.y = 0
		self.ball_direction = {
			"x": random.choice([-1, 1]) * random.uniform(GameConfig.speed_range_min, GameConfig.speed_range_max),
			"y": random.choice([-1, 1]) * random.uniform(GameConfig.speed_range_min, GameConfig.speed_range_max),
		}
		self.last_player_hit = None
		asyncio.create_task(self.await_for_new_match())

	async def await_for_new_match(self):
		self.game_status = GameStatus.WAITING
		await asyncio.sleep(3)
		self.game_status = GameStatus.PLAYING

	async def update_ball_position(self):
		if self.game_status == GameStatus.PLAYING:
			ball_x = self.ball.x + self.ball_direction["x"]
			ball_y = self.ball.y + self.ball_direction["y"]

			if self.numberOfPlayers == 2:
				await self.check_screen_collision(ball_y)
			await self.check_player_collision(ball_x, ball_y)
			if (await self.check_game_conditions() == True):
				return True

			await self.move_ball()
		return False

	async def check_game_conditions(self):
		field_width = GameConfig.field_width
		if self.numberOfPlayers == 4:
			field_width = GameConfig.multiplayer_field_width
		if (
				self.ball.x <= -(field_width / 2 - GameConfig.ball_size)
				or self.ball.x >= field_width / 2 - GameConfig.ball_size
				or (self.numberOfPlayers == 4 and (self.ball.y <= -(field_width / 2 - GameConfig.ball_size)
				or self.ball.y >= field_width / 2 - GameConfig.ball_size))
			):
			player = self.last_player_hit
			players = (list)(self.players.values())
			if player is None:
				if self.ball.x <= -(field_width / 2 - GameConfig.ball_size):
					color = 0
				elif self.ball.x >= field_width / 2 - GameConfig.ball_size:
					color = 1
				elif self.ball.y >= GameConfig.field_height / 2 - GameConfig.ball_size:
					color = 2
				elif self.ball.y <= -(GameConfig.field_height / 2 - GameConfig.ball_size):
					color = 3
				player = next(filter(lambda player: player.color == color, players), None)
				for scoredPlayer in players:
					if scoredPlayer != player:
						await self.update_score(scoredPlayer)
			else:
				await self.update_score(player)
			if any(player.score >= GameConfig.max_score for player in players):
				return True
			await self.ball_reset()
			if await self.check_players_connected() == True:
				return True

		return False

	async def check_players_connected(self):
		time = 0
		while True:
			scores = await GameRepository.get_players_in_game(self.gameId)
			players = [score.playerId for score in scores]
			game = await sync_to_async(GameModel.objects.filter(id=self.gameId).first)()
			are_players_connected = any(player.is_connected for player in players)
			if game.isSinglePlayer is True:
				for player in players:
					if player.is_connected == True:
						are_players_connected = True
						break
			if are_players_connected or time >= 180:
				break
			await asyncio.sleep(1)
			time += 1
		if time >= 180:
			return True
		return False

	async def update_score(self, player):
		player.score = await self.game_repository.UpdatePlayerScore(player.user_id, self.gameId)
		try:
			await self.channel_layer.group_send(
				self.game,
				{
					"type": "update_score",
					"playerColor": player.color,
					"playerScore": player.score,
					"expiry": 0.02
				})
		except Exception as e:
			return logger.error(f"Error on update score | {GameSession.__name__} | {self.update_score.__name__} | with error: {e}.")

	async def notify_clients(self):
		response_data = {
			"ball": self.ball.to_dict(),
			"players": {player.color: player.to_dict() for player in self.players.values()},
			"numberOfPlayers": len(self.players),
			"fieldAttributes": {"height": GameConfig.field_height, "width": GameConfig.field_width},
			"gameStatus": self.game_status,
			"lastPlayerHit": self.last_player_hit.to_dict() if self.last_player_hit is not None else None,
		}
		json_response = json.dumps(response_data)
		try:
			await self.channel_layer.group_send(
				self.game,
				{
				"type": "game.update",
				"game_state": json_response,
				"expiry": 0.02
				})
		except:
			return logging.error(f"Error on notify clients | {GameSession.__name__} | {self.notify_clients.__name__}.")

	async def process_player_move(self, player):
		queue_name = f"{self.game}_{player.user_id}"
		while True:
			await asyncio.sleep(0.005)

			try:
				message = redis_client.lpop(queue_name)
				if message is None:
					continue
				data = json.loads(message)

				move = data.get("move", {})
				if player.orientation == "left" or player.orientation == "right":
					player.y += move["direction"] * GameConfig.player_speed
				else:
					player.x += move["direction"] * GameConfig.player_speed
				if player.orientation in ["left", "right"]:
					if player.y < -(GameConfig.field_height / 2 - GameConfig.player_height / 2):
						player.y = -(GameConfig.field_height / 2 - GameConfig.player_height / 2)
					elif player.y > GameConfig.field_height / 2 - GameConfig.player_height / 2:
						player.y = GameConfig.field_height / 2 - GameConfig.player_height / 2
				elif player.orientation in ["top", "bottom"]:
					if player.x < -(GameConfig.field_height / 2 - GameConfig.multiplayer_width / 2):
						player.x = -(GameConfig.field_height / 2 - GameConfig.multiplayer_width / 2)
					elif player.x > GameConfig.field_height / 2 - GameConfig.multiplayer_width / 2:
						player.x = GameConfig.field_height / 2 - GameConfig.multiplayer_width / 2

			except json.JSONDecodeError as e:
				print(f"Erro ao decodificar JSON: {e}")
			except Exception as e:
				print(f"Erro ao processar mensagem: {e}")

	async def finish_game(self):
		try:
			await GameModel.objects.filter(id=self.gameId).aupdate(status=1)

			game_session = await GameModel.objects.filter(id=self.gameId).afirst()

			player_scores = await sync_to_async(list)(
				ScoreModel.objects.filter(gameId=self.gameId).annotate(
					player_id=F('playerId__id'),
					player_name=F('playerId__name')
				)
			)

			ranked_players = sorted(player_scores, key=lambda ps: (-ps.score, ps.player_id))

			players_ranking = [
				{"rank": rank + 1, "id": ps.player_id, "score": ps.score}
				for rank, ps in enumerate(ranked_players)
			]

			max_score = max(ps.score for ps in ranked_players) if ranked_players else 0
			top_players = [ps for ps in ranked_players if ps.score == max_score]
			winner_id = top_players[0].player_id if len(top_players) == 1 else None

			redis_client.rpush(
                self.sync_session_queue,
                json.dumps({
                    "type": "game-over",
                    "matchId": game_session.matchId,
                    "gameId": game_session.id,
					"winner":  winner_id,
					"players": players_ranking
                })
            )
			await self.channel_layer.group_send(
				self.game,
				{
					"type": "game_finished",
					"roomType": self.roomType,
					"winner": winner_id,
					"expiry": 0.02
				})
		except Exception as e:
			return logger.error(f"Error on Finished | {GameSession.__name__} | {self.finish_game.__name__} | with error: {e}.")

	async def game_loop(self):
		print("Game loop started")
		asyncio.create_task(self.await_for_new_match())
		game = await sync_to_async(GameModel.objects.filter(id=self.gameId).first)()
		if game.isSinglePlayer is True:
			asyncio.create_task(self.move_bot())

		while True:
			if await self.update_ball_position() == True:
				break
			await self.notify_clients()
			await asyncio.sleep(0.02)

	async def send_message_game_start(self):
		try:
			game_session = await sync_to_async(GameModel.objects.filter(id=self.gameId).first)()
			redis_client.rpush(
					self.sync_session_queue,
					json.dumps({
						"type": "game-started",
						"matchId": game_session.matchId,
						"gameId": game_session.id
					})
				)
			
			queue_name = f"room_{self.roomId[:8]}_{game_session.matchId}"
			logging.info(f"\033[93mSending message game start {queue_name}\033[0m")
			await self.channel_layer.group_send(
				queue_name,
				{
					"type": "game.started",
					"gameId": self.gameId,
					"expiry": 0.02
				})
		except Exception as e:
			logger.error(f"\033[91mError to send game started message. {e}\033[0m")
			return True


		i = 60
		while True:
			scores = await GameRepository.get_players_in_game(self.gameId)
			if i == 0:
				logging.error(f"Error | {GameSession.__name__} | {self.send_message_game_start.__name__} | Timeout to start game.")
				return True
			i -= 1
			all_players_connected = 0
			players = [score.playerId for score in scores]
			for player in players:
				logging.info(f"Test {player} | {player.is_connected}")
				if player.is_connected == True:
					all_players_connected += 1
			if all_players_connected == self.numberOfPlayers:
				logging.info(f"Players connected | {all_players_connected}")
				break
			game = scores[0].gameId
			if game.isSinglePlayer == True and all_players_connected == 1:
				logging.info(f"Players connected | {all_players_connected}")
				break
			await asyncio.sleep(2)
			logging.info(f"Players connected | {scores[0]} | {scores[1]}")
		return False

	async def startGame(self):
		logger.info(f"{self.startGame.__name__} Jogo iniciado | Room {self.roomId} | Game {self.gameId}.")
		await self.add_player_channels()
		if (await self.send_message_game_start()):
			return logging.error(f"Error | {self.startGame.__name__} | {self.startGame.__name__} | Timeout to start game.")
		await self.game_loop()
		await self.finish_game()
		logger.info(f"{self.startGame.__name__} | Finished | Room: {self.roomId} | Game: {self.gameId}.")