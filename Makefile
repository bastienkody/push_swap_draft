SRC_DIR = ./src/

SRCS =	${SRC_DIR}main.c\

OBJS =	${SRCS:.c=.o}

NAME =	push_swap

CC =	cc

CFLAGS =	-Wall -Wextra -Werror

LDFLAGS =	-L./libft -lft 

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all:	${NAME}

${NAME}:	${OBJS}
			make -C libft/
			${CC} -o ${NAME} ${OBJS} ${LDFLAGS}

clean:
		rm -rf ${OBJS}
		make clean -C libft/

fclean:		clean
		rm -rf ${NAME}
		make fclean -C libft/

re:		fclean all

.PHONY:	all clean bonus re
