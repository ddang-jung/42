/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjun <hyeonjun@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 16:21:34 by hyeonjun          #+#    #+#             */
/*   Updated: 2022/07/21 13:15:33 by hyeonjun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t
	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_i;
	size_t	src_i;
	size_t	res;

	dst_i = 0;
	src_i = 0;
	res = 0;
	while (dst[dst_i] != '\0')
		dst_i++;
	while (src[res] != '\0')
		res++;
	if (dstsize < dst_i)
		res += dstsize;
	else
		res += dst_i;
	while (src[src_i] != '\0' && dst_i + 1 < dstsize)
	{
		dst[dst_i] = src[src_i];
		dst_i++;
		src_i++;
	}
	dst[dst_i] = '\0';
	return (res);
}
