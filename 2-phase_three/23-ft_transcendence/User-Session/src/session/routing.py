from django.urls import path
from .consumers import RoomConsumer, PlayerScoreConsumer

websocket_urlpatterns = [
    path('api/v1/user-session/ws/rooms/<str:room_code>/', RoomConsumer.as_asgi()),
    path('api/v1/user-session/ws/match/<str:room_code>/', PlayerScoreConsumer.as_asgi()),
]