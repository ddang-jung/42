SRCS = main.c\
	./signal/signal.c\
	./init/init.c\
	./init/env.c\
	./parse/get.c\
	./parse/parse.c\
	./parse/token.c\
	./parse/utils.c\
	./parse/syntax.c\
	./parse/interpret.c\
	./execute/excute.c\
	./execute/excute_utils.c\
	./execute/excute_utils2.c\
	./execute/ft_execve.c\
	./execute/ft_execve_utils.c\
	./execute/heredoc.c\
	./execute/shell_built_in/ft_cd.c\
	./execute/shell_built_in/ft_cd_utils.c\
	./execute/shell_built_in/ft_echo.c\
	./execute/shell_built_in/ft_env.c\
	./execute/shell_built_in/ft_exe.c\
	./execute/shell_built_in/ft_export.c\
	./execute/shell_built_in/ft_export_util.c\
	./execute/shell_built_in/ft_export_util2.c\
	./execute/shell_built_in/ft_pwd.c\
	./execute/shell_built_in/ft_unset.c\
	./execute/shell_built_in/ft_unset_utils.c\
	./execute/shell_built_in/ft_exit.c\
	./free/free.c

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address

LIBFT = ./libft/libft.a
LIBFTCC	= -L./libft -lft

RM = rm -f
NAME = minishell
LREAD = -lreadline -L/opt/homebrew/opt/readline/include
RREAD = -I/opt/homebrew/opt/readline/include

#LREAD 	= -lreadline -L${HOME}/.brew/opt/readline/lib
#RREAD	= -I${HOME}/.brew/opt/readline/include

all : ${NAME}

${NAME} : ${OBJS} ${LIBFT}
	@CC ${CFLAGS} -I ./ ${LIBFTCC} ${LREAD} ${RREAD} ${OBJS} -o ${NAME}

%.o : %.c
	@CC ${CFLAGS} -I ./ ${RREAD} -o $@ -c $<

${LIBFT} :
	@make -C ./libft bonus

clean :
	@${RM} ${OBJS}
	@make -C ./libft clean

fclean : clean
	@${RM} ${NAME}
	@make -C ./libft fclean

re :
	make fclean
	make all

.PHONY : all clean fclean re bonus