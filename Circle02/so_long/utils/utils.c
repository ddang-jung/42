/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjun <hyeonjun@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 10:05:42 by hyeonjun          #+#    #+#             */
/*   Updated: 2023/01/23 11:39:14 by hyeonjun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	error_handler(char *error_message)
{
	perror(error_message);
	exit(EXIT_FAILURE);
}

void	free_game(t_game *game)
{
	int	index;

	index = -1;
	while (game->board->map[++index] != NULL)
		free(game->board->map[index]);
	free(game->board->map);
	free(game->board);
	free(game->img);
}

size_t	ft_strslen(char **strs)
{
	size_t	len;

	len = 0;
	while (strs[len] != NULL)
		len++;
	return (len);
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
