/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjun <hyeonjun@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 22:33:29 by hyeonjun          #+#    #+#             */
/*   Updated: 2022/07/19 16:22:30 by hyeonjun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		index;
	char	*ch_s;
	char	ch_c;

	index = 0;
	ch_s = (char *)s;
	ch_c = (char)c;
	while (ch_s[index])
	{
		if (ch_s[index] == ch_c)
			return (&ch_s[index]);
		index++;
	}
	if (ch_c == '\0')
		return (&ch_s[index]);
	else
		return (NULL);
}
