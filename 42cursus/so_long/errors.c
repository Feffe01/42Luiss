/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgiampa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 17:49:04 by fgiampa           #+#    #+#             */
/*   Updated: 2024/12/28 17:49:06 by fgiampa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_filename(char *description)
{
	write(2, "\033[1;31mError\033[0m", 16);
	ft_printf("\nFile not valid: %s\n", description);
	exit(EXIT_FAILURE);
}

void	error_map(char *description)
{
	write(2, "\033[1;31mError\033[0m", 16);
	ft_printf("\nMap is not valid: %s\n", description);
	exit(EXIT_FAILURE);
}
