# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyeonjun <hyeonjun@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/11 20:17:36 by hyeonjun          #+#    #+#              #
#    Updated: 2023/04/11 21:29:29 by hyeonjun         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = main.c init.c run.c routine.c utils.c

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

DEBUG = -g -fsanitize=thread

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