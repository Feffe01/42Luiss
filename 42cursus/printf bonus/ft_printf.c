/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 18:26:40 by fgiampa           #+#    #+#             */
/*   Updated: 2024/03/10 16:07:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdarg.h>

void	ft_format(const char *str, size_t *x, size_t *c)
{
	if (*str == 'c')
		ft_putchar_pf((int)*x, c);
	else if (*str == 's')
		ft_putstr_pf((char *)*x, c);
	else if (*str == 'p')
	{
		ft_putstr_pf("0x", c);
		ft_putnbr_base_pf((unsigned long)*x, "0123456789abcdef", c);
	}
	else if (*str == 'd' || *str == 'i')
		ft_putnbr_pf((int)*x, c);
	else if (*str == 'u')
		ft_putunsigned_pf((unsigned int)*x, c);
	else if (*str == 'x')
		ft_putnbr_base_pf((unsigned int)*x, "0123456789abcdef", c);
	else if (*str == 'X')
		ft_putnbr_base_pf((unsigned int)*x, "0123456789ABCDEF", c);
	else if (*str == '%')
		ft_putchar_pf('%', c);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	size_t	c;
	size_t	*x;

	if (!str)
		return (-1);
	c = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			*x = va_arg(args, size_t);
			ft_format(str, x, &c);
		}
		else
			ft_putchar_pf(*str, &c);
		str++;
	}
	va_end(args);
	return (c);
}
