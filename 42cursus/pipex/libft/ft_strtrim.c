/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgiampa <fgiampa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 17:01:47 by fgiampa           #+#    #+#             */
/*   Updated: 2024/02/16 17:01:47 by fgiampa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isincluded(char const *set, char c)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*strim;
	size_t	i;
	size_t	start;
	size_t	end;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && ft_isincluded(set, s1[start]))
		start++;
	end = ft_strlen(s1);
	while (start < end && ft_isincluded(set, s1[end - 1]))
		end--;
	strim = (char *)malloc(sizeof(*s1) * (end - start + 1));
	if (!strim)
		return (NULL);
	i = 0;
	while (start < end)
		strim[i++] = s1[start++];
	strim[i] = 0;
	return (strim);
}
