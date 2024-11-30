CFLAGS := -Wall -Wextra -Werror

LIBFT := libft

SRC := $(wildcard *.c)

OBJ := $(SRC:.c=.o)

NAME := push_swap

all: ${NAME} clean
	./${NAME} -3 4 -12 33 77

${NAME}: ${OBJ}
	${MAKE} -C ${LIBFT} all clean
	cc -g ${CFLAGS} ${OBJ} -L ${LIBFT} -lft -o ${NAME}

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