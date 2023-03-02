/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjun <hyeonjun@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 16:43:14 by hyeonjun          #+#    #+#             */
/*   Updated: 2022/07/20 17:45:07 by hyeonjun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*uc_s1;
	unsigned char	*uc_s2;
	size_t			index;

	uc_s1 = (unsigned char *)s1;
	uc_s2 = (unsigned char *)s2;
	index = 0;
	while (index < n)
	{
		if (uc_s1[index] != uc_s2[index])
			return (uc_s1[index] - uc_s2[index]);
		index++;
	}
	return (0);
}
