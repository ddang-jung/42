/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjun <hyeonjun@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 12:00:36 by hyeonjun          #+#    #+#             */
/*   Updated: 2022/09/25 21:44:42 by hyeonjun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print2(unsigned long nbr, char *base, unsigned long size, int *count)
{
	if (nbr < size)
		ft_putchar(base[nbr], count);
	else
	{
		ft_print2(nbr / size, base, size, count);
		ft_print2(nbr % size, base, size, count);
	}
}

unsigned long	ft_checkbase2(char *base)
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

void	ft_putptr_base(unsigned long ul_nbr, char *base, int *count)
{
	unsigned long	size;

	size = ft_checkbase2(base);
	if (size != 0)
	{
		if (ul_nbr < 0)
		{
			ft_putchar('-', count);
			ul_nbr *= -1;
		}
		ft_print_str("0x", count);
		ft_print2(ul_nbr, base, size, count);
	}
	return ;
}
