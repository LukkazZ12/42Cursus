NAME					=	warlock

HEADER_PATH				=	includes

SOURCES_PATH			=	sources

OBJECTS_PATH			=	objects

FLAGS					=	-Wall -Wextra -Werror -std=c++98 -I$(HEADER_PATH)

CPP						=	c++

SOURCES					=	main.cpp \
							Warlock.cpp

OBJECTS					=	$(addprefix $(OBJECTS_PATH)/,	$(SOURCES:.cpp=.o))

RM						=	rm -rf

all:					$(NAME)

$(NAME):				$(OBJECTS_PATH) $(OBJECTS)
						@echo "\033[32mCompiling...\033[0m"
						@$(CPP) $(FLAGS) $(OBJECTS) -o $@

$(OBJECTS_PATH):
						@mkdir -p $(OBJECTS_PATH)

$(OBJECTS_PATH)/%.o:	$(SOURCES_PATH)/%.cpp $(HEADER_PATH)/Warlock.hpp
						@$(CPP) $(FLAGS) -c $< -o $@

clean:
						@$(RM) $(OBJECTS_PATH)
						@echo "\033[31mRemoved o-files.\033[0m"

fclean:					clean
						@$(RM) $(NAME)
						@echo "\033[31mRemoved executable file.\033[0m"

re:						fclean all

.PHONY:					all clean fclean re