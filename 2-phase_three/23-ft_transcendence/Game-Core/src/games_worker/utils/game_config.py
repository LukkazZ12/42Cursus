import random
import math

class playerColor(enumerate):
	BLUE = 0
	RED = 1
 
	GREEN = 3
	YELLOW = 4
	WHITE = 5
	BLACK = 6

class GameConfig:
	# Screen Configuration
	screen_width = 0
	screen_height = 0

	field_height = 80
	field_width = 90
	multiplayer_field_width = 80

	max_score = 5

	# Ball Configuration
	speed_range_min = 0.4
	speed_range_max = 0.7
	ball_speed_x_coef = random.choice([-1, 1])
	ball_speed_y_coef = random.choice([-1, 1])
	ball_speed_x = ball_speed_x_coef * random.uniform(speed_range_min, speed_range_max)
	ball_speed_y = ball_speed_y_coef * random.uniform(speed_range_min, speed_range_max)
	ball_size = 2

	# Player Configuration
	player_speed = 4

	player_height = 16
	player_width = 2

	multiplayer_height = 2
	multiplayer_width = 16

	player_positions = [
		{"x": -(field_width - player_width) / 2, "y": 0},
		{"x": (field_width - player_width) / 2, "y": 0},
	]

	multiplayer_positions = [
		{"x": -(multiplayer_field_width - player_width) / 2, "y": 0},
		{"x": (multiplayer_field_width - player_width) / 2, "y": 0},
		{"x": 0, "y": (multiplayer_field_width - multiplayer_height) / 2},
		{"x": 0, "y": -(multiplayer_field_width - multiplayer_height) / 2},
	]

	max_distance_ball_player = ball_size + math.sqrt((player_height / 2)**2 + (player_width / 2)**2)

class GameStatus:
	WAITING = "WAITING"
	PLAYING = "PLAYING"
	FINISHED = "FINISHED"
	PAUSED = "PAUSED"