#include "../../include/main.h"
#include "../../include/excute.h"

int	g_exit_code;

void	built_in_exe(t_minishell *m, t_pipe *p, char *cmd)
{
	if (ft_strcmp(cmd, "echo") == 0)
		echo(m, p);
	if (ft_strcmp(cmd, "export") == 0)
		export(m, p);
	if (ft_strcmp(cmd, "env") == 0)
		env(m);
	if (ft_strcmp(cmd, "pwd") == 0)
		pwd();
	if (ft_strcmp(cmd, "unset") == 0)
		unset(m, p);
	if (ft_strcmp(cmd, "cd") == 0)
		cd(m, p);
	if (ft_strcmp(cmd, "exit") == 0)
		ft_exit(p);
}

void	exe(t_minishell *m, t_pipe *p)
{
	t_cmd	*t;

	t = p->cmd_head->next;
	while (t)
	{
		if (ft_strcmp(t->str, "echo") == 0 || ft_strcmp(t->str, "cd") == 0 \
		|| ft_strcmp(t->str, "env") == 0 || ft_strcmp(t->str, "exit") == 0 \
		|| ft_strcmp(t->str, "export") == 0 || ft_strcmp(t->str, "pwd") == 0 \
		|| ft_strcmp(t->str, "unset") == 0)
		{
			built_in_exe(m, p, t->str);
			exit(g_exit_code);
		}
		else
			ft_execve(m, p);
		t = t->next;
	}
}
