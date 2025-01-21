import logging

from rooms.models import Room, Match
from players.models import MatchPlayer, Player

class SessionRepository():

    @staticmethod
    async def update_player_connected_status(player_id, is_connected):
        player = await Player.objects.filter(id=player_id).afirst()
        if player is None:
            return
        player.isConnected = is_connected
        await player.asave()


    @staticmethod
    async def get_match_by_player_id_and_status(player_id, status=1):
        try:
            match_player = await MatchPlayer.objects \
                .filter(player_id=player_id, match__status=status).select_related('match').afirst()
            if match_player is None:
                logging.warning(f"No Match open found for player id={player_id}.")
                return None
            return match_player.match
        except Exception as e:
            logging.error(f"Error fetching match for player_id={player_id} and status={status}: {e}")
            raise

    @staticmethod
    async def get_room(room_code):
        return await Room.objects.filter(code=room_code).afirst()

    @staticmethod
    async def get_match(match_id):
        return await Match.objects.filter(id=match_id).afirst()

    @staticmethod
    async def get_player(player_id):
        return await Player.objects.filter(id=player_id).afirst()

    @staticmethod
    async def get_match_player(match_id, player_id):
        return await MatchPlayer.objects.filter(match_id=match_id, player_id=player_id).afirst()

    @staticmethod
    async def get_players_in_match(match_id):
        return await MatchPlayer.objects.filter(match_id=match_id).aprefetch_related('player')

    @staticmethod
    async def get_players_in_room(room_id):
        return await Player.objects.filter(room_id=room_id).aprefetch_related('matches_played')

    @staticmethod
    async def get_matches_in_room(room_id):
        return await Match.objects.filter(room_id=room_id).aprefetch_related('players_in_match')

    @staticmethod
    async def create_player(name, room_id, room_code, profile_color, url_profile_image, created_by):
        player = Player(name=name, room_id=room_id, room_code=room_code, profile_color=profile_color, url_profile_image=url_profile_image, createdBy=created_by)
        await player.asave()
        return player

    @staticmethod
    async def create_match(room_id, created_by):
        match = Match(room_id=room_id, createdBy=created_by)
        await match.asave()
        return match

    @staticmethod
    async def create_match_player(match_id, player_id, position):
        match_player = MatchPlayer(match_id=match_id, player_id=player_id, position=position)
        await match_player.asave()
        return match_player

    @staticmethod
    async def update_player(player):
        await player.asave()

    @staticmethod
    async def update_match(match):
        await match.asave()

    @staticmethod
    async def update_match_player(match_player):
        await match_player.asave()

    @staticmethod
    async def delete_player(player):
        await player.adelete()

    @staticmethod
    async def delete_match(match):
        await match.adelete()

    @staticmethod
    async def delete_match_player(match_player):
        await match_player.adelete()