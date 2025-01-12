/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgiampa <fgiampa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 18:26:40 by fgiampa           #+#    #+#             */
/*   Updated: 2024/03/07 18:51:55 by fgiampa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdarg.h>

void	ft_format(const char *str, va_list *args, size_t *c)
{
	if (*str == 'c')
		ft_putchar_pf(va_arg(*args, int), c);
	else if (*str == 's')
		ft_putstr_pf(va_arg(*args, char *), c);
	else if (*str == 'p')
		ft_putptr_pf(va_arg(*args, unsigned long), "0123456789abcdef", c);
	else if (*str == 'd' || *str == 'i')
		ft_putnbr_pf(va_arg(*args, int), c);
	else if (*str == 'u')
		ft_putunsigned_pf(va_arg(*args, unsigned int), c);
	else if (*str == 'x')
		ft_putnbr_base_pf(va_arg(*args, unsigned int), "0123456789abcdef", c);
	else if (*str == 'X')
		ft_putnbr_base_pf(va_arg(*args, unsigned int), "0123456789ABCDEF", c);
	else if (*str == '%')
		ft_putchar_pf('%', c);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	size_t	c;

	if (!str)
		return (-1);
	c = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			ft_format(str, &args, &c);
		}
		else
			ft_putchar_pf(*str, &c);
		str++;
	}
	va_end(args);
	return (c);
}
