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

CHECK_M = $(shell ar -t $(NAME) ft_printf.o 2>&1)
CHECK_B = $(shell ar -t $(NAME) ft_printf_bonus.o 2>&1)

ifeq ($(CHECK_B) , ft_printf_bonus.o)
all:
else
all: $(NAME)
endif

$(NAME): $(OBJ)

ifeq ($(CHECK_M) , ft_printf.o)
bonus: fclean $(BONUS_OBJ)
else
bonus: $(BONUS_OBJ)
endif

clean:
	rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

%.o: %.c
	cc $(CFLAGS) -c $< -o $@
	ar rcs $(NAME) $@

.PHONY: all clean fclean re bonus