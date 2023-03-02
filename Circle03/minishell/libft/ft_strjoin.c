/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjun <hyeonjun@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 15:28:46 by hyeonjun          #+#    #+#             */
/*   Updated: 2022/07/23 12:15:07 by hyeonjun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	index_j;
	size_t	index_s;
	char	*join;

	join = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!join)
		return (NULL);
	index_j = 0;
	index_s = 0;
	while (s1[index_s])
	{
		join[index_j] = s1[index_s];
		index_j++;
		index_s++;
	}
	index_s = 0;
	while (s2[index_s])
	{
		join[index_j] = s2[index_s];
		index_j++;
		index_s++;
	}
	join[index_j] = '\0';
	return (join);
}
