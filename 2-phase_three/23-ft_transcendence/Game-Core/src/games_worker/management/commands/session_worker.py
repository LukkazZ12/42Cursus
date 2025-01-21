import asyncio, logging

from games_worker.listeners.game_maker_listener import GameMakerListener
from django.core.management.base import BaseCommand

class Command(BaseCommand):
    help = "Run <session_worker> to start the game state worker."

    async def send_game_state(self):
        game_maker_listener = GameMakerListener()

        try:
            await game_maker_listener.listen()
        except KeyboardInterrupt:
            logging.warning("\033[33mWorker has been stopped. Waiting for pending tasks...\033[0m")
            await game_maker_listener.wait_for_tasks()
            logging.warning("\033[33mAll tasks have been completed.\033[0m")
        except asyncio.CancelledError:
            logging.warning("\033[33mWorker has been stopped.\033[0m")
            await game_maker_listener.wait_for_tasks()

    def handle(self, *args, **kwargs):
        logging.warning("\033[33mStarting game state worker...\033[0m")
        try:
            loop = asyncio.get_event_loop()
            loop.create_task(self.send_game_state())
            loop.run_forever()
        except KeyboardInterrupt:
            logging.warning("\033[33mWorker has been stopped.\033[0m")
            loop.stop()
