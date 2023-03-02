#include "../include/main.h"

t_redir	*new_redir(int type, char *file)
{
	t_redir	*new;

	if (!file || !(*file))
		critical_error("No Filename After Redir.");
	new = (t_redir *)malloc(sizeof(t_redir));
	if (!new)
		critical_error("Fucntion malloc() Error.");
	new->type = type;
	new->file = file;
	new->next = NULL;
	return (new);
}

t_cmd	*new_cmd(char *str)
{
	t_cmd	*new;

	if (!str || !(*str))
		return (NULL);
	new = (t_cmd *)malloc(sizeof(t_cmd));
	if (!new)
		critical_error("Fucntion malloc() Error.");
	new->str = str;
	new->next = NULL;
	return (new);
}

t_redir	*make_new_redir(t_redir *node, char *str, int *i, int *loc)
{
	int		type;
	char	*file;

	type = get_type(str, i);
	file = get_file(str, i, loc);
	node->next = new_redir(type, file);
	*loc = *i;
	return (node->next);
}

t_cmd	*make_new_cmd(t_cmd *node, char *str, int *i, int *loc)
{
	char	*sub;

	if (*loc < *i)
	{
		sub = ft_substr(str, *loc, (*i - *loc));
		node->next = new_cmd(sub);
		node = node->next;
	}
	while (str[*i] == ' ')
		*i += 1;
	*loc = *i;
	*i -= 1;
	return (node);
}

void	tokenizer(t_redir *redir_head, t_cmd *cmd_head, char *str)
{
	t_redir	*redir_node;
	t_cmd	*cmd_node;
	char	flag;
	int		loc;
	int		i;

	redir_node = redir_head;
	cmd_node = cmd_head;
	flag = 0;
	loc = 0;
	i = -1;
	while (str[++i])
	{
		flag = check_quote(flag, str[i]);
		if (flag == 0 && (str[i] == '<' || str[i] == '>'))
			redir_node = make_new_redir(redir_node, str, &i, &loc);
		if (flag == 0 && str[i] == ' ')
			cmd_node = make_new_cmd(cmd_node, str, &i, &loc);
		if (i >= (int)ft_strlen(str))
			break ;
	}
	if (loc < i)
		cmd_node->next = new_cmd(ft_substr(str, loc, (i - loc)));
}
