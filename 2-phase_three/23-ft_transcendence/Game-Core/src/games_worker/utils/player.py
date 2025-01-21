from .game_config import GameConfig

class Player:
    def __init__(self, user_id, color, x, y, orientation):
        self.user_id = user_id
        self.color = color
        self.x = x
        self.y = y
        self.orientation = orientation
        self.score = 0
        self.width = GameConfig.player_width
        self.height = GameConfig.player_height

    def to_dict(self):
        return {
            "user_id": self.user_id,
            "color": self.color,
            "x": self.x,
            "y": self.y,
            "width": self.width,
            "height": self.height,
        }