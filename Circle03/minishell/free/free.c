#include "../include/main.h"

void	free_cmd(t_cmd *head)
{
	t_cmd	*node;
	t_cmd	*temp;

	node = head->next;
	while (node != NULL)
	{
		temp = node->next;
		free(node->str);
		free(node);
		node = temp;
	}
}

void	free_redir(t_redir *head)
{
	t_redir	*node;
	t_redir	*temp;

	node = head->next;
	while (node != NULL)
	{
		temp = node->next;
		free(node->file);
		free(node);
		node = temp;
	}
}

void	free_line(t_minishell *minishell)
{
	t_pipe	*node;
	t_pipe	*temp;

	node = minishell->head->next;
	while (node != NULL)
	{
		temp = node->next;
		free_redir(node->redir_head);
		free(node->redir_head);
		free_cmd(node->cmd_head);
		free(node->cmd_head);
		free(node->str);
		free(node);
		node = temp;
	}
	minishell->head->pipe_cnt = 1;
	free(minishell->line);
}

void	free_env(t_env *head)
{
	t_env	*node;
	t_env	*temp;

	node = head;
	while (node != NULL)
	{
		temp = node->next;
		if (node->all != NULL)
			free(node->all);
		if (node->key != NULL)
			free(node->key);
		if (node->val != NULL)
			free(node->val);
		free(node);
		node = temp;
	}
}

void	free_all(t_minishell *minishell)
{
	free(minishell->head);
	free_env(minishell->env);
	free_env(minishell->senv);
}
