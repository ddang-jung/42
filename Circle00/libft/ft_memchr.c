/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjun <hyeonjun@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 16:26:00 by hyeonjun          #+#    #+#             */
/*   Updated: 2022/07/22 20:04:42 by hyeonjun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			index;
	unsigned char	*uc_s;

	uc_s = (unsigned char *)s;
	index = 0;
	while (index < n)
	{
		if (uc_s[index] == (unsigned char)c)
			return (&uc_s[index]);
		index++;
	}
	return (NULL);
}
