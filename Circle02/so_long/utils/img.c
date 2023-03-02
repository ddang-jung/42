/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjun <hyeonjun@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 10:10:02 by hyeonjun          #+#    #+#             */
/*   Updated: 2023/01/23 11:39:00 by hyeonjun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init_img(t_game *game)
{
	t_img	*init;

	init = (t_img *)malloc(sizeof(t_img));
	if (init == NULL)
		error_handler("Function Malloc Returned NULL.");
	init->wall = mlx_xfti(game->mlx, "./img/wall.xpm");
	init->empty = mlx_xfti(game->mlx, "./img/empty.xpm");
	init->coin = mlx_xfti(game->mlx, "./img/coin.xpm");
	init->player = mlx_xfti(game->mlx, "./img/player_R.xpm");
	init->exit = mlx_xfti(game->mlx, "./img/close.xpm");
	game->img = init;
}

void	put_img(t_game *game, char c, int x, int y)
{
	if (c == '1')
		mlx_pitw(game, game->img->wall, x, y);
	else if (c == '0')
		mlx_pitw(game, game->img->empty, x, y);
	else if (c == 'P')
		mlx_pitw(game, game->img->player, x, y);
	else if (c == 'C')
		mlx_pitw(game, game->img->coin, x, y);
	else if (c == 'E')
		mlx_pitw(game, game->img->exit, x, y);
	else
		exit_game(game);
}

void	draw_img(t_game *game)
{
	int		str_index;
	int		chr_index;
	char	c;

	str_index = -1;
	while (game->board->map[++str_index] != NULL)
	{
		chr_index = -1;
		while (game->board->map[str_index][++chr_index] != '\0')
		{
			c = game->board->map[str_index][chr_index];
			put_img(game, c, chr_index, str_index);
		}
	}
}
