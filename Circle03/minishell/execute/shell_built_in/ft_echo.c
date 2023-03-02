#include "../../include/excute.h"

static int	check_option(char *str)
{
	int	i;

	if (str[0] != '-')
		return (0);
	if (str[1] != 'n')
		return (0);
	i = 1;
	while (str[++i] != '\0')
	{
		if (str[i] != 'n')
			return (0);
	}
	return (1);
}

static t_cmd	*init_position(t_pipe *p)
{
	t_cmd	*node;

	node = p->cmd_head->next;
	while (node)
	{
		if (ft_strcmp(node->str, "echo") == 0)
			return (node->next);
		node = node->next;
	}
	return (NULL);
}

void	echo(t_minishell *m, t_pipe *p)
{
	int		flag;
	t_cmd	*node;

	(void)m;
	node = init_position(p);
	if (node == NULL || node->str[0] == '\0')
	{
		ft_putstr_fd("\n", 1);
		return ;
	}
	flag = 0;
	while (node && check_option(node->str) == 1)
	{
		flag = 1;
		node = node->next;
	}
	while (node)
	{
		ft_putstr_fd(node->str, 1);
		if (node->next)
			ft_putchar_fd(' ', 1);
		node = node->next;
	}
	if (flag == 0)
		ft_putchar_fd('\n', 1);
}
