/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjun <hyeonjun@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 18:09:41 by hyeonjun          #+#    #+#             */
/*   Updated: 2022/07/21 12:41:27 by hyeonjun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trim;
	size_t	index;
	size_t	end;

	if (!s1 && !set)
		return (NULL);
	index = 0;
	end = ft_strlen(s1);
	while (s1[index] && ft_strchr(set, s1[index]))
		index++;
	while (s1[end - 1] && ft_strchr(set, s1[end - 1]) && end > index)
		end--;
	trim = (char *)malloc(sizeof(char) * (end - index + 1));
	if (!trim)
		return (NULL);
	ft_strlcpy(trim, &s1[index], end - index + 1);
	return (trim);
}
