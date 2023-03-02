/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjun <hyeonjun@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 10:07:06 by hyeonjun          #+#    #+#             */
/*   Updated: 2023/01/23 11:38:56 by hyeonjun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

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
