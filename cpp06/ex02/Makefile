NAME = identify
SRC = main.cpp
OBJ = ${SRC:.cpp=.o}
INCLUDES = Base.hpp A.hpp B.hpp C.hpp
FLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic-errors

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

