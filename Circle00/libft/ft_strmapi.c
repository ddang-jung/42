/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjun <hyeonjun@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 14:56:49 by hyeonjun          #+#    #+#             */
/*   Updated: 2022/07/21 22:50:33 by hyeonjun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*map;
	unsigned int	index;

	map = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!map)
		return (NULL);
	index = 0;
	while (s[index])
	{
		map[index] = f(index, s[index]);
		index++;
	}
	map[index] = '\0';
	return (map);
}
