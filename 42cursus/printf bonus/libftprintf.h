/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgiampa <fgiampa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 18:22:03 by fgiampa           #+#    #+#             */
/*   Updated: 2024/03/06 18:22:03 by fgiampa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);

void	ft_putchar_pf(char c, size_t *count);

void	ft_putnbr_base_pf(unsigned long nbr, char *base, size_t *c);

void	ft_putnbr_pf(int n, size_t *c);

void	ft_putstr_pf(char *s, size_t *c);

void	ft_putunsigned_pf(unsigned int n, size_t *c);

#endif
