/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjun <hyeonjun@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 14:17:56 by hyeonjun          #+#    #+#             */
/*   Updated: 2022/07/19 20:02:02 by hyeonjun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			index;
	unsigned char	*uc_b;
	unsigned char	uc_c;

	index = 0;
	uc_b = (unsigned char *)b;
	uc_c = (unsigned char)c;
	while (index < len)
	{
		uc_b[index] = uc_c;
		index++;
	}
	return (uc_b);
}
