# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyeonjun <hyeonjun@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/18 15:14:41 by hyeonjun          #+#    #+#              #
#    Updated: 2022/09/25 21:56:51 by hyeonjun         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

HEADER = ft_printf.h

MAIN_SRCS = ft_printf.c ft_printf_utils.c ft_putnbr_base.c ft_putptr_base.c

MAIN_OBJS = $(MAIN_SRCS:.c=.o)

BONUS_OBJS = $(BONUS_SRCS:.c=.o)

CC = cc

FLAGS = -Werror -Wextra -Wall

OBJS = $(MAIN_OBJS)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o : %.c
	$(CC) -c $(FLAGS) $^ -o $@

clean:
	rm -f $(MAIN_OBJS)

fclean: clean
	rm -f $(NAME)

re:
	@make fclean
	@make all

.PHONY: all clean fclean re