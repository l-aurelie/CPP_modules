NAME = megaphone
SRC = megaphone.cpp
OBJ = ${SRC:.cpp=.o}
FLAGS = -Wall -Wextra -Werror -std=c++98

all: ${NAME} 

%.o: %.cpp
	c++ ${FLAGS} -c $< -o $@

${NAME}: ${OBJ}
	c++ ${FLAGS} -o ${NAME} ${OBJ}

clean:
	rm -f ${OBJ}

fclean: clean
	rm -f ${NAME}

re: fclean ${NAME}

.PHONY: all clean fclean re
