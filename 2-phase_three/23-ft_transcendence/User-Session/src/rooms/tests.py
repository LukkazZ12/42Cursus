from django.test import TestCase
from .models import Room, Match
from players.models import Player, MatchPlayer
from .utils import createTournamentMatches
import math

class TournamentMatchesTestCase(TestCase):
    def setUp(self):
        # Mock the database by creating test data
        self.room = Room.objects.create(
            name='Tournament Room',
            maxAmountOfPlayers=8,
            type=1,  # Tournament
            amountOfPlayers=8
        )
        # Add 8 players to the mock database
        self.players = []
        for i in range(1, 9):
            player = Player.objects.create(
                name=f'Player {i}',
                roomId=self.room,
                roomCode=self.room.code,
                bracketsPosition=i
            )
            self.players.append(player)

    def test_create_tournament_matches(self):
        # Call the function to create tournament matches
        createTournamentMatches(self.room)

        # Calculate expected number of matches
        number_of_rounds = math.ceil(math.log2(self.room.maxAmountOfPlayers))
        total_matches = sum(2 ** (number_of_rounds - round_number) for round_number in range(1, number_of_rounds + 1))

        # Check if the correct number of matches were created
        matches = Match.objects.filter(room=self.room)
        self.assertEqual(matches.count(), total_matches)

        # Validate first round matches have correct players assigned
        first_round_matches = matches.filter(stage=1).order_by('position')
        self.assertEqual(first_round_matches.count(), 4)  # Should be 4 matches in the first round

        expected_pairs = list(zip(self.players[::2], self.players[1::2]))
        for match, (player_one, player_two) in zip(first_round_matches, expected_pairs):
            match_players = MatchPlayer.objects.filter(match=match)
            self.assertEqual(match_players.count(), 2)
            self.assertIn(player_one, [mp.player for mp in match_players])
            self.assertIn(player_two, [mp.player for mp in match_players])

    def test_matches_linked_correctly(self):
        createTournamentMatches(self.room)
        matches = Match.objects.filter(room=self.room)
        number_of_rounds = math.ceil(math.log2(self.room.maxAmountOfPlayers))

        # For each match except the final, check that nextMatch is set correctly
        for stage in range(1, number_of_rounds):
            current_round_matches = matches.filter(stage=stage).order_by('position')
            next_round_matches = matches.filter(stage=stage + 1).order_by('position')
            for i in range(0, len(current_round_matches), 2):
                match_one = current_round_matches[i]
                match_two = current_round_matches[i + 1]
                expected_next_match = next_round_matches[i // 2]
                self.assertEqual(match_one.nextMatch, expected_next_match.id)
                self.assertEqual(match_two.nextMatch, expected_next_match.id)

        # Final match should not have a nextMatch
        final_match = matches.get(stage=number_of_rounds)
        self.assertIsNone(final_match.nextMatch)

    def test_tournament_progression(self):
        createTournamentMatches(self.room)
        matches = Match.objects.filter(room=self.room)
        number_of_rounds = math.ceil(math.log2(self.room.maxAmountOfPlayers))

        # Simulate tournament progression by assigning winners
        for stage in range(1, number_of_rounds + 1):
            stage_matches = matches.filter(stage=stage).order_by('position')
            for match in stage_matches:
                match_players = MatchPlayer.objects.filter(match=match)
                if not match_players.exists():
                    match.status = 3  # Finished without players
                    match.save()
                    continue  # Skip matches without players
                # Assign the first player as the winner
                winner_player = match_players.first().player
                match.winner = winner_player.id
                match.status = 3  # Finished
                match.save()
            if match.nextMatch:
                next_match = Match.objects.get(id=match.nextMatch)
                MatchPlayer.objects.create(match=next_match, player=winner_player)

        # Check that the final match has a winner
        final_match = matches.get(stage=number_of_rounds)
        self.assertIsNotNone(final_match.winner)

        # Check that the tournament winner is one of the original players
        tournament_winner = Player.objects.get(id=final_match.winner)
        self.assertIn(tournament_winner, self.players)






# tests antigos
from django.test import TestCase, Client
from django.urls import reverse
from django.http import JsonResponse
import json
from .models import Room
from players.models import Player

class RoomStatusViewTest(TestCase):
    def setUp(self):
        # Criar uma sala de teste no banco de dados de teste
        self.room = Room.objects.create(name='Test Room', status='2')

    def test_room_status_view_success(self):
        # Fazer uma requisição GET para a view com o ID da sala
        response = self.client.get(reverse('room-status', args=[self.room.code]))

        # Verificar se o status HTTP é 200 (OK)
        self.assertEqual(response.status_code, 200)

        # Verificar se o conteúdo JSON retornado está correto
        self.assertJSONEqual(response.content, {'status': self.room.status})

    def test_room_status_view_room_does_not_exist(self):
        # Fazer uma requisição GET para uma sala que não existe
        invalid_room_code = self.room.code + "invalid_part"
        response = self.client.get(reverse('room-status', args=[invalid_room_code]))

        # Verificar se a resposta é 404 (Not Found)
        self.assertEqual(response.status_code, 404)

# class CreateRoomViewTest(TestCase):
#     def setUp(self):
#         self.client = Client()
#         self.url = reverse('new-room')  # Insira o nome correto da rota para CreateRoomView

#     def test_create_room_success(self):
#         data = {
#             "createdBy": "user123",
#             "roomName": "Test Room",
#             "roomType": "1",
#             "maxAmountOfPlayers": "4",
#             "privateRoom": "true"
#         }
#         response = self.client.post(self.url, json.dumps(data), content_type="application/json")

#         # Verifica se o status HTTP é 201 (Created)
#         self.assertEqual(response.status_code, 201)

#         # Verifica o conteúdo da resposta
#         response_data = response.json()
#         self.assertIn('roomCode', response_data)
#         self.assertEqual(response['Location'], f"/session/rooms/{response_data['roomCode']}")
#         self.assertEqual(response['userId'], data["createdBy"])

#     def test_create_room_missing_fields(self):
#         data = {
#             "createdBy": "user123",
#             "roomName": "Test Room"
#             # Faltando roomType e numberOfPlayers
#         }
#         response = self.client.post(self.url, json.dumps(data), content_type="application/json")

#         # Verifica se o status HTTP é 400 (Bad Request)
#         self.assertEqual(response.status_code, 400)

#         # Verifica o conteúdo da resposta
#         response_data = response.json()
#         self.assertEqual(response_data, {'errorCode': '400', 'message': 'Bad Request'})

#     def test_create_room_invalid_room_type_format(self):
#         data = {
#             "createdBy": "user123",
#             "roomName": "Test Room",
#             "roomType": "invalid",  # Valor inválido
#             "maxAmountOfPlayers": "4",
#             "privateRoom": "true"
#         }
#         response = self.client.post(self.url, json.dumps(data), content_type="application/json")

#         # Verifica se o status HTTP é 400 (Bad Request)
#         self.assertEqual(response.status_code, 400)

#         # Verifica o conteúdo da resposta
#         response_data = response.json()
#         self.assertEqual(response_data, {'errorCode': '400', 'message': 'Bad Request'})

#     def test_create_room_invalid_number_of_players_format(self):
#         data = {
#             "createdBy": "user123",
#             "roomName": "Test Room",
#             "roomType": "1",  # Valor inválido
#             "maxAmountOfPlayers": "invalid",
#             "privateRoom": "true"
#         }
#         response = self.client.post(self.url, json.dumps(data), content_type="application/json")

#         # Verifica se o status HTTP é 400 (Bad Request)
#         self.assertEqual(response.status_code, 400)

#         # Verifica o conteúdo da resposta
#         response_data = response.json()
#         self.assertEqual(response_data, {'errorCode': '400', 'message': 'Bad Request'})

# class MatchPageViewTest(TestCase):
#     def setUp(self):
#         self.room = Room.objects.create(
#             roomCode="12345",
#             roomName="Sala Teste",
#             roomType=0,
#             maxAmountOfPlayers=2,
#             privateRoom=False,
#             createdBy="Jogador1"
#         )

#         self.match = Match.objects.create(
#             roomCode=self.room.roomCode,
#             maxAmountOfPlayers=self.room.maxAmountOfPlayers,
#             createdBy=self.room.createdBy
#         )

#         self.player1 = Player.objects.create(
#             roomCode=self.room.roomCode,
#             matchId=self.match.matchId,
#             playerId="J1",
#             playerName="Jogador1",
#             profileColor=1010,
#             urlProfileImage="url/template1"
#         )
#         self.player2 = Player.objects.create(
#             roomCode=self.room.roomCode,
#             matchId=self.match.matchId,
#             playerId="J2",
#             playerName="Jogador2",
#             profileColor=2020,
#             urlProfileImage="url/template2"
#         )
#         self.match.amountOfPlayers=2

#     def test_get_room_details(self):
#         # Simule uma requisição GET à URL da sala com o roomCode
#         url = reverse('match', args=[self.match.matchId])
#         response = self.client.get(url)

#         # Verifique se a resposta HTTP é 200 (OK)
#         self.assertEqual(response.status_code, 200)

#         # Verifique se os dados retornados estão corretos
#         response_data = response.json()

#         # Verifique os dados da sala
#         self.assertEqual(response_data["matchId"], self.match.matchId)
#         self.assertEqual(response_data["maxAmountOfPlayers"], self.match.maxAmountOfPlayers)
#         self.assertEqual(response_data["amountOfPlayers"], self.match.amountOfPlayers)
#         self.assertEqual(response_data["createdBy"], self.match.createdBy)

#         # Verifique os dados dos jogadores
#         players = response_data["players"]
#         self.assertEqual(len(players), 2)

#         # Verifique as informações do primeiro jogador
#         self.assertEqual(players[0]["playerId"], self.player1.playerId)
#         self.assertEqual(players[0]["playerName"], self.player1.playerName)
#         self.assertEqual(players[0]["profileColor"], self.player1.profileColor)
#         self.assertEqual(players[0]["urlProfileImage"], self.player1.urlProfileImage)

#         # Verifique as informações do segundo jogador
#         self.assertEqual(players[1]["playerId"], self.player2.playerId)
#         self.assertEqual(players[1]["playerName"], self.player2.playerName)
#         self.assertEqual(players[1]["profileColor"], self.player2.profileColor)
#         self.assertEqual(players[1]["urlProfileImage"], self.player2.urlProfileImage)

# class AddPlayerToRoomViewTest(TestCase):
#     def setUp(self):
#         # Cria uma sala para os testes
#         self.room = Room.objects.create(
#             roomCode="12345",
#             maxAmountOfPlayers=3,
#             createdBy="Admin"
#         )
#         self.add_player_url = reverse('add-player', args=[self.room.roomCode])  # URL do endpoint PUT

#     def test_add_player_successfully(self):
#         # Testa a adição bem-sucedida de um jogador
#         response = self.client.put(
#             self.add_player_url,
#             data={'playerName': 'Player1'},
#             content_type='application/json'
#         )
#         self.assertEqual(response.status_code, 204)
#         self.assertEqual(Player.objects.filter(roomCode=self.room.roomCode).count(), 1)
#         self.assertEqual(Player.objects.first().playerName, "Player1")
#         # self.assertEqual(response.headers.get("playerId"), "Player1")

#     def test_add_player_missing_name(self):
#         # Testa a requisição PUT sem o nome do jogador
#         response = self.client.put(
#             self.add_player_url,
#             data={},
#             content_type='application/json'
#         )
#         self.assertEqual(response.status_code, 400)

#         response_data = response.json()
#         self.assertEqual(response_data, {'errorCode': '400', 'message': 'Player name is required'})

#     def test_add_player_to_full_room(self):
#         # Preenche a sala ao máximo e testa a adição de outro jogador
#         for i in range(self.room.maxAmountOfPlayers):
#             Player.objects.create(playerName=f'Player{i+1}', roomCode=self.room.roomCode)

#         response = self.client.put(
#             self.add_player_url,
#             data={'playerName': 'ExtraPlayer'},
#             content_type='application/json'
#         )
#         self.assertEqual(response.status_code, 403)

#         response_data = response.json()
#         self.assertEqual(response_data, {'errorCode': '403', 'message': 'Room is full'})

#     def test_add_player_to_nonexistent_room(self):
#         # Testa a adição de um jogador a uma sala inexistente
#         nonexistent_room_url = reverse('add-player', args=["99999"])
#         response = self.client.put(
#             nonexistent_room_url,
#             data={'playerName': 'NonExistentRoomPlayer'},
#             content_type='application/json'
#         )
#         self.assertEqual(response.status_code, 404)

#         response_data = response.json()
#         self.assertEqual(response_data, {'errorCode': '404', 'message': 'Room not found'})

# class AvailableRoomsViewTest(TestCase):
#     @classmethod
#     def setUpTestData(cls):
#         cls.rooms = [
#             Room.objects.create(roomCode=f"room{i}", roomName=f"Room {i}", maxAmountOfPlayers=4, roomType=1)
#             for i in range(15)
#         ]
#         cls.url = reverse("available-rooms")  # URL da view

#     def test_first_page_no_filter(self):
#         # Testa a primeira página sem filtros
#         response = self.client.get(self.url, {"currentPage": 1, "pageSize": 5})
#         self.assertEqual(response.status_code, 200)
#         data = response.json()["paginatedItems"]
#         self.assertEqual(data["currentPage"], 1)
#         self.assertEqual(len(data["Data"]), 5)  # Deve retornar 5 salas

#     def test_pagination_with_multiple_pages(self):
#         # Testa a segunda página e verifica a paginação
#         response = self.client.get(self.url, {"currentPage": 2, "pageSize": 5})
#         data = response.json()["paginatedItems"]
#         self.assertEqual(response.status_code, 200)
#         self.assertEqual(data["currentPage"], 2)
#         self.assertTrue(data["hasPreviousPage"])
#         self.assertTrue(data["hasNextPage"])
#         self.assertEqual(len(data["Data"]), 5)

#     def test_filter_by_room_name(self):
#         # Testa a filtragem pelo nome da sala
#         response = self.client.get(self.url, {"currentPage": 1, "pageSize": 5, "filterLabel": "Room 1"})
#         data = response.json()["paginatedItems"]
#         self.assertEqual(response.status_code, 200)
#         # Confirma se apenas salas com "Room 1" no nome foram retornadas
#         for room in data["Data"]:
#             self.assertIn("Room 1", room["roomName"])

#     def test_filter_by_room_code(self):
#         # Testa a filtragem pelo código da sala
#         response = self.client.get(self.url, {"currentPage": 1, "pageSize": 5, "filterLabel": "room1"})
#         data = response.json()["paginatedItems"]
#         self.assertEqual(response.status_code, 200)
#         # Confirma se apenas salas com "room1" no código foram retornadas
#         for room in data["Data"]:
#             self.assertIn("room1", room["roomCode"])

#     def test_out_of_range_page(self):
#         # Testa uma página fora do intervalo (espera a última página)
#         response = self.client.get(self.url, {"currentPage": 10, "pageSize": 5})
#         data = response.json()["paginatedItems"]
#         self.assertEqual(response.status_code, 200)
#         last_page = (Room.objects.count() - 1) // 5 + 1  # Calcula o número total de páginas dinamicamente
#         self.assertEqual(data["currentPage"], last_page)
#         self.assertFalse(data["hasNextPage"])

#     def test_invalid_page(self):
#         # Testa uma página com valor inválido (não numérico)
#         response = self.client.get(self.url, {"currentPage": "invalid", "pageSize": 5})
#         data = response.json()["paginatedItems"]
#         self.assertEqual(response.status_code, 200)
#         self.assertEqual(data["currentPage"], 1)  # Deve voltar para a primeira página
#         self.assertTrue(data["hasNextPage"])

# class RemovePlayerViewTest(TestCase):

#     def setUp(self):
#         self.room = Room.objects.create(
#             roomName="Test Room",
#             maxAmountOfPlayers=4,
#             amountOfPlayers=1,
#             roomType=0,
#             roomStatus=0,
#             createdBy="Test Creator",
#             roomCode="room123"
#         )

#         self.player = Player.objects.create(
#             playerId="player123",
#             roomCode=self.room.roomCode
#         )

#     def test_remove_player_success(self):
#         response = self.client.delete(
#             reverse('remove-player', args=[self.room.roomCode, self.player.playerId])
#         )

#         self.assertEqual(response.status_code, 204)
#         self.assertEqual(Player.objects.filter(playerId=self.player.playerId).count(), 0)

#     def test_remove_player_not_found(self):
#         """Testa a tentativa de remover um jogador que não existe."""
#         response = self.client.delete(
#             reverse('remove-player', args=[self.room.roomCode, "non_existent_player"])
#         )

#         self.assertEqual(response.status_code, 404)
#         response_data = response.json()
#         self.assertEqual(response_data, {"errorCode": "404", "message": "Player not found in the room"})

#     def test_remove_player_room_not_found(self):
#         """Testa a tentativa de remover um jogador de uma sala que não existe."""
#         response = self.client.delete(
#             reverse('remove-player', args=["non_existent_room", self.player.playerId])
#         )

#         self.assertEqual(response.status_code, 404)
#         self.assertEqual(response.json(), {"errorCode": "404", "message": "Room not found"})

#     def tearDown(self):
#         """Limpa o banco de dados após os testes."""
#         self.player.delete()
#         self.room.delete()