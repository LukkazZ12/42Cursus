NAME			=		ircserv

CC				=		c++ -g3
FLAGS			=		-Wall -Wextra -Werror -std=c++98
RM				=		rm -rf

INCLUDES		=		-I ./includes/ -I ./includes/classes

SRCS_PATH		=		srcs/
OBJECTS_PATH	=		objects/
VPATH			=		srcs:srcs/classes:srcs/commands

SOURCES			=		main.cpp \
						Server.cpp \
						Client.cpp \
						Message.cpp \
						Channel.cpp \
						Commands.cpp \
						Utils.cpp \
						USER.cpp \
						NICK.cpp \
						PASS.cpp \
						QUIT.cpp \
						JOIN.cpp \
						PART.cpp \
						PRIVMSG.cpp \
						KICK.cpp \
						INVITE.cpp \
						TOPIC.cpp \
						MODE.cpp

HEADERS			=		includes/classes/Channel.hpp \
						includes/classes/Client.hpp \
						includes/classes/CommandArgs.hpp \
						includes/classes/Commands.hpp \
						includes/classes/Message.hpp \
						includes/classes/Server.hpp \
						includes/classes/Utils.hpp \
						includes/ft_irc.hpp \
						includes/replies.hpp

OBJECTS			=		$(patsubst %.cpp, $(OBJECTS_PATH)%.o, $(SOURCES))

all:					$(NAME)

$(OBJECTS_PATH)%.o:		%.cpp
						@mkdir -p $(dir $@)
						@$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

$(NAME):				$(OBJECTS) $(HEADERS)
						@$(CC) $(FLAGS) $(INCLUDES) $(OBJECTS) -o $@
						@echo "\033[32mircserv compiled!\033[0m"

clean:
						@$(RM) $(OBJECTS_PATH)

fclean:					clean
						@$(RM) $(NAME)

re:						fclean all

.PHONY:					all bonus clean fclean re