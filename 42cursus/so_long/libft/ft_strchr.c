/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgiampa <fgiampa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:49:31 by fgiampa           #+#    #+#             */
/*   Updated: 2024/10/15 19:29:06 by fgiampa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	const char	*f;

	f = s;
	while (*f)
	{
		if (*f == (char)c)
			return ((char *) f);
		f++;
	}
	if (*f == (char)c)
		return ((char *) f);
	return (NULL);
}
