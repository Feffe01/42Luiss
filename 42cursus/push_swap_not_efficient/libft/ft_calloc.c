/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgiampa <fgiampa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 18:26:58 by fgiampa           #+#    #+#             */
/*   Updated: 2024/02/27 17:10:15 by fgiampa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;

	if (count && size && count > (4294967295U / size))
		return (NULL);
	p = (void *)malloc(count * size);
	if (p != NULL)
		ft_bzero(p, count * size);
	return (p);
}
