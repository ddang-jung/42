/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjun <hyeonjun@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 13:59:44 by hyeonjun          #+#    #+#             */
/*   Updated: 2023/01/18 15:58:40 by hyeonjun         ###   ########.fr       */
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
	KEY_W = 13,
	KEY_A = 0,
	KEY_S,
	KEY_D,
	KEY_ESC = 53,
}	t_keycode;

typedef enum e_size
{
	WIDTH = 50,
	HEIGHT = 50,
}
typedef enum e_status
{
	ERROR = -1,
}	t_status;


#endif