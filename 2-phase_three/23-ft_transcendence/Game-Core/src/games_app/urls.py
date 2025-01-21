from django.urls import path
from .views.games_view import GameView
from .views.tournament_history_view import TournamentHistoryView

urlpatterns = [
    path('ranking/', GameView.as_view(), name='game'),
    path("tournament-history/", TournamentHistoryView.as_view(), name="tournament-history")
]
