CC = c++
FLAGS =  -std=c++98 -Wall -Wextra -Werror
SRCS = main.cpp
OUT = out
OBJS = ${SRCS:.c=.o}

.c.o:
	${cc} ${FLAGS} -c $< -o ${<:.c=.o}

${OUT}: ${OBJS}
	${CC} ${FLAGS} ${OBJS} -o ${OUT}
all:
	${CC} ${FLAGS} ${OBJS} -o ${OUT}
clean:
	rm -rf ${OUT}
fclean : clean
re: fclean all