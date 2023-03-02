/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjun <hyeonjun@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 10:49:16 by hyeonjun          #+#    #+#             */
/*   Updated: 2023/01/23 11:39:10 by hyeonjun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	*mlx_xfti(void *mlx, char *file)
{
	int	wid;
	int	hei;

	return (mlx_xpm_file_to_image(mlx, file, &wid, &hei));
}

void	mlx_pitw(t_game *game, void *img, int x, int y)
{
	x *= WIDTH;
	y *= HEIGHT;

	mlx_put_image_to_window(game->mlx, game->win, img, x, y);
}
