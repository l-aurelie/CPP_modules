NAME = Animal
SRC = Animal.cpp Cat.cpp Dog.cpp WrongAnimal.cpp WrongCat.cpp main.cpp
OBJ = ${SRC:.cpp=.o}
INCLUDES = Animal.hpp Cat.hpp Dog.hpp WrongAnimal.hpp WrongCat.hpp
FLAGS = -Wall -Wextra -Werror -std=c++98

all: ${NAME} 

%.o: %.cpp ${INCLUDES}
	c++ ${FLAGS} -c $< -o $@

${NAME}: ${OBJ} ${INCLUDES}
	c++ ${FLAGS} ${OBJ} -o ${NAME}

clean:
	rm -f ${OBJ}

fclean: clean
	rm -f ${NAME}

re: fclean ${NAME}

.PHONY: all clean fclean re

