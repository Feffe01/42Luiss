/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned_pf.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgiampa <fgiampa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 18:21:52 by fgiampa           #+#    #+#             */
/*   Updated: 2024/03/06 18:21:52 by fgiampa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putunsigned_pf(unsigned int n, size_t *c)
{
	unsigned long	nbr;

	nbr = n;
	if (nbr > 9)
	{
		ft_putunsigned_pf(nbr / 10, c);
		ft_putchar_pf((nbr % 10) + '0', c);
	}
	else
		ft_putchar_pf(nbr + '0', c);
}
