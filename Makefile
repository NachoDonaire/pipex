SRCS	=	pipex.c ft_split.c ft_calloc.c ft_memcpy.c \
			create_file.c pipex_utils.c ft_strnstr.c ft_strlen.c \
			gestor_ex.c
OBJS	=	${SRCS:.c=.o}
NAME	=	pipex
CC		=	gcc
RM		=	rm -f
CFLAGS	=	-Wall -Wextra -Werror 
all:	${NAME}
$(NAME):	${OBJS}
	${CC} ${CFLAGS} -o ${NAME} ${OBJS}
clean:
	${RM} ${OBJS}
fclean: clean
	${RM} ${NAME}
re: fclean all
.PHONY: all clean fclean re
