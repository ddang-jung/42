/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjun <hyeonjun@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 21:52:52 by hyeonjun          #+#    #+#             */
/*   Updated: 2022/07/16 21:33:49 by hyeonjun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_len(int n)
{
	size_t	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

static int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	else
		return (n);
}

char	*ft_itoa(int n)
{
	char		*arr;

	arr = (char *)malloc(sizeof(char) * (get_len(n) + 1));
	if (!arr)
		return (NULL);
	if (n < 0)
		arr[0] = '-';
	if (n == 0)
		arr[0] = '0';
	arr[get_len(n)] = '\0';
	while (n != 0)
	{
		arr[get_len(n) - 1] = ft_abs(n % 10) + '0';
		n /= 10;
	}
	return (arr);
}
