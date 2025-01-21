import redis
import json
import logging

from django.http import HttpResponse
from django.views import View
from channels.layers import get_channel_layer
from asgiref.sync import async_to_sync

from rooms.models import Room, Match
from rooms.models import RoomStatus, roomTypes
from players.models import Player, MatchPlayer

logger = logging.getLogger(__name__)

redis_client = redis.Redis(host='redis', port=6379, db=0, decode_responses=True)

class GameView(View):
    def post(self, request, room_code):
        user_id = request.headers.get('X-User-Id')
        if user_id is None or not room_code or not user_id:
            return HttpResponse(f"User ID not found", status=400)

        room = Room.objects.filter(code=room_code).first()
        if room is None:
            return HttpResponse(f"Room {room_code} not found", status=400)
        if room.players.count() < 2:
            return HttpResponse(f"Minimal amount of players {2}", status=403)
        if room.createdBy != user_id:
            return HttpResponse(f"User {user_id} is not the owner of room {room_code}", status=403)
        if room.type == roomTypes.TOURNAMENT.value:
            return HttpResponse(f"Room {room_code} is not a match game room", status=403)
        if room.amountOfPlayers != room.maxAmountOfPlayers and room.type != roomTypes.SINGLE_PLAYER.value:
            return HttpResponse(f"Room {room_code} is not full", status=403)

        room.status = RoomStatus.CREATING_GAME
        room.save()

        isSinglePlayer = False
        if (room.amountOfPlayers == 1):
            isSinglePlayer = True

        match = Match.objects.create(
            room=room,
            status=0
        )
        match.save()
        for player in room.players.all():
            MatchPlayer.objects.create(
                match=match,
                player=player,
                position=0
            )

        channel_layer = get_channel_layer()
        async_to_sync(channel_layer.group_send)(
            f"room_{room_code}",
            {
                "type": "sync.match",
                "matches": [
                    {
                        "id": match.id,
                        "players": [
                            {"id": player.id}
                            for player in room.players.all()
                        ]
                    }
                ]
            }
        )

        message = {
            "type": "create_game",
            "roomId": room.id,
            "roomType": room.type,
            "matchId": match.id,
            "isSinglePlayer": isSinglePlayer,
            "stage": room.stage,
            "ownerId": user_id,
            "players": [
                {
                    "id": player.id,
                    "name": player.name,
                    "color": player.profileColor,
                }
                for player in room.players.all()
            ]
        }

        logger.info(f"{GameView.__name__} | ENVIANDO MSG {json.dumps(message)}")
        redis_client.rpush("create-game-queue", json.dumps(message))
        return HttpResponse(f"Game created for room {room_code}", status=201)

class TournamentGameView(View):
    def post(self, request, room_code):
        user_id = request.headers.get('X-User-Id')
        if user_id is None or not room_code or not user_id:
            return HttpResponse(f"User ID not found", status=400)

        room = Room.objects.filter(code=room_code).first()
        if room is None:
            return HttpResponse(f"Room {room_code} not found", status=400)
        if room.players.count() < 4:
            return HttpResponse(f"Minimal amount of players {4}", status=401)
        if room.type != roomTypes.TOURNAMENT.value:
            return HttpResponse(f"Room {room_code} is not a tournament game room", status=403)
        if room.amountOfPlayers != room.maxAmountOfPlayers:
            return HttpResponse(f"Room {room_code} is not full", status=403)

        room.status = RoomStatus.CREATING_GAME
        room.save()

        try:
            player_one = Player.objects.filter(id=user_id).first()
            if player_one is None:
                return HttpResponse(f"Player {user_id} not found", status=400)
            matchPlayer = MatchPlayer.objects.filter(player=player_one, match__stage=room.stage).first()
            if (matchPlayer is None):
                return HttpResponse(f"you lost!", status=401)
            match = matchPlayer.match
            secondMatchPlayer = MatchPlayer.objects.filter(match=match).exclude(player=player_one).first()
            player_two = secondMatchPlayer.player

            message = {
                "type": "create_game",
                "roomId": room.id,
                "roomType": room.type,
                "matchId": match.id,
                "isSinglePlayer": False,
                "stage": room.stage,
                "ownerId": user_id,
                "players": [
                    {
                        "id": player_one.id,
                        "name": player_one.name,
                        "color": player_one.profileColor,
                    },
                    {
                        "id": player_two.id,
                        "name": player_two.name,
                        "color": player_two.profileColor,
                    }
                ]
            }
            logger.info(f"{TournamentGameView.__name__} | ENVIANDO MSG {json.dumps(message)}")
            redis_client.rpush("create-game-queue", json.dumps(message))
            return HttpResponse(f"Game created for room {room_code}", status=201)
        except Exception as e:
            logger.error(f"Error creating game for room {room_code}: {str(e)}")
            return HttpResponse(f"Error creating game for room {room_code}", status=500)
