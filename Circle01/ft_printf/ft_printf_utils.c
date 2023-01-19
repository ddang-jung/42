/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjun <hyeonjun@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 18:44:12 by hyeonjun          #+#    #+#             */
/*   Updated: 2022/10/02 16:06:43 by hyeonjun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_ptr(void *ptr, int *count)
{
	unsigned long	ul_ptr;

	ul_ptr = (unsigned long)ptr;
	ft_putptr_base(ul_ptr, "0123456789abcdef", count);
}

void	ft_print_int(int nbr, int *count)
{
	ft_putnbr_base(nbr, "0123456789", count);
}

void	ft_print_unsignedint(unsigned int nbr, int *count)
{
	ft_putnbr_base(nbr, "0123456789", count);
}

void	ft_print_upperhex(unsigned int nbr, int *count)
{
	ft_putnbr_base(nbr, "0123456789ABCDEF", count);
}

void	ft_print_lowerhex(unsigned int nbr, int *count)
{
	ft_putnbr_base(nbr, "0123456789abcdef", count);
}
