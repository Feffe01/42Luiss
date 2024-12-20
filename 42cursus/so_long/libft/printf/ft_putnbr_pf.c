/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgiampa <fgiampa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 18:21:44 by fgiampa           #+#    #+#             */
/*   Updated: 2024/03/06 18:21:44 by fgiampa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putnbr_pf(int n, size_t *c)
{
	long	nbr;

	nbr = n;
	if (nbr < 0)
	{
		ft_putchar_pf('-', c);
		nbr = -nbr;
	}
	if (nbr > 9)
	{
		ft_putnbr_pf(nbr / 10, c);
		ft_putchar_pf((nbr % 10) + '0', c);
	}
	else
		ft_putchar_pf(nbr + '0', c);
}
