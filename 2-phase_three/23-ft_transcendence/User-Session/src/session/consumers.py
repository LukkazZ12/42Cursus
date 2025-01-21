import json
import logging

from channels.generic.websocket import AsyncWebsocketConsumer
from rooms.models import Room, Match
from players.models import MatchPlayer, Player
from asgiref.sync import sync_to_async
from .repository import SessionRepository
from rooms.utils import update_players_list

class RoomConsumer(AsyncWebsocketConsumer):
    async def connect(self):
        # cookies_header = dict(self.scope['headers']).get(b'cookie', b'').decode('utf-8')
        # cookies = dict(item.split("=") for item in cookies_header.split("; ") if "=" in item)
        # self.user_id = cookies.get("userId")
        self.repository = SessionRepository()
        self.user_id = self.scope['query_string'].decode("utf-8").split("userId=")[-1]
        self.room_name = self.scope['url_route']['kwargs']['room_code']
        self.room_group_name = f"room_{self.room_name}"

        if not self.user_id or not self.room_name:
            await self.close(code=400)
            return

        await self.channel_layer.group_add(
            self.room_group_name,
            self.channel_name
        )

        await sync_to_async(update_players_list)(self.room_name, "")

        match = await self.repository.get_match_by_player_id_and_status(self.user_id)
        if match is not None:
            await self.channel_layer.group_add(
                f"room_{self.room_name}_{match.id}",
                self.channel_name
            )
            logging.info(f"{RoomConsumer.__name__} | User {self.user_id} connected to queue room_{self.room_name}_{match.id}")

        await self.repository.update_player_connected_status(self.user_id, True)
        await self.accept()

    async def disconnect(self, close_code):
        await self.channel_layer.group_discard(
            self.room_group_name,
            self.channel_name
        )

        match = await self.repository.get_match_by_player_id_and_status(self.user_id)
        if match is not None:
            await self.channel_layer.group_discard(
                f"room_{self.room_name}_{match.id}",
                self.channel_name
            )

        self.repository.update_player_connected_status(self.user_id, True)

    async def player_list_update(self, event):
        user_removed = event["userRemoved"]
        await self.send(text_data=json.dumps({
            "type": "player_list_update",
            "userRemoved": user_removed,
        }))

    async def delete_room(self, event):
        await self.send(text_data=json.dumps({
            "type": "delete_room",
        }))

    async def game_started(self, event):
        logging.info(f"{RoomConsumer.__name__} Game started event: {event}")
        await self.send(text_data=json.dumps(event))

    async def sync_match(self, event):
        matches = event.get("matches", [])
        for match in matches:
            players = match.get("players", [])
            for player in players:
                if player["id"] == self.user_id:
                    await self.channel_layer.group_add(
                        f"room_{self.room_name}_{match['id']}",
                        self.channel_name,
                    )
                    await self.send(text_data=json.dumps(event))
                    return logging.info(f"{RoomConsumer.__name__} | {self.sync_match.__name__} |  | User {self.user_id} connected to queue room_{self.room_name}_{match['id']}")
        await self.send(text_data=json.dumps(event))
        return logging.error(f"{RoomConsumer.__name__} | User {self.user_id} not found in matches")

    async def tournament_ended(self, event):
        await self.send(text_data=json.dumps(event))

class PlayerScoreConsumer(AsyncWebsocketConsumer):
    async def connect(self):
        self.room_name = self.scope['url_route']['kwargs']['room_code']
        self.room_group_name = f"match_{self.room_name}"

        await self.channel_layer.group_add(
            self.room_group_name,
            self.channel_name
        )

        await self.accept()

    async def disconnect(self, close_code):
        await self.channel_layer.group_discard(
            self.room_group_name,
            self.channel_name
        )

    async def update_score(self, event):
        await self.send(text_data=json.dumps(event))