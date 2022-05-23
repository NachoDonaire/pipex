SRCS	=	pipex.c ft_split.c ft_calloc.c ft_memcpy.c \
			create_file.c pipex_utils.c ft_strnstr.c ft_strlen.c \
			gestor_ex.c
OBJS	=	${SRCS:.c=.c}
NAME	=	pipex
CC		=	gcc
RM		=	rm -f
CFLAGS	=	-Wall -Wextra -Werror 
.c.o:
	${CC} ${CFLAGS} -c ${SRCS}
all:	${NAME}
$(NAME):	${OBJS}
	${CC} ${CFLAGS} -o ${NAME} ${SRCS}
clean:
	${RM} ${OBJS}
fclean:
	${RM} ${NAME}
re: fclean all
.PHONY: all clean fclean re
re: fclean all
.PHONY: all clean fclean re
