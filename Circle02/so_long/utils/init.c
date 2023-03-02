/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjun <hyeonjun@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 10:14:51 by hyeonjun          #+#    #+#             */
/*   Updated: 2023/01/23 11:39:04 by hyeonjun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

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
	free(one_line_map);
}
