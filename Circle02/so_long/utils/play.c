/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjun <hyeonjun@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 10:12:22 by hyeonjun          #+#    #+#             */
/*   Updated: 2023/01/23 11:39:07 by hyeonjun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	exit_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	free_game(game);
	ft_putendl_fd("Program closed in a clean way.", 1);
	exit(EXIT_SUCCESS);
}

void	move_player(t_game *game, int key, int dx, int dy)
{
	char		c;

	if (key == KEY_A)
		game->img->player = mlx_xfti(game->mlx, "./img/player_L.xpm");
	if (key == KEY_D)
		game->img->player = mlx_xfti(game->mlx, "./img/player_R.xpm");
	c = game->board->map[game->loc[1] + dy][game->loc[0] + dx];
	if (c != '1')
	{
		ft_putnbr_fd(++game->cnt, 1);
		write(1, "\n", 1);
		if (game->loc[0] == game->exit[0] && game->loc[1] == game->exit[1])
			game->board->map[game->loc[1]][game->loc[0]] = 'E';
		else
			game->board->map[game->loc[1]][game->loc[0]] = '0';
		game->board->map[game->loc[1] + dy][game->loc[0] + dx] = 'P';
		game->loc[0] += dx;
		game->loc[1] += dy;
	}
	draw_img(game);
}

int	key_handler(int key, t_game *game)
{
	const int	dx[14] = {-1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	const int	dy[14] = {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1};
	char		c;

	if (key == KEY_W || key == KEY_S || key == KEY_A || key == KEY_D)
	{
		c = game->board->map[game->loc[1] + dy[key]][game->loc[0] + dx[key]];
		if (c == 'C')
		{
			game->board->coin--;
			if (game->board->coin == 0)
				game->img->exit = mlx_xfti(game->mlx, "./img/open.xpm");
		}
		else if (c == 'E')
		{
			if (game->board->coin == 0)
				exit_game(game);
		}
		move_player(game, key, dx[key], dy[key]);
	}
	else if (key == KEY_ESC)
		exit_game(game);
	else
		return (0);
	return (0);
}
