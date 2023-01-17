/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjun <hyeonjun@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 16:39:33 by hyeonjun          #+#    #+#             */
/*   Updated: 2022/07/22 15:07:45 by hyeonjun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	unsigned int	index;
	unsigned char	uc_s;

	index = 0;
	while (s[index])
	{
		uc_s = (unsigned char)s[index];
		write(fd, &uc_s, 1);
		index++;
	}
	write(fd, "\n", 1);
}
