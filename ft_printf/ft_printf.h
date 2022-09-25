/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjun <hyeonjun@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 09:15:15 by hyeonjun          #+#    #+#             */
/*   Updated: 2022/09/25 18:32:54 by hyeonjun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

void	ft_putchar(char c, int *count);
int		ft_printf(const char *format, ...);
void	ft_putnbr_base(unsigned long l_nbr, char *base, int *count);

void	ft_print_ptr(void *ptr, int *count);
void	ft_print_int(int nbr, int *count);
void	ft_print_unsignedint(unsigned int nbr, int *count);
void	ft_print_upperhex(unsigned int nbr, int *count);
void	ft_print_lowerhex(unsigned int nbr, int *count);

#endif