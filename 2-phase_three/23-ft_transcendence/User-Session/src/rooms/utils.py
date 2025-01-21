import random
import math

from channels.layers import get_channel_layer
from asgiref.sync import async_to_sync

from .models import roomTypes, Room, Match
from players.models import Player, playerColors, MatchPlayer

def get_room_type_range(room_type):
    if not room_type:
        raise ValueError(f"invalid param")
    if room_type == roomTypes.MATCH:
        return [2, 4]
    if room_type == roomTypes.TOURNAMENT:
        return [4]
    if room_type == roomTypes.SINGLE_PLAYER:
        return [1]
    raise ValueError(f"Invalid room type: {room_type}")

def validate_field(data, field, field_type, default=None, required=True):
    value = data.get(field, default)
    if required and (not value or value is None):
        raise ValueError(f"'{field}' field is mandatory.")
    if not isinstance(value, field_type):
        raise ValueError(f"'{field}' type value is {field_type.__name__}.")
    return value

def validate_name_field(data, field, required=True):
    value = data.get(field, "Senhor Bolinha")
    if required and (not value or value is None):
        raise ValueError(f"'{field}' field is mandatory.")
    if not isinstance(value, str):
        raise ValueError(f"'{field}' type value is {str.__name__}.")
    if len(value) < 3 or len(value) > 100:
        raise ValueError(f"'{field}' value must have between 3 and 100 characters.")
    return value

def validate_integer_field(data, field, default=None, required=True):
    value = data.get(field, default)
    if required and (not value or value is None):
        raise ValueError(f"'{field}' field is mandatory.")
    if isinstance(value, str):
        try:
            value = int(value)
        except ValueError:
            raise ValueError(f"'{field}' value must be an integer or a string representing an integer.")
    if not isinstance(value, int):
        raise ValueError(f"'{field}' type value is {int.__name__}.")
    return value


def validate_amount_players(data, field, field_type, room_type):
    value = data.get(field)
    if (not value or value is None):
        raise ValueError(f"'{field}' field is mandatory.")
    if isinstance(value, str):
        try:
            value = int(value)
        except ValueError:
            raise ValueError(f"'{field}' value must be an integer or a string representing an integer.")
    if not isinstance(value, field_type):
        raise ValueError(f"'{field}' type value is {field_type.__name__}.")
    range = get_room_type_range(roomTypes(room_type))
    if value not in range:
        raise ValueError(f"'{field}' is not a valid size of players.")
    return value

def setPlayerColor(room_code):
    room = Room.objects.filter(code=room_code).first()
    profileColor = 0
    used_colors = Player.objects.filter(roomCode=room_code).values_list('profileColor', flat=True)
    all_colors = {color.value for color in playerColors}
    available_colors = all_colors - set(used_colors)
    if available_colors:
        profileColor = available_colors.pop()
    return profileColor

def setBracketsPosition(room_code):
    room = Room.objects.filter(code=room_code).first()
    used_positions = room.players.values_list('bracketsPosition', flat=True)
    used_positions_list = list(used_positions)

    avaliable_positions_list = list(filter(lambda x: x not in used_positions_list, list(range(1,room.maxAmountOfPlayers + 1))))
    return random.choice(avaliable_positions_list)


def setFirstRound(room, first_round_matches):
    players = Player.objects.filter(roomId=room).order_by('bracketsPosition')
    for match, player_pair in zip(first_round_matches, zip(players[::2], players[1::2])):
        player_one, player_two = player_pair
        # Correctly assign 'match' and 'player' foreign keys
        MatchPlayer.objects.create(match=match, player=player_one, position=1)
        MatchPlayer.objects.create(match=match, player=player_two)
        match.status = 1
        match.save()

def createTournamentMatches(room):
    number_of_rounds = math.ceil(math.log2(room.maxAmountOfPlayers))
    matches = {}

    # Create all matches for each round
    for round_number in range(1, number_of_rounds + 1):
        matches_in_round = []
        num_matches = 2 ** (number_of_rounds - round_number)
        for match_position in range(1, num_matches + 1):
            match = Match.objects.create(
                room=room,
                stage=round_number,
                status=0,
                position=match_position
            )
            matches_in_round.append(match)
        matches[round_number] = matches_in_round

    # Link matches to next matches
    for round_number in range(1, number_of_rounds):
        current_round = matches[round_number]
        next_round = matches[round_number + 1]
        for i in range(0, len(current_round), 2):
            next_match = next_round[i // 2]
            current_round[i].nextMatch = next_match.id
            current_round[i].save()
            current_round[i + 1].nextMatch = next_match.id
            current_round[i + 1].save()

    # Assign players to first round matches
    setFirstRound(room, matches[1])

def update_players_list(room_code, userRemoved):
    channel_layer = get_channel_layer()
    async_to_sync(channel_layer.group_send)(
        f"room_{room_code}",
        {
            "type": "player_list_update",
            "userRemoved": userRemoved,
        }
    )