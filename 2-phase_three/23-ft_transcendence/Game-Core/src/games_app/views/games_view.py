from django.views import View
from django.http import JsonResponse, HttpResponse
from games_app.models.game_model import GameModel
from games_app.models.score_model import ScoreModel
from games_app.models.player_model import PlayerModel
from django.core.paginator import Paginator
from django.core.paginator import Paginator, EmptyPage, PageNotAnInteger
from django.db.models import Sum, Count, Q

class GameView(View):
    def get(self, request):
        player_stats = []
        try:
            player_stats = PlayerModel.objects.values('name').annotate(
                total_points=Sum('scores__score'),
                total_wins=Count('scores__position', filter=Q(scores__position=1)),
                total_losses=Count('scores__position', filter=Q(scores__position__gt=1)),
                total_draws=Count('scores__position', filter=Q(scores__position=0))
            ).order_by('-total_wins', '-total_points')
        except Exception as e:
            return JsonResponse(data={}, status=204)

        page_number = int(request.GET.get('page', 1))
        page_size = min(int(request.GET.get('pageSize', 10)), 100)

        paginator = Paginator(player_stats, page_size)
        try:
            current_page = paginator.page(page_number)
        except PageNotAnInteger:
            current_page = paginator.page(1)
        except EmptyPage:
            current_page = paginator.page(paginator.num_pages)

        data = list(current_page.object_list)

        response = {
            'paginatedItems': {
                'Data': data,
                'totalPages': paginator.num_pages,
                'currentPage': current_page.number,
                'hasPreviousPage': current_page.has_previous(),
                'previousPage': current_page.previous_page_number() if current_page.has_previous() else None,
                'nextPage': current_page.next_page_number() if current_page.has_next() else None,
                'pageSize': paginator.per_page,
                'hasNextPage': current_page.has_next(),
            }
        }
        return JsonResponse(response, safe=False)