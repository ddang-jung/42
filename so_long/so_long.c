/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjun <hyeonjun@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 13:58:57 by hyeonjun          #+#    #+#             */
/*   Updated: 2023/01/17 17:21:12 by hyeonjun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long.h"

typedef struct s_copy
{
	char	**map;
	int		coin;
	int		exit;
}	t_copy;


typedef struct s_input
{
	char	**map;
	int		garo;
	int		sero;
	int		player;
	int		coin;
	int		exit;
	int		status;
}	t_input;

void	error_handler(char *error_message)
{
	perror(error_message);
	exit(EXIT_FAILURE);
}

void	clear_input(t_input *input)
{
	input->map = NULL;
	input->garo = 0;
	input->sero = 0;
	input->player = 0;
	input->coin = 0;
	input->exit = 0;
	input->status = 0;
}

void	get_input(char *file, t_input *input)
{
	int		fd;
	char	*line;
	char	*one_line_map;

	fd = open(file, O_RDONLY);
	if (fd == ERROR)
		error_handler("Function open() Returned Error Value.");
	one_line_map = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		one_line_map = ft_strjoin(one_line_map, line);
		if (one_line_map == NULL)
			error_handler("Function ft_strjoin() Returned Error Value.");
		free(line);
	}
	if (one_line_map == NULL)
		error_handler("Nothing in file?");
	input->map = ft_split(one_line_map, '\n');
}

size_t	ft_strslen(char **strs)
{
	size_t	len;

	len = 0;
	while (strs[len] != NULL)
		len++;
	return (len);
}

void	component_check(char c, t_input *input)
{
	if (c == '0' || c == '1' || c == 'P' || c == 'C' || c == 'E')
	{
		if (c == 'P')
			input->player++;
		if (c == 'C')
			input->coin++;
		if (c == 'E')
			input->exit++;
	}
	else
		error_handler("Map Contains Character Other than 0, 1, P, C, E.");
}

void	map_check(t_input *input)
{
	int		str_index;
	int		chr_index;

	input->garo = ft_strlen(*(input->map));
	input->sero = ft_strslen(input->map);
	if (input->garo == input->sero)
		error_handler("Map is Square.");
	str_index = -1;
	while (input->map[++str_index] != NULL)
	{
		chr_index = -1;
		while (input->map[str_index][++chr_index] != '\0')
		{
			component_check(input->map[str_index][chr_index], input);
			if (str_index == 0 || str_index == (input->sero - 1) \
			|| chr_index == 0 || chr_index == (input->garo - 1))
				if (input->map[str_index][chr_index] != '1')
					error_handler("There is a Hole in the Wall.");
		}
		if (input->garo != chr_index)
			error_handler("Map is Not Rectangular.");
	}
	if (input->player != 1 || input->coin < 1 || input->exit != 1)
		error_handler("Component Count Error.");
}

void	location_finder(char **map, char c, int *loc)
{
	int	str_index;
	int	chr_index;

	str_index = -1;
	while (map[++str_index] != NULL)
	{
		chr_index = -1;
		while (map[str_index][++chr_index] != '\0')
		{
			if (map[str_index][chr_index] == c)
			{
				loc[0] = chr_index;
				loc[1] = str_index;
			}
		}
	}
}

void	do_dfs(t_input *input, t_copy *copy, int x, int y)
{
	int			index;
	const int	dx[4] = {1, -1, 0, 0};
	const int	dy[4] = {0, 0, 1, -1};

	printf("%d %d %c %c\n", x, y, input->map[y][x], copy->map[y][x]);
	if (copy->map[y][x] == '1')
		return ;
	else
		copy->map[y][x] = '1';
	if (input->map[y][x] == '1')
		return ;
	else if (input->map[y][x] == 'C')
		copy->coin -= 1;
	else if (input->map[y][x] == 'E')
		copy->exit -= 1;
	printf("coin: %d exit: %d\n", copy->coin, copy->exit);
	if (copy->coin == 0 && copy->exit == 0)
		input->status = 1;
	index = -1;
	while (++index < 4)
		if (x + dx[index] < input->garo && y + dy[index] < input->sero)
			do_dfs(input, copy, x + dx[index], y + dy[index]);
}

void	path_check(t_input *input)
{
	t_copy	copy;
	int		loc[2];
	int		index;

	copy.map = (char **)malloc(sizeof(char *) * (input->sero + 1));
	if (copy.map == NULL)
		error_handler("Function Malloc Returned NULL.");
	index = -1;
	while (++index < input->sero)
		copy.map[index] = ft_strdup(input->map[index]);
	copy.map[index] = NULL;
	copy.coin = input->coin;
	copy.exit = input->exit;
	location_finder(input->map, 'P', loc);
	do_dfs(input, &copy, loc[0], loc[1]);
	if (input->status == 0)
		error_handler("There is No Available Path in This Map...");
	index = -1;
	while (++index < input->sero)
		free(copy.map[index]);
	free(copy.map);
}

void	valid_check(int argc, char **argv, t_input *input)
{
	if (argc != 2)
		error_handler("Invalid Number of Arguments!");
	if (argv[1] == NULL)
		error_handler("You Put NULL Argument!");
	if (ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])) == NULL)
		error_handler("You Should Put .ber File.");
	clear_input(input);
	get_input(argv[1], input);
	map_check(input);
	path_check(input);
}

int	main(int argc, char **argv)
{
	t_input	input;

	valid_check(argc, argv, &input);
	for (int i = 0; input.map[i] != NULL; i++)
		printf("%d %s\n", i + 1, input.map[i]);
	return (0);
}