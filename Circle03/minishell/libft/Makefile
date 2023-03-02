# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junyoung <junyoung@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/18 15:14:41 by hyeonjun          #+#    #+#              #
#    Updated: 2023/02/03 09:07:00 by junyoung         ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

HEADER = libft.h

MAIN_SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c \
ft_strlcat.c ft_strncmp.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c \
ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c \
ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

BONUS_SRCS = ft_lstlast.c

MAIN_OBJS = $(MAIN_SRCS:.c=.o)

BONUS_OBJS = $(BONUS_SRCS:.c=.o)

CC = cc

FLAGS = -Werror -Wextra -Wall

ifdef BONUS_FLAG
	OBJS = $(MAIN_OBJS) $(BONUS_OBJS)
else
	OBJS = $(MAIN_OBJS)
endif

all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)

%.o : %.c
	@$(CC) -c $(FLAGS) $^ -o $@

bonus:
	make BONUS_FLAG=1 all

clean:
	@rm -f $(MAIN_OBJS) $(BONUS_OBJS)

fclean: clean
	@rm -f $(NAME)

re:
	@make fclean
	@make all

.PHONY: all bonus clean fclean re