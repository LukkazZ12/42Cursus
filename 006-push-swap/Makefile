NAME =		push_swap
CFLAGS =	-Wall -Wextra -Werror -g3

SRCS =		push_swap.c \
			libft.c \
			check_arg.c \
			stack_functions.c \
			operations_s_p.c \
			operations_r_rr.c \
			two_to_five_radix.c

OBJS = $(SRCS:%.c=%.o)

all: $(NAME)

%.o:%.c
	cc $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	cc $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re