/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgiampa <fgiampa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:50:42 by fgiampa           #+#    #+#             */
/*   Updated: 2024/02/23 19:31:43 by fgiampa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	unsigned int	j;

	if (!s2[0])
		return ((char *)s1);
	if (!s1 && n == 0)
		return (NULL);
	i = 0;
	while (s1[i] && i < n)
	{
		j = 0;
		while (s1[j + i] == s2[j] && s2[j] && s1[j + i] && j + i < n)
			j++;
		if (s2[j] == 0)
			return ((char *)(s1 + i));
		i++;
	}
	return (NULL);
}
