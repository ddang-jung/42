/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjun <hyeonjun@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 21:26:25 by hyeonjun          #+#    #+#             */
/*   Updated: 2022/11/18 02:47:56 by hyeonjun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char		*join;
	int			i;
	int			j;
	const char	*empty = "";

	if (!s1)
		s1 = (char *)empty;
	join = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 2));
	if (!join)
		return (NULL);
	i = -1;
	while (s1[++i])
		join[i] = s1[i];
	if (s1 != empty)
		free(s1);
	j = -1;
	while (s2[++j])
		join[i + j] = s2[j];
	join[i + j] = ' ';
	join[i + j + 1] = '\0';
	return (join);
}
