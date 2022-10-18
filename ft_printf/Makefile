NAME =		libftprintf.a

SRC =		ft_printf.c \
			ft_printf_spdiuxX.c \
			ft_printf_c_chr.c

OBJ =		$(SRC:%.c=%.o)

BONUS_SRC =	ft_printf_bonus.c \
			ft_printf_spdiuxX_bonus.c \
			ft_printf_c_chr_bonus.c

BONUS_OBJ =	$(BONUS_SRC:%.c=%.o)

CFLAGS =	-Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)

bonus: $(BONUS_OBJ)

clean:
	rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

%.o: %.c
	cc $(CFLAGS) -c $< -o $@
	ar rcs $(NAME) $@

.PHONY: all clean fclean re bonus