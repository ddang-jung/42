#include "../include/main.h"

int	g_exit_code;

int	check_syntax(char *line)
{
	if (check_only_space(line) == ERROR)
		return (ERROR);
	if (check_only_pipe(line) == ERROR \
	|| check_only_pipe2(line) == ERROR \
	|| check_unclosed_quote(line) == ERROR \
	|| check_unexpected_token(line) == ERROR)
	{
		g_exit_code = 258;
		return (ERROR);
	}
	return (0);
}

t_pipe	*new_pipe(char *str)
{
	t_pipe	*new;
	char	*trim;

	if (!str)
		critical_error("Function ft_substr() Error.");
	new = (t_pipe *)malloc(sizeof(t_pipe));
	if (!new)
		critical_error("Function malloc() Error.");
	trim = ft_strctrim(str, ' ');
	if (!trim)
		critical_error("Function ft_strctrim() Error.");
	free(str);
	new->redir_head = init_redir();
	new->cmd_head = init_cmd();
	new->pipe_cnt = 0;
	new->str = trim;
	new->next = NULL;
	return (new);
}

void	split_pipe(t_pipe *head, char *line)
{
	t_pipe	*node;
	char	flag;
	int		loc;
	int		i;

	node = head;
	flag = 0;
	loc = 0;
	i = -1;
	while (line[++i])
	{
		flag = check_quote(flag, line[i]);
		if (flag == 0 && line[i] == '|')
		{
			head->pipe_cnt++;
			node->next = new_pipe(ft_substr(line, loc, (i - loc)));
			node = node->next;
			loc = i + 1;
		}
	}
	node->next = new_pipe(ft_substr(line, loc, (i - loc)));
}

void	parse(t_minishell *minishell, t_env *env)
{
	t_pipe	*node;

	if (check_syntax(minishell->line) == ERROR)
	{
		g_exit_code = 258;
		return ;
	}
	split_pipe(minishell->head, minishell->line);
	node = minishell->head->next;
	while (node != NULL)
	{
		tokenizer(node->redir_head, node->cmd_head, node->str);
		interpreter(node->cmd_head, env);
		node = node->next;
	}
	g_exit_code = 0;
}
