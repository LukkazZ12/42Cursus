from django.urls import path, include

urlpatterns = [
    path("api/v1/game-core/games/", include("games_app.urls")),
]
