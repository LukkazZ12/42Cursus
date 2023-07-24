NAME			=		philo

HEADER_PATH		=		includes

GNL_PATH		=		get_next_line

OBJECTS_PATH	=		objects

SOURCES_PATH	=		sources

GNL				=		$(addprefix $(GNL_PATH)/,	get_next_line.c \
													get_next_line_utils.c)

SOURCES			=		hello_hello_hello.c \
						pit_crew.c \
						reading_is_fundamental.c \
						rupauls_dragrace.c \
						the_library_is_open.c \
						the_library_is_officially_closed.c \
						tuck_and_untuck.c \
						$(GNL)

OBJECTS			=		$(addprefix $(OBJECTS_PATH)/, $(SOURCES:.c=.o))

CC				=		cc

C_FLAGS			=		-Wall -Werror -Wextra -g3 -pthread -I$(HEADER_PATH)

RM				=		rm -rf

all:					$(NAME)

$(NAME):				$(OBJECTS_PATH) $(OBJECTS)
						@$(CC) $(C_FLAGS) $(OBJECTS) -o $@

$(OBJECTS_PATH):
						@mkdir -p $(OBJECTS_PATH)
						@mkdir -p $(OBJECTS_PATH)/$(GNL)

$(OBJECTS_PATH)/%.o:	$(SOURCES_PATH)/%.c $(HEADER_PATH)/werkroom.h $(HEADER_PATH)/get_next_line.h
						@$(CC) $(C_FLAGS) -c $< -o $@

clean:
						@$(RM) $(OBJECTS_PATH)

fclean:					clean
						@$(RM) $(NAME)

re:						fclean all

.PHONY:					all clean fclean re