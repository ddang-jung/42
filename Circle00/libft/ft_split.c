/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjun <hyeonjun@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 18:12:38 by hyeonjun          #+#    #+#             */
/*   Updated: 2022/07/23 20:02:40 by hyeonjun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

static char	*ft_strndup(const char *s, size_t num)
{
	char	*word;
	char	*temp;

	word = (char *)malloc(sizeof(char) * (num + 1));
	if (!word)
		return (NULL);
	temp = word;
	while (num-- > 0)
		*temp++ = *s++;
	*temp = '\0';
	return (word);
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

	//s가 NULL이 들어오면 ft_cntword에서 s의 while문이 NULL포인터를 가리키며 seg fault 띄우므로 예외처리하기
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
