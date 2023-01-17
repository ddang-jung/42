/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjun <hyeonjun@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 12:34:09 by hyeonjun          #+#    #+#             */
/*   Updated: 2022/12/29 18:57:21 by hyeonjun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

char	*ft_strndup(const char *s1, int n)
{
	char	*dup;
	int		index;

	dup = malloc(sizeof(char) * n + 1);
	if (!dup)
		return (NULL);
	index = 0;
	while (s1[index] && index < n)
	{
		dup[index] = s1[index];
		index++;
	}
	dup[index] = '\0';
	return (dup);
}
