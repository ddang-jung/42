#include "../include/excute.h"

int	dir_out(t_excute *e, char *file, int dir)
{
	if (dir == '>')
	{
		e->out = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (e->out < 0)
			return (open_error(file));
		dup2(e->out, STDOUT_FILENO);
		close(e->out);
	}
	if (dir == '+')
	{
		e->out = open(file, O_WRONLY | O_CREAT | O_APPEND, 0644);
		if (e->out < 0)
			return (open_error(file));
		dup2(e->out, STDOUT_FILENO);
		close(e->out);
	}
	return (0);
}

void	only_excute(t_minishell *m, t_pipe *p, t_excute *e)
{
	t_cmd	*n;

	n = p->cmd_head->next;
	init_rid(p, e);
	if (ft_strcmp(n->str, "echo") == 0 || ft_strcmp(n->str, "cd") == 0 \
	|| ft_strcmp(n->str, "env") == 0 || ft_strcmp(n->str, "exit") == 0 \
	|| ft_strcmp(n->str, "export") == 0 || ft_strcmp(n->str, "pwd") == 0 \
	|| ft_strcmp(n->str, "unset") == 0)
		built_in_exe(m, p, n->str);
	dup2(e->origin_in, STDIN_FILENO);
	dup2(e->origin_out, STDOUT_FILENO);
	close(e->origin_in);
	close(e->origin_out);
}

int	check_built_or_execve(t_pipe *p, int count)
{
	t_cmd	*n;

	if (!p->cmd_head->next)
		return (0);
	n = p->cmd_head->next;
	if ((ft_strcmp(n->str, "echo") == 0 || ft_strcmp(n->str, "cd") == 0 \
	|| ft_strcmp(n->str, "env") == 0 || ft_strcmp(n->str, "exit") == 0 \
	|| ft_strcmp(n->str, "export") == 0 || ft_strcmp(n->str, "pwd") == 0 \
	|| ft_strcmp(n->str, "unset") == 0) && count == 1)
		return (1);
	return (0);
}
