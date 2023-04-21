NAME			=		push_swap

SOURCES 		=		push_swap.c \
						libft.c \
						check_arg.c \
						stack_functions.c \
						operations_s_p.c \
						operations_r_rr.c \
						two_to_five_radix.c

SOURCES_PATH	=		sources

SOURCE			=		$(addprefix $(SOURCES_PATH)/, $(SOURCES))

OBJECTS_PATH	=		objects

OBJECTS			=		$(addprefix $(OBJECTS_PATH)/, $(SOURCES:.c=.o))

HEADER_PATH		=		includes

CC				=		cc

C_FLAGS			=		-Wall -Wextra -Werror -g3 -I$(HEADER_PATH)

RM				=		rm -rf

all: 					$(NAME)

$(NAME):				$(OBJECTS_PATH) $(OBJECTS)
						$(CC) $(C_FLAGS) $(OBJECTS) -o $@

$(OBJECTS_PATH):
						@mkdir -p $(OBJECTS_PATH)

$(OBJECTS_PATH)/%.o:	$(SOURCES_PATH)/%.c $(HEADER_PATH)/push_swap.h
					 	$(CC) $(C_FLAGS) -c $< -o $@

clean:
						@$(RM) $(OBJECTS_PATH)

fclean:					clean
						@$(RM) $(NAME)

re:						fclean all

.PHONY:					all clean fclean re