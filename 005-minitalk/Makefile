NAME			=		minitalk

SERVER			=		server

SERVER_BONUS	=		server_bonus

CLIENT			=		client

CLIENT_BONUS	=		client_bonus

SOURCES			=		server.c \
						client.c \
						libft.c

SOURCES_BONUS	=		server_bonus.c \
						client_bonus.c \
						libft_bonus.c

SOURCES_PATH	=		sources

SOURCES_B_PATH	=		sources_bonus

SOURCE			=		$(addprefix $(SOURCES_PATH)/, $(SOURCES))

SOURCE_BONUS	=		$(addprefix $(SOURCES_B_PATH)/, $(SOURCES_BONUS))

OBJECTS_PATH	=		objects

OBJECTS_B_PATH	=		objects_bonus

OBJECTS			=		$(addprefix $(OBJECTS_PATH)/, $(SOURCES:.c=.o))

OBJECTS_BONUS	=		$(addprefix $(OBJECTS_B_PATH)/, $(SOURCES_BONUS:.c=.o))

HEADER_PATH		=		includes

CC				=		cc

C_FLAGS			=		-Wall -Wextra -Werror -g3 -I$(HEADER_PATH)

RM				=		rm -rf

all:					$(NAME)

$(NAME):				$(OBJECTS_PATH) $(OBJECTS) $(SERVER) $(CLIENT)

$(SERVER):				$(OBJECTS_PATH) $(OBJECTS)
						$(CC) $(C_FLAGS) $(addprefix $(OBJECTS_PATH)/, server.o) \
							$(addprefix $(OBJECTS_PATH)/, libft.o) -o $@

$(CLIENT):				$(OBJECTS_PATH) $(OBJECTS)	
						$(CC) $(C_FLAGS) $(addprefix $(OBJECTS_PATH)/, client.o) \
							$(addprefix $(OBJECTS_PATH)/, libft.o) -o $@
					
$(OBJECTS_PATH):
						@mkdir -p $(OBJECTS_PATH)

$(OBJECTS_PATH)/%.o:	$(SOURCES_PATH)/%.c $(HEADER_PATH)/minitalk.h
						$(CC) $(C_FLAGS) -c $< -o $@

bonus:					$(OBJECTS_B_PATH) $(OBJECTS_BONUS) $(SERVER_BONUS) $(CLIENT_BONUS)

$(SERVER_BONUS):		$(OBJECTS_B_PATH) $(OBJECTS_BONUS)
						$(CC) $(C_FLAGS) $(addprefix $(OBJECTS_B_PATH)/, server_bonus.o) \
							$(addprefix $(OBJECTS_B_PATH)/, libft_bonus.o) -o $@

$(CLIENT_BONUS):		$(OBJECTS_B_PATH) $(OBJECTS_BONUS)	
						$(CC) $(C_FLAGS) $(addprefix $(OBJECTS_B_PATH)/, client_bonus.o) \
							$(addprefix $(OBJECTS_B_PATH)/, libft_bonus.o) -o $@
					
$(OBJECTS_B_PATH):
						@mkdir -p $(OBJECTS_B_PATH)

$(OBJECTS_B_PATH)/%.o:	$(SOURCES_B_PATH)/%.c $(HEADER_PATH)/minitalk_bonus.h
						$(CC) $(C_FLAGS) -c $< -o $@

clean:
						@$(RM) $(OBJECTS_PATH) $(OBJECTS_B_PATH)

fclean:					clean
						@$(RM) $(SERVER) $(CLIENT) $(SERVER_BONUS) $(CLIENT_BONUS)

re:						fclean all

rebonus:				fclean bonus

.PHONY:					all clean fclean re bonus