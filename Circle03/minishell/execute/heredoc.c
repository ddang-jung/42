#include "../include/main.h"
#include "../include/excute.h"

void	unlink_all(void)
{
	int		i;
	int		flag;
	char	*dest;

	i = 0;
	flag = 1;
	while (flag != -1)
	{
		dest = ft_strjoin2(ft_itoa(i), "temp");
		flag = unlink(dest);
		free(dest);
		i++;
	}
}

void	init_heredoc(t_pipe *np)
{
	t_redir	*node;
	char	*str;
	int		i;

	i = 0;
	node = np->redir_head->next;
	while (node)
	{
		if (node->type == HEREDOC)
		{
			str = ft_strjoin2(ft_itoa(i), "temp");
			heredoc(node->file, str);
			node->type = RID_IN;
			node->file = ft_strdup(str);
			free(str);
			i++;
		}
		node = node->next;
	}
}

void	init_excute_heredoc(t_minishell *m, t_excute *e)
{
	t_pipe	*np;

	e->out = -1;
	e->origin_in = dup(STDIN_FILENO);
	e->origin_out = dup(STDOUT_FILENO);
	np = m->head->next;
	while (np)
	{
		init_heredoc(np);
		np = np->next;
	}
}
