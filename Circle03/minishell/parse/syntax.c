#include "../include/main.h"

int	check_only_space(char *line)
{
	size_t	blank;
	int		i;

	blank = 0;
	i = -1;
	while (line[++i])
	{
		if (line[i] == ' ')
			blank++;
	}
	if (ft_strlen(line) == blank)
		return (ERROR);
	return (0);
}

int	check_only_pipe(char *line)
{
	size_t	blank;
	size_t	pipe;
	int		i;

	blank = 0;
	pipe = 0;
	i = -1;
	while (line[++i])
	{
		if (line[i] == ' ')
			blank++;
		if (line[i] == '|')
			pipe++;
	}
	if (ft_strlen(line) == blank)
		return (ERROR);
	if (ft_strlen(line) == blank + pipe)
	{
		printf("syntax error near unexpected token '|'\n");
		return (ERROR);
	}
	return (0);
}

int	check_only_pipe2(char *line)
{
	char	flag;
	int		loc;
	int		i;

	flag = 0;
	loc = 0;
	i = -1;
	while (line[++i])
	{
		flag = check_quote(flag, line[i]);
		if (flag == 0 && line[i] == '|')
		{
			if (only_pipe(line, i, &loc) == ERROR)
				return (ERROR);
		}
	}
	if (only_pipe(line, i, &loc) == ERROR)
		return (ERROR);
	return (0);
}

int	check_unclosed_quote(char *line)
{
	char	flag;
	int		i;

	flag = 0;
	i = -1;
	while (line[++i])
		flag = check_quote(flag, line[i]);
	if (flag != 0)
	{
		printf("syntax error unclosed quote\n");
		return (ERROR);
	}
	return (0);
}

int	check_unexpected_token(char *line)
{
	char	flag;
	int		i;

	flag = 0;
	i = -1;
	while (line[++i])
	{
		flag = check_quote(flag, line[i]);
		if (flag == 0 \
		&& (line[i] == '\\' || line[i] == ';' \
		|| (line[i] == '|' && line[i + 1] == '|') \
		|| (line[i] == '>' && line[i + 1] == '>' && line[i + 2] == '>') \
		|| (line[i] == '<' && line[i + 1] == '<' && line[i + 2] == '<')))
		{
			printf("syntax error near unexpected token '%c'\n", line[i]);
			return (ERROR);
		}
	}
	return (0);
}
