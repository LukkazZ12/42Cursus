NAME					=	aanimal

HEADER_PATH				=	includes

SOURCES_PATH			=	sources

OBJECTS_PATH			=	objects

FLAGS					=	-Wall -Wextra -Werror -std=c++98 -I$(HEADER_PATH)

CPP						=	c++

SOURCES					=	AAnimal.cpp \
							Brain.cpp \
							Cat.cpp \
							Dog.cpp \
							main.cpp \

OBJECTS					=	$(addprefix $(OBJECTS_PATH)/,	$(SOURCES:.cpp=.o))

RM						=	rm -rf

all:					$(NAME)

$(NAME):				$(OBJECTS_PATH) $(OBJECTS)
						@echo "Compiling..."
						@$(CPP) $(FLAGS) $(OBJECTS) -o $@

$(OBJECTS_PATH):
						@mkdir -p $(OBJECTS_PATH)

$(OBJECTS_PATH)/%.o:	$(SOURCES_PATH)/%.cpp $(HEADER_PATH)/AAnimal.hpp $(HEADER_PATH)/Brain.hpp \
							$(HEADER_PATH)/Cat.hpp $(HEADER_PATH)/Dog.hpp
						@$(CPP) $(FLAGS) -c $< -o $@

clean:
						@$(RM) $(OBJECTS_PATH)
						@echo "Removed o-files."

fclean:					clean
						@$(RM) $(NAME)
						@echo "Removed executable file."

re:						fclean all

.PHONY:					all clean fclean re