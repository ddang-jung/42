#include "../../include/main.h"
#include "../../include/excute.h"

int	g_exit_code;

static int	print_error(char *str, char *key, char *value)
{
	printf(" export: '%s' : not a valid identifier\n", str);
	g_exit_code = 1;
	free_key_value(key, value);
	return (1);
}

static void	print_export(t_minishell *m)
{
	t_env	*list;

	sorting_env(m);
	list = m->senv->next;
	while (list)
	{
		ft_putstr_fd("declare -x ", 1);
		ft_putstr_fd(list->all, 1);
		ft_putstr_fd("\n", 1);
		list = list->next;
	}
	g_exit_code = 0;
}

static int	check_error(char *str)
{
	char	*key;
	char	*value;
	int		i;

	key = init_key_and_value(str, 'k');
	value = init_key_and_value(str, 'v');
	if (ft_isalpha(str[0]) != 1 && str[0] != '_')
		return (print_error(str, key, value));
	i = 0;
	while (str[++i] != '=' && str[i])
	{
		if (ft_isalnum(str[i]) != 1)
			return (print_error(str, key, value));
	}
	if (str[i - 1] == ' ' && (str[i - 1] == ' ' && str[i + 1] == ' '))
		return (print_error(value, key, value));
	return (0);
}

static t_cmd	*init_position(t_pipe *p)
{
	t_cmd	*node;

	node = p->cmd_head->next;
	while (node)
	{
		if (ft_strcmp(node->str, "export") == 0)
			return (node->next);
		node = node->next;
	}
	return (NULL);
}

void	export(t_minishell *m, t_pipe *p)
{
	t_cmd	*node;

	node = init_position(p);
	if (node == NULL)
		print_export(m);
	while (node)
	{
		if (check_error(node->str) == 1)
		{
			node = node->next;
			continue ;
		}
		if (check_old_env(m, node->str) == 1)
			old_put_in_env(m, node->str);
		else
			new_put_in_env(m, node->str);
		node = node->next;
	}
}
