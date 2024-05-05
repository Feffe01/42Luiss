/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgiampa <fgiampa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 16:59:54 by fgiampa           #+#    #+#             */
/*   Updated: 2024/02/16 16:59:54 by fgiampa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free(char **arr)
{
	size_t	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

size_t	ft_countwords(char const *s, char c)
{
	size_t	i;
	size_t	count;
	size_t	div;

	i = 0;
	count = 0;
	div = 1;
	while (s[i])
	{
		if (s[i] == c)
			div = 1;
		if (s[i] != c && div == 1)
		{
			div = 0;
			count++;
		}
		i++;
	}
	return (count);
}

char	*ft_allocateword(char const *s, size_t i, size_t wrd_len,
							char **arr)
{
	size_t	j;
	char	*wrd;

	wrd = (char *)malloc(sizeof (*wrd) * (wrd_len + 1));
	if (!wrd)
	{
		ft_free(arr);
		return (0);
	}
	wrd[wrd_len] = '\0';
	j = 0;
	while (j < wrd_len)
	{
		wrd[j] = s[i - wrd_len + j];
		j++;
	}
	return (wrd);
}

char	**ft_assignwords(char **arr, char const *s, char c)
{
	size_t	i;
	size_t	wrd_len;
	size_t	wrd_num;

	i = 0;
	wrd_num = 0;
	while (s[i])
	{
		wrd_len = 0;
		while (s[i] && s[i] == c)
			i++;
		while (s[i] && s[i] != c)
		{
			i++;
			wrd_len++;
		}
		if (wrd_len > 0)
			arr[wrd_num++] = ft_allocateword(s, i, wrd_len, arr);
	}
	arr[wrd_num] = 0;
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	size_t	num_wrds;

	if (!s)
		return (NULL);
	num_wrds = ft_countwords(s, c);
	arr = (char **)malloc(sizeof(char *) * (num_wrds + 1));
	if (!arr)
		return (NULL);
	ft_assignwords(arr, s, c);
	return (arr);
}
