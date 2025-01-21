from django.urls import path
from games_app.consumers.GameSessionConsumer import GameSessionConsumer

websocket_urlpatterns = [
    path('api/v1/game-core/games/<str:game_id>/', GameSessionConsumer.as_asgi()),
]