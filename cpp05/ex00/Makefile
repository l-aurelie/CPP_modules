NAME = bureaucrat
SRC = Bureaucrat.cpp main.cpp
OBJ = ${SRC:.cpp=.o}
INCLUDES = Bureaucrat.hpp
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

