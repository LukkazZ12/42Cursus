NAME =				fdf

SOURCES =			mandatory/fdf.c \
					mandatory/rows_cols.c \
					mandatory/parse_map.c \
					mandatory/render.c \
					mandatory/draw.c \
					mandatory/bresenham.c \
					mandatory/final.c

OBJECTS =			$(SOURCES:%.c=%.o)

BONUS_NAME =		fdf_bonus

BONUS_SOURCES =		bonus/fdf_bonus.c \
					bonus/rows_cols_bonus.c \
					bonus/parse_map_bonus.c \
					bonus/render_bonus.c \
					bonus/draw_bonus.c \
					bonus/bresenham_bonus.c \
					bonus/final_bonus.c

BONUS_OBJECTS =		$(BONUS_SOURCES:%.c=%.o)

CC =				cc

C_FLAGS =			-Wall -Wextra -Werror

LIBFT_FLAGS =		-Llibft -lft

MLX_FLAGS =			-Lmlx -lmlx -Imlx -lXext -lX11 -lm -lz

DIR_LIBFT =			./libft/

LIBFT = 			$(addprefix $(DIR_LIBFT), libft.a)

all: $(LIBFT) $(NAME)

$(LIBFT):
	@make -C $(DIR_LIBFT)

$(NAME): $(OBJECTS)
	$(CC) -no-pie $(OBJECTS) $(LIBFT_FLAGS) $(MLX_FLAGS) -o $(NAME)

%.o: %.c mandatory/fdf.h bonus/fdf_bonus.h
	$(CC) $(C_FLAGS) -o3 -I/usr/include -Imlx -g3 -c $< -o $@
	
bonus: $(LIBFT) $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJECTS)
	$(CC) -no-pie $(BONUS_OBJECTS) $(LIBFT_FLAGS) $(MLX_FLAGS) -o $(BONUS_NAME)

clean:
	@rm -Rf $(OBJECTS) $(BONUS_OBJECTS)
	@make -C $(DIR_LIBFT) clean

fclean: clean
	@rm -f $(NAME) $(BONUS_NAME)
	@make -C $(DIR_LIBFT) fclean

re: fclean all

rebonus: fclean bonus

.PHONY: all clean fclean re bonus