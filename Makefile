CFLAGS := -Wall -Wextra -Werror

LIBFT := libft

LIBFTA := libcheck

BASE := list.c moves.c stacks.c utils.c moves_more.c stacks_more.c
SRC := ${BASE}
OBJ := $(SRC:.c=.o)

NAME := push_swap
BONUSNAME := checker

all: ${NAME}

${NAME}: ${OBJ} ${LIBFTA} push_swap.c
	@-cc -g ${CFLAGS} ${OBJ} push_swap.c -L ${LIBFT} -lft -o ${NAME}

${OBJ}: ${SRC}
	@- cc -g -c ${CFLAGS} ${SRC}

${LIBFTA}:
	@- ${MAKE} -C ${LIBFT} bonus clean
	touch ${LIBFTA}

bonus: ${BONUSNAME}

${BONUSNAME}: ${OBJ} ${LIBFTA} checker.c
	@-cc -g ${CFLAGS} ${OBJ} checker.c -L ${LIBFT} -lft -o ${BONUSNAME}


clean:
#@ ${MAKE} -C ${LIBFT} clean --- it s already cleaned after creating archive 
	@- rm -f ${OBJ} checker.o push_swap.o

fclean: clean
	@ ${MAKE} -C ${LIBFT} fclean
	rm -f ${NAME} ${LIBFTA} ${BONUSNAME}

re: fclean all bonus

val: all
	@valgrind -s --leak-check=yes --show-leak-kinds=all --track-origins=yes ${TEST}

fun: all
	@funcheck ${TEST}

.PHONY: all bonus clean fclean re val fun
