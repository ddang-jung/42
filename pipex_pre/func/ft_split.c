/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjun <hyeonjun@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 18:12:38 by hyeonjun          #+#    #+#             */
/*   Updated: 2022/12/29 18:57:06 by hyeonjun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static size_t	ft_cntword(const char *str, char c)
{
	size_t	cnt;
	size_t	flag;

	cnt = 0;
	flag = 0;
	while (*str != '\0')
	{
		if (*str != c && flag == 0)
		{
			flag = 1;
			cnt++;
		}
		else if (*str == c)
			flag = 0;
		str++;
	}
	return (cnt);
}

static size_t	ft_wordlen(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (*s != '\0' && *s != c)
	{
		len++;
		s++;
	}
	return (len);
}

static void	ft_free_str(char **s, int i)
{
	while (i--)
	{
		free(s[i]);
		s[i] = NULL;
	}
	free(s);
	s = NULL;
}

char	**ft_split(char const *s, char c)
{
	size_t	nb;
	size_t	cnt;
	char	**result;

	cnt = ft_cntword(s, c);
	result = (char **)malloc(sizeof(char *) * (cnt + 1));
	if (!result)
		return (NULL);
	nb = 0;
	while (nb < cnt)
	{
		while (*s != '\0' && *s == c)
			s++;
		result[nb] = ft_strndup(s, ft_wordlen(s, c));
		if (!result[nb])
		{
			ft_free_str(result, nb - 1);
			return (NULL);
		}
		s += ft_wordlen(s, c);
		nb++;
	}
	result[cnt] = NULL;
	return (result);
}
