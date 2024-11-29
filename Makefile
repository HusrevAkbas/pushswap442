CFLAGS := -Wall -Wextra -Werror

TARGET := test

SRC := $(wildcard *.c)

OBJ := $(SRC: .c=.o)

NAME := push_swap

all:
	cc -g ${CFLAGS} ${SRC} -o ${NAME}
	./${NAME} 1233 1233 123123

clean:
	rm -f ${OBJ}

fclean:
	rm -f ${NAME}

val:
	valgrind -s --leak-check=yes --show-leak-kinds=all --track-origins=yes ./${NAME}

run:
	./${NAME}