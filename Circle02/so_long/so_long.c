/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjun <hyeonjun@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 13:58:57 by hyeonjun          #+#    #+#             */
/*   Updated: 2023/01/18 19:32:51 by hyeonjun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long.h"

typedef struct s_copy
{
	char	**map;
	int		coin;
	int		exit;
}	t_copy;

typedef struct s_board
{
	char	**map;
	int		garo;
	int		sero;
	int		player;
	int		coin;
	int		exit;
	int		status;
}	t_board;

typedef struct s_player
{
	int		x;
	int		y;
	int		status;
	void	*img;
}	t_player

typedef struct s_exit
{
	int		x;
	int		y;
	int		status;
	void	*img;
	void	*open_img;
}	t_exit;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	void	*tile;
	void	*wall;
	void	*collect;
}	t_game;

void	error_handler(char *error_message)
{
	perror(error_message);
	exit(EXIT_FAILURE);
}

void	clear_board(t_board *board)
{
	board->map = NULL;
	board->garo = 0;
	board->sero = 0;
	board->player = 0;
	board->coin = 0;
	board->exit = 0;
	board->status = 0;
}

void	init_board(char *file, t_board *board)
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
	board->map = ft_split(one_line_map, '\n');
}

size_t	ft_strslen(char **strs)
{
	size_t	len;

	len = 0;
	while (strs[len] != NULL)
		len++;
	return (len);
}

void	component_check(char c, t_board *board)
{
	if (c == '0' || c == '1' || c == 'P' || c == 'C' || c == 'E')
	{
		if (c == 'P')
			board->player++;
		if (c == 'C')
			board->coin++;
		if (c == 'E')
			board->exit++;
	}
	else
		error_handler("Map Contains Character Other than 0, 1, P, C, E.");
}

void	map_check(t_board *board)
{
	int		str_index;
	int		chr_index;

	board->garo = ft_strlen(*(board->map));
	board->sero = ft_strslen(board->map);
	if (board->garo == board->sero)
		error_handler("Map is Square.");
	str_index = -1;
	while (board->map[++str_index] != NULL)
	{
		chr_index = -1;
		while (board->map[str_index][++chr_index] != '\0')
		{
			component_check(board->map[str_index][chr_index], board);
			if (str_index == 0 || str_index == (board->sero - 1) \
			|| chr_index == 0 || chr_index == (board->garo - 1))
				if (board->map[str_index][chr_index] != '1')
					error_handler("There is a Hole in the Wall.");
		}
		if (board->garo != chr_index)
			error_handler("Map is Not Rectangular.");
	}
	if (board->player != 1 || board->coin < 1 || board->exit != 1)
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

void	do_dfs(t_board *board, t_copy *copy, int x, int y)
{
	int			index;
	const int	dx[4] = {1, -1, 0, 0};
	const int	dy[4] = {0, 0, 1, -1};

	if (copy->map[y][x] == '1')
		return ;
	else
		copy->map[y][x] = '1';
	if (board->map[y][x] == '1')
		return ;
	else if (board->map[y][x] == 'C')
		copy->coin -= 1;
	else if (board->map[y][x] == 'E')
		copy->exit -= 1;
	if (copy->coin == 0 && copy->exit == 0)
		board->status = 1;
	index = -1;
	while (++index < 4)
		if (x + dx[index] < board->garo && y + dy[index] < board->sero)
			do_dfs(board, copy, x + dx[index], y + dy[index]);
}

void	path_check(t_board *board)
{
	t_copy	copy;
	int		loc[2];
	int		index;

	copy.map = (char **)malloc(sizeof(char *) * (board->sero + 1));
	if (copy.map == NULL)
		error_handler("Function Malloc Returned NULL.");
	index = -1;
	while (++index < board->sero)
		copy.map[index] = ft_strdup(board->map[index]);
	copy.map[index] = NULL;
	copy.coin = board->coin;
	copy.exit = board->exit;
	location_finder(board->map, 'P', loc);
	do_dfs(board, &copy, loc[0], loc[1]);
	if (board->status == 0)
		error_handler("There is No Available Path in This Map...");
	index = -1;
	while (++index < board->sero)
		free(copy.map[index]);
	free(copy.map);
}

void	valid_check(int argc, char **argv, t_board *board)
{
	if (argc != 2)
		error_handler("Invalid Number of Arguments!");
	if (argv[1] == NULL)
		error_handler("You Put NULL Argument!");
	if (ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])) == NULL)
		error_handler("You Should Put .ber File.");
	clear_board(board);
	init_board(argv[1], board);
	map_check(board);
	path_check(board);
}

void	init_game(t_board *board, t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, board->garo * WIDTH, board->sero * HEIGHT, "so_long");
}

int	main(int argc, char **argv)
{
	t_board	board;
	t_game	game;

	valid_check(argc, argv, &board);
	for (int i = 0; board.map[i] != NULL; i++)
		printf("%s\n", board.map[i]);
	init_game(&board, &game);
	return (0);
}