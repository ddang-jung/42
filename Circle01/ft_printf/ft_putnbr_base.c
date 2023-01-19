/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjun <hyeonjun@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 12:00:36 by hyeonjun          #+#    #+#             */
/*   Updated: 2022/09/25 19:11:28 by hyeonjun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print(long long nbr, char *base, long long size, int *count)
{
	if (nbr < size)
		ft_putchar(base[nbr], count);
	else
	{
		ft_print(nbr / size, base, size, count);
		ft_print(nbr % size, base, size, count);
	}
}

long long	ft_checkbase(char *base)
{
	int		index;
	int		next;

	index = 0;
	while (base[index] != '\0')
	{
		next = index + 1;
		if (base[index] == '+' || base[index] == '-')
			return (0);
		while (base[next] != '\0')
		{
			if (base[index] == base[next])
				return (0);
			next++;
		}
		index++;
	}
	if (index < 2)
		return (0);
	return (index);
}

void	ft_putnbr_base(long long ll_nbr, char *base, int *count)
{
	long long	size;

	size = ft_checkbase(base);
	if (size != 0)
	{
		if (ll_nbr < 0)
		{
			ft_putchar('-', count);
			ll_nbr *= -1;
		}
		ft_print(ll_nbr, base, size, count);
	}
	return ;
}
