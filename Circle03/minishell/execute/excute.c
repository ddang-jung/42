#include "../include/main.h"
#include "../include/excute.h"

int	g_exit_code;

int	init_rid(t_pipe *p, t_excute *e)
{
	t_redir	*t;
	int		return_value;

	if (!p->redir_head->next)
		return (0);
	t = p->redir_head->next;
	return_value = 0;
	while (t)
	{
		if (t->type == RID_IN)
			return_value = dir_in(e, t->file);
		if (t->type == RID_OUT)
			return_value = dir_out(e, t->file, '>');
		if (t->type == APPEND)
			return_value = dir_out(e, t->file, '+');
		t = t->next;
	}
	if (return_value)
		g_exit_code = 1;
	return (return_value);
}

void	redir_fork(t_minishell *m, t_pipe *p, t_excute *e)
{
	pid_t	pid;

	setting_signal(FORK);
	e->pipe = pipe(e->pipefd);
	pid = fork();
	if (e->pipe == -1 || pid == -1)
		critical_error("pipe_or_fork_fail");
	if (pid > 0)
	{
		parent_init_fork(e);
	}
	else
	{
		if (!p->cmd_head->next)
			exit(0);
		child_init_fork(e);
		exe(m, p);
	}
}

void	fork_last(t_minishell *m, t_pipe *p, t_excute *e)
{
	pid_t	pid;
	int		status;

	setting_signal(FORK);
	pid = fork();
	if (pid == -1)
		critical_error("fork_fail");
	if (pid > 0)
	{
		dup2(e->origin_in, STDIN_FILENO);
		dup2(e->origin_out, STDOUT_FILENO);
		close(e->origin_in);
		close(e->origin_out);
		waitpid(pid, &status, 0);
		if (g_exit_code != 130 && g_exit_code != 131)
			g_exit_code = status / 256;
	}
	else
	{
		if (!p->cmd_head->next)
			exit(0);
		exe(m, p);
	}
}

void	excute(t_minishell *m)
{
	t_pipe		*p;
	t_excute	e;
	int			i;

	i = 0;
	p = m->head->next;
	init_excute_heredoc(m, &e);
	if (check_built_or_execve(p, m->head->pipe_cnt) == 1)
		return (only_excute(m, p, &e));
	while (++i < m->head->pipe_cnt)
	{
		if (init_rid(p, &e) == 1)
			return ;
		redir_fork(m, p, &e);
		p = p->next;
	}
	if (init_rid(p, &e) == 1)
		return ;
	i = 0;
	while (++i < m->head->pipe_cnt)
		waitpid(-1, NULL, 0);
	fork_last(m, p, &e);
	unlink_all();
}
