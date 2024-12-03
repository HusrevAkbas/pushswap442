CFLAGS := -Wall -Wextra -Werror

LIBFT := libft

LIBFTA := libcheck

SRC := $(wildcard *.c)

OBJ := $(SRC:.c=.o)

NAME := push_swap
#| paste - - - - - - -
TEST1 = ./${NAME} 96 88 73 25 79 4 97 7 16 12 84 52 31 71 70 99 11 17 87 66 62 33 34 6 15 21 94 77 48 92 20 60 69 9 24 40 85 61 63 82 55 91 14 5 26 28 75 3 67 22 23 59 58 86 45 10 90 35 2 8 101 100 53 50 13 56 39 95 78 32 1 93 37 51 80 29 57 36 18 64 27 68 42 44 54 0 98 72 38 76 49 19 30 74 47 43 81 83 89 65 41
TEST4 = ./${NAME} 31 19 26 4 18 12 63 23 22 100 14 87 44 74 77 86 53 33 29 46 41 34 16 60 58 3 62 28 43 97 21 66 57 90 98 42 6 50 52 24 79 88 38 45 55 92 83 40 9 80 32 71 82 93 54 85 17 70 94 49 10 47 76 78 68 65 7 56 48 64 36 39 95 81 96 84 75 35 8 1 61 51 91 89 72 69 2 59 67 99 73 5 27 20 13 37 11 30 15 25
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