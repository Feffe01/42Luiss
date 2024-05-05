/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgiampa <fgiampa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 16:02:36 by fgiampa           #+#    #+#             */
/*   Updated: 2024/04/22 16:02:36 by fgiampa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*s3;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	s3 = (char *)malloc(sizeof(*s1) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!s3)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		s3[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		s3[i++] = s2[j++];
	s3[i] = 0;
	free(s1);
	return (s3);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;
	size_t	i;

	if (count && size && count > (4294967295U / size))
		return (NULL);
	p = (void *)malloc(count * size);
	if (p != NULL)
	{
		i = 0;
		while (i < count * size)
		{
			*(char *)(p + i) = 0;
			i++;
		}
	}
	return (p);
}
