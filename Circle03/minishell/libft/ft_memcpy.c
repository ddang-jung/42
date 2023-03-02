/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjun <hyeonjun@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 17:37:00 by hyeonjun          #+#    #+#             */
/*   Updated: 2022/07/21 13:15:14 by hyeonjun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			index;
	unsigned char	*uc_dst;
	unsigned char	*uc_src;

	if (dst == NULL && src == NULL)
		return (NULL);
	index = 0;
	uc_dst = (unsigned char *)dst;
	uc_src = (unsigned char *)src;
	while (index < n)
	{
		uc_dst[index] = uc_src[index];
		index++;
	}
	return (uc_dst);
}
