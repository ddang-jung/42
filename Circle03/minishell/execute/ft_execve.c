#include "../include/main.h"
#include "../include/excute.h"

int	g_exit_code;

static void	print_error(char *str)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd(": command not found\n", 2);
	g_exit_code = 127;
	exit(127);
}

static char	**get_option(t_pipe *p)
{
	t_cmd	*node;
	char	**dest;
	int		i;

	node = p->cmd_head->next;
	i = 0;
	while (node)
	{
		i++;
		node = node->next;
	}
	dest = (char **)malloc(sizeof(char *) * (i + 1));
	dest[i] = NULL;
	node = p->cmd_head->next;
	i = 0;
	while (node)
	{
		dest[i] = ft_strdup(node->str);
		node = node->next;
		i++;
	}
	return (dest);
}

char	**reverse_init_env(t_minishell *m)
{
	t_env	*env;
	char	**dest;
	int		i;

	env = m->env->next;
	i = 0;
	while (env)
	{
		i++;
		env = env->next;
	}
	env = m->env->next;
	dest = (char **)malloc(sizeof(char *) * (i + 1));
	dest[i] = NULL;
	i = -1;
	while (dest[++i] != NULL)
	{
		dest[i] = ft_strdup(env->all);
		env = env->next;
	}
	return (dest);
}

void	ft_execve(t_minishell *m, t_pipe *p)
{
	t_for_execve	cve;
	char			**env;

	cve.path = get_path(m);
	if (cve.path == NULL)
		print_error(p->cmd_head->next->str);
	cve.cmd = p->cmd_head->next->str;
	cve.cmd = check_path(cve.cmd, cve.path);
	if (cve.cmd == NULL)
		print_error(p->cmd_head->next->str);
	cve.option = get_option(p);
	env = reverse_init_env(m);
	execve(cve.cmd, cve.option, env);
}
