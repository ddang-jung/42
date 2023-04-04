SRCS = main.c check.c init.c run.c philo.c clean.c utils.c

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror -g -fsanitize=thread

RM = rm -f

NAME = philo

all : ${NAME}

${NAME} : ${OBJS}
	@CC ${CFLAGS} ${OBJS} -o ${NAME}

%.o : %.c
	@CC ${CFLAGS} -o $@ -c $<

clean :
	@${RM} ${OBJS}

fclean : clean
	@${RM} ${NAME}

re :
	make fclean
	make all

.PHONY : all clean fclean re bonus