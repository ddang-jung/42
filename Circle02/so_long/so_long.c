/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjun <hyeonjun@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 13:58:57 by hyeonjun          #+#    #+#             */
/*   Updated: 2023/02/01 19:30:11 by hyeonjun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long.h"

void	valid_check(int argc, char **argv, t_game *game)
{
	t_board	*temp;

	if (argc != 2)
		error_handler("Invalid Number of Arguments!");
	if (argv[1] == NULL)
		error_handler("You Put NULL Argument!");
	if (ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])) == NULL)
		error_handler("You Should Put .ber File for Map.");
	temp = (t_board *)malloc(sizeof(t_board));
	if (temp == NULL)
		error_handler("Function malloc() Returned NULL.");
	clear_board(temp);
	init_board(argv[1], temp);
	map_check(temp);
	path_check(temp);
	game->board = temp;
}

void	init_game(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, (game->board->garo * WIDTH), (game->board->sero * HEIGHT), "so_long");
	game->cnt = 0;
	location_finder(game->board->map, 'P', game->loc);
	location_finder(game->board->map, 'E', game->exit);
	init_img(game);
	draw_img(game);
}

int	main(int argc, char **argv)
{
	t_game	game;

	valid_check(argc, argv, &game);
	init_game(&game);
	mlx_hook(game.win, KEY_D, 0, key_handler, &game);
	mlx_hook(game.win, KEY_EXIT, 0, exit_game, &game);
	mlx_loop(game.mlx);
	system("leaks ./so_long");
	return (0);
}
