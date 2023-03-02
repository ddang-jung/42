#include "../include/main.h"

int	get_type(char *str, int *i)
{
	int	type;

	if (str[*i] == str[*i + 1])
	{
		if (str[*i] == '<')
			type = HEREDOC;
		else
			type = APPEND;
		*i += 2;
	}
	else
	{
		if (str[*i] == '<')
			type = RID_IN;
		else
			type = RID_OUT;
		*i += 1;
	}
	return (type);
}

char	*get_file(char *str, int *i, int *loc)
{
	char	flag;

	flag = 0;
	while (str[*i] == ' ')
		*i += 1;
	*loc = *i;
	if (str[*i] == '\'' || str[*i] == '"')
	{
		flag = str[*i];
		*i += 1;
		while (str[*i] != flag)
			*i += 1;
	}
	else
		while (str[*i] != ' ' && str[*i])
			*i += 1;
	return (ft_substr(str, *loc, (*i - *loc)));
}
