CFLAGS := -Wall -Wextra -Werror

LIBFT := libft

LIBFTA := libcheck

SRC := $(wildcard *.c)

OBJ := $(SRC:.c=.o)

NAME := push_swap
#| paste - - - - - - -
TEST1 = ./${NAME} 96 88 73 25 79 4 97 7 16 12 84 52 31 71 70 99 11 17 87 66 62 33 34 6 15 21 94 77 48 92 20 60 69 9 24 40 85 61 63 82 55 91 14 5 26 28 75 3 67 22 23 59 58 86 45 10 90 35 2 8 101 100 53 50 13 56 39 95 78 32 1 93 37 51 80 29 57 36 18 64 27 68 42 44 54 0 98 72 38 76 49 19 30 74 47 43 81 83 89 65 41
TEST4 = ./${NAME} 7 53 44 64 98 85 65 76 99 60 14 88 2 13 81 93 15 72 1 66 36 51 55 89 31 83 18 3 49 56 67 43 4 37 59 45 69 11 23 57 48 40 34 84 87 46 78 77 35 27 30 52 8 19 79 86 42 12 33 29 61 9 50 100 97 91 54 63 82 68 26 95 70 74 41 92 24 47 58 71 80 28 25 10 75 90 94 96 73 21 39 5 62 32 20 38 17 6 22 16
TEST3 = ./${NAME} 19 1 10 3 6 4 5 2 7 8
TEST2 = ./${NAME} -3 4 12 33 77 || true

all: ${NAME} clean
#	-${TEST2}
	-${TEST4}

${NAME}: ${OBJ} ${LIBFTA}
	@-cc -g ${CFLAGS} ${OBJ} -L ${LIBFT} -lft -o ${NAME}

${OBJ}: ${SRC}
	@- cc -g -c ${CFLAGS} ${SRC}

${LIBFTA}:
	@- ${MAKE} -C ${LIBFT} bonus clean
	touch ${LIBFTA}

clean:
#@ ${MAKE} -C ${LIBFT} clean
	@- rm -f ${OBJ}

fclean: clean
	@ ${MAKE} -C ${LIBFT} fclean
	rm -f ${NAME} ${LIBFTA}

re: fclean all

val:
	@valgrind -s --leak-check=yes --show-leak-kinds=all --track-origins=yes ${TEST1}

run:
	./${NAME}