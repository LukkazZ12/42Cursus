from django.urls import path
from .views import GameView, TournamentGameView

urlpatterns = [
    path('<str:room_code>/new-game/', GameView.as_view(), name='new-game'),
    path('<str:room_code>/new-tournament-game/', TournamentGameView.as_view(), name='new-game'),
]
