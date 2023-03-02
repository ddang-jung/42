# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyeonjun <hyeonjun@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/16 16:20:44 by hyeonjun          #+#    #+#              #
#    Updated: 2023/01/23 12:10:38 by hyeonjun         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ---- NAME ---- #

NAME		= so_long

LIBFT		= ./libft/libft.a
LIBFTCC		= -L./libft -lft

MLX			=	./mlx/libmlx.a
MLXCC		=	-L./mlx -lmlx
MLX_FLAGS	=	-framework OpenGL -framework Appkit

CC = cc
CFLAGS = -Wall -Wextra -Werror $(DBGS)
DBGS = -fsanitize=address -g3

AR = ar
ARFLAG = ruc
RM = rm -rf

object_dir = ./objects

# ---- escape ---- #

DELINE = \033[K
CURSUP = \033[A

RESET = \033[0m
RESTINT = \033[22m

BOLD = \033[1m

MAGENTA = \033[35m
GREEN = \033[32m
RED = \033[31m

# ---- Mandatory ---- #

sources1 :=	

sources1 += ./so_long.c
sources1 += ./utils/check.c
sources1 += ./utils/img.c
sources1 += ./utils/init.c
sources1 += ./utils/play.c
sources1 += ./utils/utils.c
sources1 += ./utils/utils_mlx.c
sources1 += ./get_next_line/get_next_line.c
sources1 += ./get_next_line/get_next_line_utils.c

# ---- Elements ---- #

all_sources = $(sources1)

objects1 = $(sources1:.c=.o)
all_objects = $(objects1)

define objects_goal
$(addprefix $(object_dir)/, $(call $(if $(filter bonus, $(MAKECMDGOALS)), objects2, objects1))) 
endef

define react
$(if $(filter bonus, $(MAKECMDGOALS)), bonus, all)
endef

# ---- Command ---- #

.PHONY : all bonus clean fclean re

all : $(NAME)

$(NAME) : $(objects_goal) $(LIBFT) $(MLX)
	@$(CC) $(CFLAGS) -o $@ $(objects_goal) $(LIBFTCC) $(MLXCC) $(MLX_FLAGS)
	@echo "$(DELINE) $(MAGENTA)$@ $(RESET) is compiled $(GREEN)$(BOLD) OK ✅ $(RESET)"

$(object_dir)/%.o : %.c
	@#mkdir -p $(object_dir)
	@mkdir -p $(object_dir)/$(dir $^)
	@$(CC) $(CFLAGS) -c $^ -o $@
	@echo " $(MAGENTA)$(NAME) $(RESET)objects file compiling... $(DELINE)$(GREEN) $^ $(RESET)$(CURSUP)"

$(LIBFT) :
	@make -C ./libft all

$(MLX) :
	@make -C ./mlx all

clean :
	@$(RM) $(all_objects)
	@rm -rf $(object_dir)
	@make -C ./libft clean
	@make -C ./mlx clean
	@echo "$(RED) Delete$(BOLD) objects $(RESTINT)file $(RESET)"

fclean : clean
	@$(RM) $(NAME)
	@make -C ./libft fclean
	@make -C ./mlx clean
	@echo "$(RED) Delete$(BOLD) $(NAME) $(RESTINT)file $(RESET)"

re : fclean
	@make $(react)