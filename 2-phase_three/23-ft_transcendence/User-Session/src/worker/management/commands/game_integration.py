import asyncio, logging

from worker.listeners.orchestrator_listerner import OrchestratorListener
from django.core.management.base import BaseCommand

class Command(BaseCommand):
    help = "Run <game_integration> to start the game integration worker."

    async def orchetrator(self):
        game_sync_listener = OrchestratorListener()

        try:
            await game_sync_listener.listen()
        except KeyboardInterrupt:
            logging.info("UserSession: All tasks have been completed.")
        except asyncio.CancelledError:
            logging.info("UsserSession: Worker has been stopped.")

    def handle(self, *args, **kwargs):
        logging.info("UsserSession: Starting game integration worker...")
        try:
            loop = asyncio.get_event_loop()
            loop.create_task(self.orchetrator())
            loop.run_forever()
        except KeyboardInterrupt:
            logging.info("UsserSession: Worker has been stopped.")
            loop.stop()