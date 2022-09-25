/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjun <hyeonjun@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 09:13:45 by hyeonjun          #+#    #+#             */
/*   Updated: 2022/09/25 18:32:34 by hyeonjun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, int *count)
{
	write (1, &c, 1);
	(*count) += 1;
}

void	ft_print_str(char *str, int *count)
{
	while (*str)
	{
		ft_putchar(*str, count);
		str++;
	}
}

void	ft_convert(char conv, va_list ap, int *count)
{
	if (conv == 'c')
		return (ft_putchar(va_arg(ap, int), count));
	else if (conv == 's')
		return (ft_print_str(va_arg(ap, char *), count));
	else if (conv == 'p')
		return (ft_print_ptr(va_arg(ap, void *), count));
	else if (conv == 'd' || conv == 'i')
		return (ft_print_int(va_arg(ap, int), count));
	else if (conv == 'u')
		return (ft_print_unsignedint(va_arg(ap, unsigned int), count));
	else if (conv == 'X')
		return (ft_print_upperhex(va_arg(ap, unsigned int), count));
	else if (conv == 'x')
		return (ft_print_lowerhex(va_arg(ap, unsigned int), count));
	else if (conv == '%')
		return (ft_putchar('%', count));
	else
		return ;
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		index;
	int		count;

	va_start(ap, format);
	index = 0;
	count = 0;
	while (format[index])
	{
		if (format[index] == '%')
			ft_convert(format[++index], ap, &count);
		else
			ft_putchar(format[index], &count);
		index++;
	}
	va_end(ap);
	return (count);
}
