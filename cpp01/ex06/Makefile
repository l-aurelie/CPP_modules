NAME = karenFilter
SRC = main.cpp Karen.cpp
OBJ = ${SRC:.cpp=.o}
INC = Karen.hpp
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

