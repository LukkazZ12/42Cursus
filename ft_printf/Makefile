SRCS	= ft_printf.c printf_spdiuxX.c

HEADERS	= ./ft_printf.h 

OBJS	= ${SRCS:.c=.o}

BONUS_OBJS	= ${BONUS:.c=.o}

NAME	= libftprintf.a

RM	= rm -f

.c.o:
	clang -Wall -Wextra -Werror -g -c $< -o ${<:.c=.o} 

all: ${NAME}

${NAME}:	${OBJS}
	ar -rcs ${NAME} ${OBJS}

clean:
	${RM} ${OBJS} ${BONUS_OBJS} 

fclean:	clean
	${RM} ${NAME} 

re: fclean all

.PHONY:	all clean fclean re