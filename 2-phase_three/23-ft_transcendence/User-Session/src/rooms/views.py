import json
import random
import logging

from django.http import JsonResponse
from django.http import HttpResponse
from django.views import View
from django.shortcuts import get_object_or_404
from django.db.models import F, Q
from django.core.paginator import Paginator, EmptyPage, PageNotAnInteger
from asgiref.sync import async_to_sync
from channels.layers import get_channel_layer
from .utils import validate_field, validate_amount_players, validate_integer_field, validate_name_field, setPlayerColor, setBracketsPosition, createTournamentMatches, update_players_list

from .models import Room, roomTypes, RoomStatus, Match
from players.models import Player, playerColors, MatchPlayer

logger = logging.getLogger(__name__)

class RoomGetView(View):
    def get(self, request):
        try:
            current_page = int(request.GET.get('currentPage', 1))
        except ValueError:
            current_page = 1
        page_size = int(request.GET.get('pageSize', 10))
        filter_label = request.GET.get('filterLabel', '')

        rooms = Room.objects.filter(privateRoom=False, amountOfPlayers__lt=F('maxAmountOfPlayers'), status__lt=RoomStatus.READY_FOR_START.value).order_by('name')
        if filter_label:
            rooms = rooms.filter(
                Q(name__icontains=filter_label) | Q(code__icontains=filter_label)
            )

        paginator = Paginator(rooms, page_size)
        try:
            paginated_rooms = paginator.page(current_page)
        except PageNotAnInteger:
            paginated_rooms = paginator.page(1)
        except EmptyPage:
            paginated_rooms = paginator.page(paginator.num_pages)

        data = [
            {
                "roomCode": room.code,
                "amountOfPlayers": room.amountOfPlayers,
                "maxAmountOfPlayers": room.maxAmountOfPlayers,
                "roomName": room.name,
                "roomType": room.type
            }
            for room in paginated_rooms
        ]

        total_items = rooms.count()
        total_pages = (total_items + page_size - 1) // page_size

        response = {
            "paginatedItems": {
                "currentPage": paginated_rooms.number,
                "pageSize": page_size,
                "nextPage": paginated_rooms.next_page_number() if paginated_rooms.has_next() else None,
                "previousPage": paginated_rooms.previous_page_number() if paginated_rooms.has_previous() else None,
                "hasNextPage": paginated_rooms.has_next(),
                "hasPreviousPage": paginated_rooms.has_previous(),
                "totalPages": total_pages,
                "Data": data
            }
        }

        return JsonResponse(response)

class CreateRoomView(View):
    def post(self, request, *args, **kwargs):
        if not request.body or request.body.strip() == b'':
            return JsonResponse({'errorCode': '402', 'message': 'Bad Request'}, status=400)
        try:
            data = json.loads(request.body)
            if not data:
                return JsonResponse({'errorCode': '400', 'message': 'Bad Request'}, status=404)
       
        except json.JSONDecodeError:
            return JsonResponse({'errorCode': '401', 'message': 'Bad Request'}, status=400)

        try:
            created_by = validate_field(data, "createdBy", str)
            room_name = validate_name_field(data, "roomName")
            room_type = validate_integer_field(data, "roomType", default=0, required=True)
            private_room = validate_field(data, "privateRoom", bool, default=False, required=False)
            max_amount_of_players = validate_amount_players(data, "maxAmountOfPlayers", int, room_type)

            if (created_by == "" or room_name == ""):
                return JsonResponse({'errorCode': '400', 'message': 'createdBy and roomName fields are mandatory.'}, status=400)

        except (ValueError, TypeError) as e:
            return JsonResponse({'errorCode': '400', 'message': f"{e}."}, status=400)

        new_room = Room.objects.create(
            name=room_name,
            type=room_type,
            maxAmountOfPlayers=max_amount_of_players,
            privateRoom=private_room,
        )

        new_player = Player.objects.create(
            name=created_by,
            roomId=new_room,
            roomCode=new_room.code,
            profileColor=setPlayerColor(new_room.code),
            urlProfileImage=f"/assets/img/{random.choice([1, 2])}.png"
        )

        if new_room.type == roomTypes.TOURNAMENT.value:
            new_player.bracketsPosition = setBracketsPosition(new_room.code)
            if new_player.bracketsPosition % 2 == 0:
                new_player.profileColor = 1
            else:
                new_player.profileColor = 0
            new_player.save()

        new_room.createdBy = new_player.id
        new_room.amountOfPlayers += 1

        if new_room.type == roomTypes.SINGLE_PLAYER.value:
            Player.objects.create(
                name="Bot",
                roomId=new_room,
                roomCode=new_room.code,
                profileColor=1,
                urlProfileImage=f"/assets/img/{random.choice([1, 2])}.png"
            )
            new_room.maxAmountOfPlayers += 1

        new_room.save()

        return JsonResponse(
            {'roomCode': new_room.code,
             'roomType': new_room.type},
            status=201,
            headers={
                'Location': f'/session/rooms/{new_room.code}',
                'X-User-Id': new_room.createdBy,
            }
        )

class RoomView(View):
    def delete(self, request, room_code):
        userId = request.headers.get("X-User-Id")
        if not userId or not room_code:
            return JsonResponse({'errorCode': '400', 'message': 'Bad request'}, status=400)

        room = Room.objects.filter(code=room_code).first()
        if room is None:
            return JsonResponse({}, status=204)

        players = Player.objects.filter(roomCode=room_code)
        user = players.filter(id=userId).first()
        if user is None:
            return JsonResponse({'errorCode': '401', 'message': 'Unauthorized'}, status=401)
        if room.createdBy != user.id:
            return JsonResponse({'errorCode': '403', 'message': 'Forbidden'}, status=403)

        channel_layer = get_channel_layer()
        async_to_sync(channel_layer.group_send)(
            f"room_{room_code}",
            { "type": "delete_room" }
        )
        players.delete()
        room.delete()
        return JsonResponse({}, status=200)

    def get(self, request, room_code):
        try:
            userId = request.headers.get("X-User-Id")
            if not userId or not room_code:
                return JsonResponse({'errorCode': '400', 'message': 'Bad request'}, status=400)

            room = Room.objects.get(code=room_code)
            if room is None or room.type == 1:
                return JsonResponse({'errorCode': '400', 'message': 'Bad request'}, status=400)

            user = Player.objects.filter(roomCode=room.code, id=userId).first()
            if user is None:
                return JsonResponse({'errorCode': '403', 'message': 'Forbidden'}, status=403)
            players = Player.objects.filter(roomCode=room.code).order_by('profileColor')
            players_data = [
                {
                    'id': player.id if user.id == room.createdBy else None,
                    'name': player.name,
                    'profileColor': player.profileColor,
                    'urlProfileImage': player.urlProfileImage,
                    "owner": player.id == room.createdBy,
                    "you": True if user.id == player.id else False,
                }
                for player in players
            ]
            return JsonResponse(
                {
                    'roomId': room.id,
                    'roomType': room.type,
                    'roomCode': room.code,
                    'roomName': room.name,
                    'maxAmountOfPlayers': room.maxAmountOfPlayers,
                    'amountOfPlayers': len(players_data),
                    'createdBy': room.createdBy,
                    'players': players_data,
                    'isOwner': user.id == room.createdBy,
                }
            )
        except Room.DoesNotExist:
            return JsonResponse({'errorCode': '404', 'message': 'Room not found'}, status=404)

class TournamentView(View):
    def get(self, request, room_code):
        try:
            userId = request.headers.get("X-User-Id")
            if not userId or not room_code:
                return JsonResponse({'errorCode': '400', 'message': 'Bad request'}, status=400)

            room = Room.objects.get(code=room_code)
            if room is None or room.type != 1:
                return JsonResponse({'errorCode': '400', 'message': 'Bad request'}, status=400)

            user = Player.objects.filter(roomCode=room.code, id=userId).first()
            if user is None:
                return JsonResponse({'errorCode': '403', 'message': 'Forbidden'}, status=403)
            players_data = {}
            matchsCount = room.maxAmountOfPlayers // 2 ** (room.stage - 1)
            total_positions = matchsCount * 2
            num_players = room.amountOfPlayers
            if room.stage == 1:
                for i in range(1, matchsCount + 1):
                    player = Player.objects.filter(roomCode=room.code, bracketsPosition=i).first()
                    if player:
                        players_data[i] = {
                            "name": player.name,
                            "urlProfileImage": player.urlProfileImage,
                            "color": player.profileColor,
                            "you": True if user.id == player.id else False,
                        }
                    else:
                        players_data[i] = None
            elif room.stage == 0:
                players_data = {}
                matchsCount = 0
                num_players = 0
            else:
                players_info = {}
                for match in Match.objects.filter(room=room, status=1).all():
                    matchPlayers = MatchPlayer.objects.filter(match=match).select_related("player").all()

                    if matchPlayers.count() == 0:
                        return JsonResponse({'errorCode': '404', 'message': 'Match not found'}, status=404)
                    if matchPlayers.count() != 2:
                        return JsonResponse({'errorCode': '400', 'message': 'Match not filled'}, status=400)
                    players = [matchPlayer.player for matchPlayer in matchPlayers]
                    for player in players:
                        players_info[player.bracketsPosition] = {
                            "name": player.name,
                            "urlProfileImage": player.urlProfileImage,
                            "color": player.profileColor
                        }

                players_data = {
                    position: players_info.get(position, None)
                    for position in range(1, matchsCount + 1)
                }

                num_players = matchsCount

                matches = Match.objects.filter(room=room, stage=room.stage)

            owner = False
            if user.bracketsPosition % 2 != 0:
                owner = True

            return JsonResponse(
                {
                    'playersData': userId,
                    'round': room.stage,
                    'roomId': room.id,
                    'roomType': room.type,
                    'roomCode': room.code,
                    'roomName': room.name,
                    'roomStatus': room.status,
                    'maxNumberOfPlayers': matchsCount,
                    'numberOfPlayers': num_players,
                    'createdBy': room.createdBy,
                    'players': players_data,
                    'owner': owner,
                    'tournamentOwner': user.id == room.createdBy,
                    'matchsCount': matchsCount,
                    #TODO: O ERRO DOS VENCEDORES PODE ESTAR AQUI
                    'winner': True if Match.objects.filter(room=room, winner=userId).exists() else False
                }
            )
        except Room.DoesNotExist:
            return JsonResponse({'errorCode': '404', 'message': 'Room not found'}, status=404)

class RoomStatusView(View):
    def get(self, request, room_code):
        if not room_code:
            return JsonResponse({'errorCode': '400', 'message': 'Bad Request'}, status=404)
        try:
            room = Room.objects.get(code=room_code)
            return JsonResponse({'status': str(room.status)})
        except Room.DoesNotExist:
            return JsonResponse({'errorCode': '404', 'message': 'Room status not found'}, status=404)

class AddPlayerToRoomView(View):
    def put(self, request, room_code):

        if not request.body or request.body.strip() == b'' or not room_code:
            return JsonResponse({'errorCode': '400', 'message': 'Bad Request'}, status=400)
        try:
            data = json.loads(request.body)
            if not data:
                return JsonResponse({'errorCode': '400', 'message': 'Bad Request'}, status=404)
       
        except json.JSONDecodeError:
            return JsonResponse({'errorCode': '400', 'message': 'Bad Request'}, status=400)

        try:
            player_name = validate_name_field(data, "playerName")
        except (ValueError, TypeError) as e:
            return JsonResponse({'errorCode': '400', 'message': f'{e}'}, status=400)

        try:
            room = Room.objects.filter(code=room_code).first()
            if room is None:
                return JsonResponse({'errorCode': '403', 'message': 'Room dont exist.'}, status=403)

            if room.players.count() >= room.maxAmountOfPlayers:
                return JsonResponse({'errorCode': '403', 'message': 'Room is full'}, status=403)

            player = Player.objects.create(
                name=player_name,
                roomCode=room_code,
                roomId=room,
                profileColor=setPlayerColor(room.code),
                urlProfileImage=f"/assets/img/{random.choice([1, 2])}.png"
            )

            if room.type == roomTypes.TOURNAMENT.value:
                player.bracketsPosition = setBracketsPosition(room.code)
                if player.bracketsPosition % 2 == 0:
                    player.profileColor = 1
                else:
                    player.profileColor = 0
                player.save()

            room.amountOfPlayers += 1
            room.save()
            update_players_list(room_code, "")

            if room.stage == 1 and room.type == roomTypes.TOURNAMENT.value and room.amountOfPlayers == room.maxAmountOfPlayers:
                createTournamentMatches(room)

            return JsonResponse(
                {
                    'roomCode': room.code,
                    'roomType': room.type
                },
                status=201,
                headers={
                    'Location': f'/session/rooms/{room_code}',
                    'X-User-Id': player.id
                }
            )
        except Room.DoesNotExist:
            return JsonResponse({'errorCode': '404', 'message': 'Room not found'}, status=404)

class RemovePlayerView(View):
    def delete(self, request, room_code, player_id):
        if not room_code or not player_id:
            return JsonResponse({'errorCode': '400', 'message': 'Bad Request'}, status=404)
       
        try:
            room = Room.objects.get(code=room_code)
        except Room.DoesNotExist:
            return JsonResponse({'errorCode': '404', 'message': 'Room not found'}, status=404)

        if room.type is roomTypes.SINGLE_PLAYER:
            return JsonResponse({'errorCode': '400', 'message': 'Bad request'}, status=400)

        try:
            player = Player.objects.get(id=player_id, roomCode=room_code)
        except Player.DoesNotExist:
            return JsonResponse({"errorCode": "404", "message": "Player not found in the room"}, status=404)

        update_players_list(room_code, player.id)

        player.delete()
        room.amountOfPlayers -= 1
        room.save()

        return HttpResponse(
            status=204,
            headers={
                'Location': f'/session/rooms/{room_code}/{player_id}',
                'playerId': player_id
            }
        )

class LockTournamentView(View):
    def post(self, request, room_code):
        try:
            userId = request.headers.get("X-User-Id")
            if not userId or not room_code:
                return JsonResponse({'errorCode': '400', 'message': 'badRequest'}, status=400)
            
            room = Room.objects.get(code=room_code)
            user = Player.objects.filter(roomCode=room.code, id=userId).first()
            if user is None:
                return JsonResponse({'errorCode': '403', 'message': 'Forbidden'}, status=403)

            if user.id != room.createdBy:
                return JsonResponse({'errorCode': '403', 'message': 'Forbidden'}, status=403)

            if room.type != roomTypes.TOURNAMENT.value:
                return JsonResponse({'errorCode': '400', 'message': 'Bad request'}, status=400)

            if room.amountOfPlayers != room.maxAmountOfPlayers:
                return JsonResponse({'errorCode': '400', 'message': 'Bad request'}, status=400)

            room.status = RoomStatus.READY_FOR_START.value
            room.save()

            matches = Match.objects.filter(room=room)

            channel_layer = get_channel_layer()
            async_to_sync(channel_layer.group_send)(
                f"room_{room.code}",
                {
                    "type": "sync.match",
                    "matches": [
                        {
                            "id": match.id,
                            "players": [
                                {"id": match_player.player.id}
                                for match_player in MatchPlayer.objects.filter(match=match).select_related('player')
                            ]
                        }
                        for match in matches
                    ]
                }
            )

            update_players_list(room_code, "")

            return JsonResponse({}, status=201)
        except Room.DoesNotExist:
            return JsonResponse({'errorCode': '404', 'message': 'Room not found'}, status=404)