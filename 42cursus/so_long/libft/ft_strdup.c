/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgiampa <fgiampa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 18:52:51 by fgiampa           #+#    #+#             */
/*   Updated: 2024/02/23 19:21:58 by fgiampa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*copy;
	size_t	l;

	l = ft_strlen(s1) + 1;
	copy = (char *)malloc(l * sizeof(*s1));
	if (!copy)
		return (NULL);
	ft_strlcpy((char *)copy, s1, l);
	return (copy);
}
