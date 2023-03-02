#include "../include/main.h"

char	check_quote(char flag, char c)
{
	if (c == '\'' || c == '"')
	{
		if (flag == 0)
			return (c);
		else
		{
			if (flag == c)
				return (0);
			else
				return (flag);
		}
	}
	return (flag);
}

int	only_pipe(char *line, int i, int *loc)
{
	while (*loc < i)
	{
		if (line[*loc] != ' ')
			break ;
		*loc += 1;
	}
	if (*loc == i)
	{
		printf("syntax error near unexpected token '|'\n");
		return (ERROR);
	}
	*loc = i + 1;
	return (0);
}

char	*ft_getenv(char *sub, t_env *env)
{
	t_env	*node;

	node = env->next;
	while (node != NULL)
	{
		if (ft_strcmp(node->key, sub) == 0)
			return (node->val);
		node = node->next;
	}
	return (NULL);
}

char	*ft_strjoin3(char *s1, char *s2)
{
	char		*join;
	int			i;
	int			j;
	const char	*empty = "";

	if (!s1)
		s1 = (char *)empty;
	join = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!join)
		return (NULL);
	i = -1;
	while (s1[++i])
		join[i] = s1[i];
	if (s1 != empty)
		free(s1);
	j = -1;
	while (s2[++j])
		join[i + j] = s2[j];
	free(s2);
	join[i + j] = '\0';
	return (join);
}

char	*ft_strctrim(char const *s, char const c)
{
	char	*trim;
	size_t	index;
	size_t	end;

	if (!s)
		return (NULL);
	index = 0;
	end = ft_strlen(s);
	while (s[index] && s[index] == c)
		index++;
	while (s[end - 1] && s[end - 1] == c && end > index)
		end--;
	trim = (char *)malloc(sizeof(char) * (end - index + 1));
	if (!trim)
		return (NULL);
	ft_strlcpy(trim, &s[index], end - index + 1);
	return (trim);
}
