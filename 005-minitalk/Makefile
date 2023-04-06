NAME 		=		minitalk
SERVER		=		server
CLIENT 		=		client
SRC			= 		server.c \
					client.c \
					utils.c \
					libft.c

SRCS_PATH	= 		sources
OBJS_PATH	= 		objects
SRCS		= 		$(addprefix $(SRCS_PATH)/, $(SRC))
OBJS		= 		$(addprefix $(OBJS_PATH)/, $(SRC:.c=.o))

CC			= 		cc -Wall -Wextra -Werror
RM			= 		rm -rf

all:				$(NAME) 

$(NAME):			$(OBJS_PATH) $(OBJS) $(SERVER) $(CLIENT)			


$(SERVER):			$(OBJS_PATH) $(OBJS)
					$(CC) $(addprefix $(OBJS_PATH)/, server.o) \
						$(addprefix $(OBJS_PATH)/, utils.o) \
						$(addprefix $(OBJS_PATH)/, libft.o) -o $(SERVER)

$(CLIENT):			$(OBJS_PATH) $(OBJS)	
					$(CC) $(addprefix $(OBJS_PATH)/, client.o) \
						$(addprefix $(OBJS_PATH)/, utils.o) \
						$(addprefix $(OBJS_PATH)/, libft.o) -o $(CLIENT)
					
$(OBJS_PATH):
					mkdir -p $(OBJS_PATH)

$(OBJS_PATH)/%.o:	$(SRCS_PATH)/%.c
					$(CC) -c $< -o $@

clean:
					$(RM) $(OBJS_PATH)

fclean:				clean
					$(RM) $(SERVER) $(CLIENT)

re:					fclean all

.PHONY:				all clean fclean re