from django.urls import path
from .views import PlayerView, PlayersInfoView, UpdatePlayerScoreView

urlpatterns = [
    path('<str:id>/', PlayerView.as_view(), name='get-player'),
    path('game/<str:game_id>/', PlayersInfoView.as_view(), name='player-info'),
    path('<str:room_code>/<str:player_color>/score/', UpdatePlayerScoreView.as_view(), name='player-score'),
]
