# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyeonjun <hyeonjun@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/16 16:20:44 by hyeonjun          #+#    #+#              #
#    Updated: 2023/01/16 16:21:18 by hyeonjun         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

FLAG = -Werror -Wextra -Wall

HEAD = ./include/

FUNC = ./func/

UTIL = ./utils/

SRCS = pipex.c $(FUNC)ft_split.c $(FUNC)ft_strjoin.c $(FUNC)ft_strlen.c $(FUNC)ft_strndup.c $(FUNC)ft_strnstr.c $(UTIL)utils.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o : %.c
	@$(CC) $(FLAG) -I $(HEAD) -o $@ -c $<

$(NAME): $(OBJS)
	@$(CC) $(FLAG) -I $(HEAD) $^ -o $@
	@echo "pipex is ready"

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re:
	@make fclean
	@make all

.PHONY: all bonus clean fclean re