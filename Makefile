CFLAGS := -Wall -Wextra -Werror

TARGET := test

SRC := $(wildcard *.c)

OBJ := $(SRC:.c=.o)

NAME := push_swap

all: ${NAME} clean
	./${NAME} -3 4 12 33 77

${NAME}: ${OBJ}
	cc -g ${CFLAGS} ${OBJ} -o ${NAME}

${OBJ}: ${SRC}
	cc -g -c ${CFLAGS} ${SRC}

clean:
	rm -f ${OBJ}

fclean:
	rm -f ${NAME}

val:
	valgrind -s --leak-check=yes --show-leak-kinds=all --track-origins=yes ./${NAME}

run:
	./${NAME}