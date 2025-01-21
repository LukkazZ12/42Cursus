from django.http import JsonResponse, HttpResponse
from django.views import View
from .models import Player, MatchPlayer
from rooms.models import Room, Match
from channels.layers import get_channel_layer
from asgiref.sync import async_to_sync

class PlayerView(View):
    def get(self, request, id):
        if not id:
            return JsonResponse({'errorCode': '400', 'message': 'Bad Request'}, status=404)
       
        player = Player.objects.filter(id=id, status=True).first()
        if player is None:
            return JsonResponse({}, status=204)
        
        room = Room.objects.filter(code=player.roomCode).first()
        if room is None or player.status == False:
            return JsonResponse({}, status=204)
        
        return JsonResponse(
            {
                "roomCode": room.code,
                "roomType": room.type,
                "roomStatus": room.status,
            },
            status=200,
        )

class PlayersInfoView(View):
    def get(self, request, game_id):
        if not game_id:
            return JsonResponse({'errorCode': '400', 'message': 'Bad Request'}, status=404)
       
        match = Match.objects.filter(gameId=game_id).first()
        if match is None:
            return JsonResponse({}, status=204)
        matchPlayers = MatchPlayer.objects.filter(match=match).select_related("player").all()
        players = [matchPlayer.player for matchPlayer in matchPlayers]

        if players is None:
            return JsonResponse({}, status=204)
        players_data = [
            {
                'name': player.name,
                'profileColor': player.profileColor,
                'urlProfileImage': player.urlProfileImage,
                'score': player.score,
            }
            for player in players
        ]
        return JsonResponse(
            {
                "players": players_data,
            },
            status=200,
        )

class UpdatePlayerScoreView(View):
    def post(self, request, room_code, player_color):
        if not room_code or not player_color:
            return JsonResponse({'errorCode': '400', 'message': 'Bad Request'}, status=404)

        color = int(player_color)
        player = Player.objects.filter(roomCode=room_code, profileColor=color).first()
        if player is None:
            return JsonResponse({}, status=204)
        player.score += 1
        player.save()
        channel_layer = get_channel_layer()
        async_to_sync(channel_layer.group_send)(
            f"match_{room_code}",
            {
                "type": "update_score",
                "playerColor": player.profileColor,
                "playerScore": player.score,
            }
        )
        return HttpResponse(
            status=204,
        )