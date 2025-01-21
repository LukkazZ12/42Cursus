import uuid

from django.db import models
from .game_model import  GameModel
from .player_model import PlayerModel

class ScoreModel(models.Model):
    gameId = models.ForeignKey(GameModel, related_name="scores", on_delete=models.CASCADE)
    playerId = models.ForeignKey(PlayerModel, related_name="scores", on_delete=models.CASCADE)
    score = models.IntegerField(default=0)
    position = models.IntegerField(default=0)
    created_at = models.DateTimeField(auto_now_add=True)
    updated_at = models.DateTimeField(auto_now=True)

    def __str__(self):
        return f"Score {self.id} | Game: {self.gameId} | Player: {self.playerId} | Score: {self.score}"

    class Meta:
        db_table = 'Scores'
        unique_together = ('gameId', 'playerId')
        indexes = [
            models.Index(fields=['gameId', 'playerId'])  # Índice único para melhorar consultas
        ]