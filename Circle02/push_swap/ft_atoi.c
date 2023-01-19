/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjun <hyeonjun@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 22:59:53 by hyeonjun          #+#    #+#             */
/*   Updated: 2022/11/15 17:42:03 by hyeonjun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v' \
	|| c == '\f' || c == '\r' | c == ' ')
		return (1);
	return (0);
}

long long	ft_calculate(const char *str, long long sign)
{
	long long	res;

	res = 0;
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + ((*str - '0') * sign);
		str++;
	}
	if (res > 2147483647 || res < -2147483648)
		ft_error(5); // no int size
	if (*str != '\0')
		ft_error(6); // something remained
	return (res);
}

int	ft_atoi(const char *str)
{
	long long	sign;
	long long	res;

	sign = 1;
	res = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	if (*str == '\0')
		ft_error(7); // only sign or nothing
	return ((int)ft_calculate(str, sign));
}
