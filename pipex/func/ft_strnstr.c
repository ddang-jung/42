/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjun <hyeonjun@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 16:50:17 by hyeonjun          #+#    #+#             */
/*   Updated: 2022/12/29 18:57:26 by hyeonjun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	index;
	size_t	sub;
	char	*ch_haystack;

	index = 0;
	ch_haystack = (char *)haystack;
	if (needle[index] == '\0')
		return (ch_haystack);
	while (ch_haystack[index] && index < len)
	{
		sub = 0;
		while (ch_haystack[index + sub] == needle[sub] \
			&& ch_haystack[index + sub] && index + sub < len)
		{
			sub++;
			if (!needle[sub])
				return (&ch_haystack[index]);
		}
		index++;
	}
	return (NULL);
}
