import uuid

from django.db import models

class GameModel(models.Model):
    id = models.CharField(max_length=64, primary_key=True, editable=False, unique=True, blank=False)
    status = models.IntegerField(default=0)
    created_by = models.CharField(max_length=64, blank=False)
    created_at = models.DateTimeField(auto_now_add=True)
    updated_by = models.CharField(max_length=64, blank=True)
    updated_at = models.DateTimeField(auto_now=True)
    roomId = models.CharField(max_length=64, blank=False)
    isSinglePlayer = models.BooleanField(default=False)
    matchId = models.CharField(max_length=64, blank=False)
    stage = models.IntegerField(default=1)

    def save(self, *args, **kwargs):
        if not self.id:
            self.id = str(uuid.uuid4())
        super(GameModel, self).save(*args, **kwargs)

    def __str__(self):
        return f"Game {self.id} - Status: {self.status}"

    class Meta:
            db_table = 'Games'
