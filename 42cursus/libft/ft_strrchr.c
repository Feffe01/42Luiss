/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgiampa <fgiampa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:50:54 by fgiampa           #+#    #+#             */
/*   Updated: 2024/10/15 20:19:29 by fgiampa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*f;

	f = s;
	while (*f)
		f++;
	while (f != s - 1)
	{
		if (*f == (char)c)
			return ((char *) f);
		f--;
	}
	return (NULL);
}
