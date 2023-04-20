NAME			=		minitalk

SERVER			=		server

CLIENT			=		client

SOURCES			=		server.c \
						client.c \
						utils.c \
						libft.c

SOURCES_PATH	=		sources

SOURCE			=		$(addprefix $(SOURCES_PATH)/, $(SOURCES))

OBJECTS_PATH	=		objects

OBJECTS			=		$(addprefix $(OBJECTS_PATH)/, $(SOURCES:.c=.o))

HEADER_PATH		=		includes

CC				=		cc

C_FLAGS			=		-Wall -Wextra -Werror -g3 -I$(HEADER_PATH)

RM				=		rm -rf

all:					$(NAME)

$(NAME):				$(OBJECTS_PATH) $(OBJECTS) $(SERVER) $(CLIENT)

$(SERVER):				$(OBJECTS_PATH) $(OBJECTS)
						$(CC) $(C_FLAGS) $(addprefix $(OBJECTS_PATH)/, server.o) \
							$(addprefix $(OBJECTS_PATH)/, utils.o) \
							$(addprefix $(OBJECTS_PATH)/, libft.o) -o $@

$(CLIENT):				$(OBJECTS_PATH) $(OBJECTS)	
						$(CC) $(C_FLAGS) $(addprefix $(OBJECTS_PATH)/, client.o) \
							$(addprefix $(OBJECTS_PATH)/, utils.o) \
							$(addprefix $(OBJECTS_PATH)/, libft.o) -o $@
					
$(OBJECTS_PATH):
						@mkdir -p $(OBJECTS_PATH)

$(OBJECTS_PATH)/%.o:	$(SOURCES_PATH)/%.c includes/minitalk.h
						$(CC) $(C_FLAGS) -c $< -o $@

clean:
						@$(RM) $(OBJECTS_PATH)

fclean:					clean
						@$(RM) $(SERVER) $(CLIENT)

re:						fclean all

.PHONY:					all clean fclean re