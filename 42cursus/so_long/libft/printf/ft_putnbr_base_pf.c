/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_pf.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgiampa <fgiampa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 18:21:40 by fgiampa           #+#    #+#             */
/*   Updated: 2024/03/06 18:21:40 by fgiampa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putcharofstring(char *str, int j, size_t *c)
{
	write(1, &str[j], 1);
	(*c)++;
}

size_t	ft_strlen_pf(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_putnbr_base_pf(unsigned long nbr, char *base, size_t *c)
{
	int	baselen;

	baselen = ft_strlen_pf(base);
	if (nbr / baselen != 0)
	{
		ft_putnbr_base_pf(nbr / baselen, base, c);
		ft_putcharofstring(base, nbr % baselen, c);
	}
	else if (nbr / baselen == 0)
		ft_putcharofstring(base, nbr % baselen, c);
}
