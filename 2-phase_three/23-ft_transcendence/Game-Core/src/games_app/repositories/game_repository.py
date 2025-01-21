import logging

from asgiref.sync import sync_to_async
from games_app.models.game_model import GameModel
from games_app.models.player_model import PlayerModel
from games_app.models.score_model import ScoreModel

logger = logging.getLogger(__name__)

class GameRepository:
    async def UpdatePlayerScore(self, player_id, game_id):
        try:
            player_score = await ScoreModel.objects.aget(playerId=player_id, gameId=game_id)
        except ScoreModel.DoesNotExist:
            player_score = ScoreModel(gameId=game_id, playerId=player_id)
        except Exception as e:
            logger.error(f"{GameRepository.__name__} | {self.UpdatePlayerScore.__name__}  Error updating player score: {e}")
            return 0
        player_score.score += 1
        await player_score.asave()
        return player_score.score

    @sync_to_async
    def GetPlayerByGameId(self, game_id):
        try:
            game = GameModel.objects.get(id=game_id)
            return list(game.players.all())
        except Exception as e:
            logging.error(f"{GameRepository.__name__} | {self.GetPlayerByGameId.__name__}  Error getting players by game id: {e}")
            return []

    @staticmethod
    async def get_player_by_id_and_by_game_id(id, game_id):
        try:
            scores = await ScoreModel.objects \
                .filter(gameId_id=game_id, playerId_id=id) \
                .select_related('playerId') \
                .select_related('gameId') \
                .afirst()
            return scores.playerId
        except Exception as e:
            logging.error(f"{GameRepository.__name__} | {GameRepository.get_player_by_id_and_by_game_id.__name__}  Error getting player id and by game id: {e}")
            return None

    @staticmethod
    async def update_player_connected_status(id, is_connected):
        try:
            player = await PlayerModel.objects.filter(id=id).afirst()
            if player is None:
                return
            player.is_connected = is_connected
            await player.asave()
        except Exception as e:
            logging.error(f"{GameRepository.__name__} | {GameRepository.update_player_connected_status.__name__}  Error updating player connected status: {e}")

    @staticmethod
    async def get_players_in_game(game_id):
        try:
            scores = await sync_to_async(lambda: list(ScoreModel.objects
                .filter(gameId=game_id)
                .select_related('playerId')
                .select_related('gameId')
                .all()))()
            return scores
        except Exception as e:
            logging.error(f"{GameRepository.__name__} | {GameRepository.get_players_in_game.__name__}  Error getting players in game: {e}")
            return []
    
    # def UpdateGameStatus(self, game_id, status):
    #     game = GameModel.objects.get(id=game_id)
    #     game.status = status
    #     game.save()

    # def GetPlayersOfGame(self, game_id):
    #     game = GameModel.objects.get(id=game_id)
    #     return game.players.all()