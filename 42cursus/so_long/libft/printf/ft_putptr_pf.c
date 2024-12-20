/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgiampa <fgiampa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 18:57:28 by fgiampa           #+#    #+#             */
/*   Updated: 2024/03/12 19:49:51 by fgiampa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putptr_pf(unsigned long nbr, char *base, size_t *c)
{
	if (!nbr)
		ft_putstr_pf("(nil)", c);
	else
	{
		ft_putstr_pf("0x", c);
		ft_putnbr_base_pf(nbr, base, c);
	}
}
