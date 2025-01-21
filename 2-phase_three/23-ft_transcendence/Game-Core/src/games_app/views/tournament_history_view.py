import logging
from django.views import View
from django.http import JsonResponse
from django.core.paginator import Paginator, EmptyPage, PageNotAnInteger
from django.db.models import Q
from django.db.models import Prefetch
from games_app.models.game_model import GameModel
from games_app.models.player_model import PlayerModel
from games_app.models.score_model import ScoreModel
from games_worker.utils.game_config import playerColor


logger = logging.getLogger(__name__)

class TournamentHistoryView(View):
    def createHistoryTable(self, roomCode, player_name=None):
        history = []
        games = GameModel.objects.filter(roomId__startswith=roomCode)
        if player_name:
            games = games.filter(scores__playerId__name=player_name).distinct()

        games = games.prefetch_related(
            Prefetch('scores', queryset=ScoreModel.objects.select_related('playerId').all())
        )

        for game in games:
            scores = game.scores.all()
            if scores.count() == 2:
                red_score = scores.first()
                blue_score = scores.last()
                red_player = red_score.playerId
                blue_player = blue_score.playerId
                red_score_value = red_score.score if red_score else 0
                blue_score_value = blue_score.score if blue_score else 0

                winner = playerColor.RED if red_score_value > blue_score_value else playerColor.BLUE
                history.append({
                    "stage": game.stage,
                    "winner": winner,
                    playerColor.RED: {
                        "name": red_player.name,
                        "score": red_score_value,
                        "color": red_player.color,
                        # "profileImage": red_player.profileImage
                    },
                    playerColor.BLUE: {
                        "name": blue_player.name,
                        "score": blue_score_value,
                        "color": blue_player.color,
                        # "profileImage": blue_player.profileImage
                    }
                })
        return history



    def get(self, request):
        roomCode = request.GET.get('roomCode', None)
        if not roomCode:
            return JsonResponse({"error": "O parâmetro 'roomCode' é obrigatório."}, status=400)

        player_name = request.GET.get('player_name', None)
        page_number = request.GET.get('page', 1)
        page_size = request.GET.get('pageSize', 10)
        tournament_history = self.createHistoryTable(roomCode, player_name)

        if not tournament_history:
            tournament_history = []

        paginator = Paginator(tournament_history, page_size)
        try:
            current_page = paginator.page(page_number)
        except PageNotAnInteger:
            current_page = paginator.page(1)
        except EmptyPage:
            current_page = paginator.page(paginator.num_pages)

        response = {
            'currentPage': current_page.number,
            'pageSize': paginator.per_page,
            'nextPage': current_page.next_page_number() if current_page.has_next() else None,
            'previousPage': current_page.previous_page_number() if current_page.has_previous() else None,
            'hasNextPage': current_page.has_next(),
            'hasPreviousPage': current_page.has_previous(),
            'games': tournament_history
        }

        return JsonResponse(response)
