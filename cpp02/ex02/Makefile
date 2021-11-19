NAME = Fixed_point
SRC = main.cpp Fixed.cpp
OBJ = ${SRC:.cpp=.o}
INC = Fixed.hpp
FLAGS = -Wall -Wextra -Werror -std=c++98

all: ${NAME} 

%.o: %.cpp ${INC}
	clang++ ${FLAGS} -c $< -o $@

${NAME}: ${OBJ} ${INC}
	clang++ ${FLAGS} ${OBJ} -o ${NAME}

clean:
	rm -f ${OBJ}

fclean: clean
	rm -f ${NAME}

re: fclean ${NAME}

.PHONY: all re clean fclean

