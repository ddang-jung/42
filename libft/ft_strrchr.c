/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjun <hyeonjun@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 18:55:17 by hyeonjun          #+#    #+#             */
/*   Updated: 2022/07/19 21:14:47 by hyeonjun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	index;
	char	*ch_s;
	char	ch_c;

	index = ft_strlen(s);
	ch_s = (char *)s;
	ch_c = (char)c;
	if (ch_c == '\0')
		return (&ch_s[index]);
	while (index--)
	{
		if (ch_s[index] == ch_c)
			return (&ch_s[index]);
	}
	return (NULL);
}
