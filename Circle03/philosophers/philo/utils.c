/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjun <hyeonjun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 20:17:44 by hyeonjun          #+#    #+#             */
/*   Updated: 2023/04/11 20:17:54 by hyeonjun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	error(char *msg)
{
	printf("%s\n", msg);
	return (ERROR);
}

int	ft_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v' \
	|| c == '\f' || c == '\r' || c == ' ')
		return (1);
	return (0);
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
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + ((*str - '0') * sign);
		str++;
	}
	if (res > 2147483647 || res < -2147483648)
		return (-1);
	return ((int)res);
}

long long	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	my_sleep(int time)
{
	long long	target;

	target = get_time() + (long long)time;
	while (target > get_time())
		usleep(200);
}
