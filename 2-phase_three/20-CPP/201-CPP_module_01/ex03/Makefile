NAME					=	unnecessaryViolence

HEADER_PATH				=	includes

SOURCES_PATH			=	sources

OBJECTS_PATH			=	objects

FLAGS					=	-Wall -Wextra -Werror -std=c++98 -I$(HEADER_PATH)

CPP						=	c++

SOURCES					=	HumanA.cpp \
							HumanB.cpp \
							main.cpp \
							Weapon.cpp

OBJECTS					=	$(addprefix $(OBJECTS_PATH)/,	$(SOURCES:.cpp=.o))

RM						=	rm -rf

all:					$(NAME)

$(NAME):				$(OBJECTS_PATH) $(OBJECTS)
						@echo "Compiling..."
						@$(CPP) $(FLAGS) $(OBJECTS) -o $@

$(OBJECTS_PATH):
						@mkdir -p $(OBJECTS_PATH)

$(OBJECTS_PATH)/%.o:	$(SOURCES_PATH)/%.cpp $(HEADER_PATH)/HumanA.hpp $(HEADER_PATH)/HumanB.hpp $(HEADER_PATH)/Weapon.hpp
						@$(CPP) $(FLAGS) -c $< -o $@

clean:
						@$(RM) $(OBJECTS_PATH)
						@echo "Removed o-files."

fclean:					clean
						@$(RM) $(NAME)
						@echo "Removed executable file."

re:						fclean all

.PHONY:					all clean fclean re