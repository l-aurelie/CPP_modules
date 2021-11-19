NAME = weapon
SRC = main.cpp Weapon.cpp HumanA.cpp HumanB.cpp
OBJ = ${SRC:.cpp=.o}
INC = HumanA.hpp HumanB.hpp Weapon.hpp
FLAGS = -Wall -Wextra -Werror -std=c++98

all: ${NAME} 

%.o: %.cpp ${INC}
	c++ ${FLAGS} -c $< -o $@

${NAME}: ${OBJ} ${INC}
	c++ ${FLAGS} ${OBJ} -o ${NAME}

clean:
	rm -f ${OBJ}

fclean: clean
	rm -f ${NAME}

re: fclean ${NAME}

.PHONY: all re clean fclean

