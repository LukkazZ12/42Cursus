import uuid

from django.db import models
from .game_model import GameModel

class PlayerModel(models.Model):
    id = models.CharField(max_length=64, primary_key=True, editable=False, unique=True, blank=False)
    is_connected = models.BooleanField(default=False)
    created_at = models.DateTimeField(auto_now_add=True)
    updated_at = models.DateTimeField(auto_now=True)
    gameId = models.ForeignKey(GameModel, related_name='players', on_delete=models.CASCADE)
    color = models.CharField(max_length=64, blank=False)
    score = models.IntegerField(default=0)
    win = models.IntegerField(default=0)
    name = models.CharField(max_length=100, blank=False, default="Anonymous")

    def save(self, *args, **kwargs):
        self.id = self.id or str(uuid.uuid4())
        super(PlayerModel, self).save(*args, **kwargs)

    def __str__(self):
        return f"Player {self.id} - Connected: {self.is_connected}"

    class Meta:
            db_table = 'Players'