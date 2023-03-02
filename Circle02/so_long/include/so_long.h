/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjun <hyeonjun@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 13:59:44 by hyeonjun          #+#    #+#             */
/*   Updated: 2023/01/23 11:36:41 by hyeonjun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../get_next_line/get_next_line.h"
# include "../libft/libft.h"
# include "../mlx/mlx.h"

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef enum e_keycode
{
	KEY_A = 0,
	KEY_S,
	KEY_D,
	KEY_W = 13,
	KEY_EXIT = 17,
	KEY_ESC = 53,
}	t_keycode;

typedef enum e_size
{
	WIDTH = 40,
	HEIGHT = 40,
}	t_size;

typedef enum e_status
{
	ERROR = -1,
}	t_status;

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

typedef struct s_img
{
	void	*wall;
	void	*empty;
	void	*coin;
	void	*player;
	void	*exit;
}	t_img;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	t_board	*board;
	t_img	*img;
	int		cnt;
	int		loc[2];
	int		exit[2];
}	t_game;

void	error_handler(char *error_message);
void	clear_board(t_board *board);
void	init_board(char *file, t_board *board);
void	map_check(t_board *board);
void	path_check(t_board *board);
void	location_finder(char **map, char c, int *loc);
void	init_img(t_game *game);
void	draw_img(t_game *game);
size_t	ft_strslen(char **strs);
void	*mlx_xfti(void *mlx, char *file);
void	mlx_pitw(t_game *game, void *img, int x, int y);
int		exit_game(t_game *game);
void	free_game(t_game *game);
int		key_handler(int key, t_game *game);

#endif