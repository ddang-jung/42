#include "../include/main.h"

int	g_exit_code;

char	*get_env(char *str, int *i, int *loc, t_env *env)
{
	char	*get;
	char	*sub;

	*i += 1;
	*loc = *i;
	if (str[*i] == '?')
	{
		*loc = *i + 1;
		get = ft_itoa(g_exit_code);
		return (get);
	}
	while (ft_isalnum(str[*i]) || str[*i] == '_')
		*i += 1;
	if (*loc == *i)
		return (ft_strdup("$"));
	sub = ft_substr(str, *loc, (*i - *loc));
	*loc = *i;
	if (str[*i] == '$')
		*i -= 1;
	get = ft_getenv(sub, env);
	free(sub);
	if (get)
		return (ft_strdup(get));
	else
		return (ft_strdup(""));
}

char	*interpret_dollor(char *str, t_env *env)
{
	char	*temp;
	char	flag;
	int		loc;
	int		i;

	temp = NULL;
	flag = 0;
	loc = 0;
	i = -1;
	while (str[++i])
	{
		flag = check_quote(flag, str[i]);
		if (flag != '\'' && str[i] == '$')
		{
			temp = ft_strjoin3(temp, ft_substr(str, loc, (i - loc)));
			temp = ft_strjoin3(temp, get_env(str, &i, &loc, env));
		}
		if (i >= (int)ft_strlen(str))
			break ;
	}
	if (loc < i)
		temp = ft_strjoin3(temp, ft_substr(str, loc, (i - loc)));
	free(str);
	return (temp);
}

char	*delete_quote(char *temp, char *str, int *i, int *loc)
{
	char	flag;

	flag = str[*i];
	temp = ft_strjoin3(temp, ft_substr(str, *loc, (*i - *loc)));
	*i += 1;
	*loc = *i;
	while (str[*i] != flag && str[*i])
		*i += 1;
	temp = ft_strjoin3(temp, ft_substr(str, *loc, (*i - *loc)));
	*loc = *i + 1;
	return (temp);
}

char	*interpret_quote(char *str)
{
	char	*temp;
	int		loc;
	int		i;

	temp = NULL;
	loc = 0;
	i = -1;
	while (str[++i])
	{
		if (str[i] == '\'' || str[i] == '"')
			temp = delete_quote(temp, str, &i, &loc);
		if (i >= (int)ft_strlen(str))
			break ;
	}
	if (loc < i)
		temp = ft_strjoin3(temp, ft_substr(str, loc, (i - loc)));
	free(str);
	return (temp);
}

void	interpreter(t_cmd *head, t_env *env)
{
	t_cmd	*node;

	node = head->next;
	while (node != NULL)
	{
		if (ft_strchr(node->str, '$'))
			node->str = interpret_dollor(node->str, env);
		if (ft_strchr(node->str, '\'') || ft_strchr(node->str, '"'))
			node->str = interpret_quote(node->str);
		node = node->next;
	}
}
