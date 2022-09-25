/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjun <hyeonjun@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 12:00:36 by hyeonjun          #+#    #+#             */
/*   Updated: 2022/09/25 09:48:49 by hyeonjun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_base(unsigned long nbr, char *base, int size, int *count)
{
	if (nbr < size)
		ft_putchar(base[nbr], count);
	else
	{
		ft_print_base(nbr / size, base, size, count);
		ft_print_base(nbr % size, base, size, count);
	}
}

int	ft_checkbase(char *base)
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

void	ft_putnbr_base(unsigned long l_nbr, char *base, int *count)
{
	int		size;

	size = ft_checkbase(base);
	if (size != 0)
	{
		if (l_nbr < 0)
		{
			ft_putchar('-', count);
			l_nbr *= -1;
		}
		ft_print_base(l_nbr, base, size, count);
	}
	return ;
}
