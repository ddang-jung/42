#include "../include/main.h"

int	g_exit_code;

t_redir	*init_redir(void)
{
	t_redir	*init;

	init = (t_redir *)malloc(sizeof(t_redir));
	if (!init)
		critical_error("Function malloc() Error.");
	init->type = HEAD;
	init->file = NULL;
	init->next = NULL;
	return (init);
}

t_cmd	*init_cmd(void)
{
	t_cmd	*init;

	init = (t_cmd *)malloc(sizeof(t_cmd));
	if (!init)
		critical_error("Function malloc() Error.");
	init->str = NULL;
	init->next = NULL;
	return (init);
}

t_pipe	*init_pipe(void)
{
	t_pipe	*init;

	init = (t_pipe *)malloc(sizeof(t_pipe));
	if (!init)
		critical_error("Function malloc() Error.");
	init->pipe_cnt = 1;
	init->redir_head = NULL;
	init->cmd_head = NULL;
	init->next = NULL;
	return (init);
}

t_env	*init_env(void)
{
	t_env	*init;

	init = (t_env *)malloc(sizeof(t_env));
	if (!init)
		critical_error("Function malloc() Error.");
	init->all = NULL;
	init->key = NULL;
	init->next = NULL;
	init->val = NULL;
	return (init);
}

void	init(t_minishell *minishell, char **envp)
{
	minishell->head = init_pipe();
	minishell->env = init_env();
	minishell->senv = init_env();
	set_env(minishell, envp);
	minishell->line = NULL;
	g_exit_code = 0;
}
