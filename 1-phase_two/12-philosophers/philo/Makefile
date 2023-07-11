NAME			=		philo

HEADER_PATH		=		includes

OBJECTS_PATH	=		objects

SOURCES_PATH	=		sources

SOURCES			=		hello_hello_hello.c \
						pit_crew.c \
						reading_is_fundamental.c \
						rupauls_dragrace.c \
						the_library_is_open.c \
						the_library_is_officially_closed.c \
						tuck_and_untuck.c

OBJECTS			=		$(addprefix $(OBJECTS_PATH)/, $(SOURCES:.c=.o))

CC				=		cc

C_FLAGS			=		-Wall -Werror -Wextra -g3 -pthread -I$(HEADER_PATH)

RM				=		rm -rf

all:					$(NAME)

$(NAME):				$(OBJECTS_PATH) $(OBJECTS)
						@$(CC) $(C_FLAGS) $(OBJECTS) -o $@

$(OBJECTS_PATH):
						@mkdir -p $(OBJECTS_PATH)

$(OBJECTS_PATH)/%.o:	$(SOURCES_PATH)/%.c $(HEADER_PATH)/werkroom.h
						@$(CC) $(C_FLAGS) -c $< -o $@

clean:
						@$(RM) $(OBJECTS_PATH)

fclean:					clean
						@$(RM) $(NAME)

re:						fclean all

.PHONY:					all clean fclean re