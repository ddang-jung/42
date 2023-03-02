#include "../../include/main.h"
#include "../../include/excute.h"

int	g_exit_code;

static t_cmd	*init_position(t_pipe *p)
{
	t_cmd	*node;

	node = p->cmd_head->next;
	while (node)
	{
		if (ft_strcmp(node->str, "exit") == 0)
			return (node->next);
		node = node->next;
	}
	return (NULL);
}

static int	check_error(char *str)
{
	int	i;

	i = -1;
	while (str[++i] != '\0')
	{
		if (ft_isdigit(str[i]) != 1 || str[i] != '-' || str[i] != '+')
			return (1);
	}
	return (0);
}

static void	exit_error(char *str)
{
	ft_putstr_fd("exit : ", 1);
	ft_putstr_fd(str, 1);
	ft_putstr_fd(": numeric argument required\n", 1);
	exit(255);
}

static void	print_all_error(void)
{
	ft_putstr_fd("exit\n", 1);
	ft_putstr_fd("minishell : exit: too many arguments\n", 1);
	g_exit_code = 1;
}

void	ft_exit(t_pipe *p)
{
	t_cmd	*token;

	token = init_position(p);
	if (token == NULL)
		exit(g_exit_code);
	if (token && token->next == NULL)
	{
		if (check_error(token->str) == 1)
			exit_error(token->str);
		ft_putstr_fd("exit\n", 1);
		exit(ft_atoi(token->str));
	}
	else
		return (print_all_error());
}
