#include "../../include/main.h"
#include "../../include/excute.h"

int	g_exit_code;

static void	print_error(char *str)
{
	ft_putstr_fd(" unset: \'", 1);
	ft_putstr_fd(str, 1);
	ft_putstr_fd("\':not a valid identifier\n", 1);
	g_exit_code = 1;
}

static int	check_error(char *src)
{
	int	i;

	if (src[0] != '_' && ft_isalpha(src[0]) != 1)
		return (1);
	i = 0;
	while (src[++i] != '\0')
		if (ft_isalnum(src[i]) != 1)
			return (1);
	return (0);
}

static t_cmd	*init_position(t_pipe *p)
{
	t_cmd	*node;

	node = p->cmd_head->next;
	while (node)
	{
		if (ft_strcmp(node->str, "unset") == 0)
			return (node->next);
		node = node->next;
	}
	return (NULL);
}

void	unset(t_minishell *m, t_pipe *p)
{
	t_cmd	*node;

	node = init_position(p);
	g_exit_code = 0;
	if (node == NULL)
		return ;
	while (node)
	{
		if (check_error(node->str) == 1)
			print_error(node->str);
		remove_unset_env(m, node->str);
		remove_unset_senv(m, node->str);
		node = node->next;
	}
}
