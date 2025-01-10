/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgiampa <fgiampa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:49:53 by fgiampa           #+#    #+#             */
/*   Updated: 2024/02/23 19:34:51 by fgiampa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	destlen;
	size_t	srclen;

	if ((!dst || !src) && size == 0)
		return (0);
	i = 0;
	j = 0;
	srclen = ft_strlen(src);
	destlen = ft_strlen(dst);
	j = destlen;
	if (destlen < size - 1 && size > 0)
	{
		while (src[i] && destlen + i < size - 1)
		{
			dst[j] = src[i];
			i++;
			j++;
		}
		dst[j] = 0;
	}
	if (destlen >= size)
		destlen = size;
	return (destlen + srclen);
}
