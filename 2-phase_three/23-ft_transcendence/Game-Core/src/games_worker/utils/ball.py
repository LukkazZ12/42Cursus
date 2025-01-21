from .game_config import GameConfig

class Ball:
    def __init__(self):
        self.x = 0
        self.y = 0
        self.radius = GameConfig.ball_size

    def to_dict(self):
        return {
            "x": self.x,
            "y": self.y,
            "radius": self.radius,
        }