/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgiampa <fgiampa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 18:21:48 by fgiampa           #+#    #+#             */
/*   Updated: 2024/03/06 18:21:48 by fgiampa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putstr_pf(char *s, size_t *c)
{
	if (!s)
		ft_putstr_pf("(null)", c);
	else
	{
		while (*s)
		{
			ft_putchar_pf(*s, c);
			s++;
		}
	}
}
