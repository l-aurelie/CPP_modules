NAME = materia
SRC = AMateria.cpp Character.cpp Cure.cpp MateriaSource.cpp Ice.cpp main.cpp
OBJ = ${SRC:.cpp=.o}
INCLUDES = AMateria.hpp Character.hpp Cure.hpp ICharacter.hpp MateriaSource.hpp Ice.hpp 
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

