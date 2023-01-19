/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjun <hyeonjun@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 18:20:24 by hyeonjun          #+#    #+#             */
/*   Updated: 2022/07/21 17:14:12 by hyeonjun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			index;
	unsigned char	*uc_src;

	if (!dst && !src)
		return (NULL);
	uc_src = (unsigned char *)src;
	if (dst < src)
	{
		index = 0;
		while (index < len)
		{
			((unsigned char *)dst)[index] = uc_src[index];
			index++;
		}
	}
	else
	{
		index = len;
		while (index)
		{
			((unsigned char *)dst)[index - 1] = uc_src[index - 1];
			index--;
		}
	}
	return (dst);
}
