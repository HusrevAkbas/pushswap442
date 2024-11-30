CFLAGS := -Wall -Wextra -Werror

LIBFT := libft

LIBFTA := libcheck

SRC := $(wildcard *.c)

OBJ := $(SRC:.c=.o)

NAME := push_swap

all: ${NAME} clean
	./${NAME} -3 4 -12 33 77

${NAME}: ${OBJ} ${LIBFTA}
	@ cc -g ${CFLAGS} ${OBJ} -L ${LIBFT} -lft -o ${NAME}

${OBJ}: ${SRC}
	@ cc -g -c ${CFLAGS} ${SRC}

${LIBFTA}:
	${MAKE} -C ${LIBFT} bonus clean
	touch ${LIBFTA}

clean:
#@ ${MAKE} -C ${LIBFT} clean
	@ rm -f ${OBJ}

fclean: clean
	@ ${MAKE} -C ${LIBFT} fclean
	@ rm -f ${NAME} ${LIBFTA}

re: fclean all

val:
	valgrind -s --leak-check=yes --show-leak-kinds=all --track-origins=yes ./${NAME}

run:
	./${NAME}