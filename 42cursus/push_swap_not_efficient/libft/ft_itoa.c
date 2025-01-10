/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgiampa <fgiampa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 16:53:13 by fgiampa           #+#    #+#             */
/*   Updated: 2024/02/16 16:53:13 by fgiampa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_numlen(int n)
{
	int	len;

	len = 0;
	if (n < 0)
		len++;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

void	ft_normal_number(char *str, int n, int nlen)
{
	int	i;

	str[nlen] = 0;
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	i = nlen - 1;
	while (n != 0)
	{
		str[i] = n % 10 + '0';
		n /= 10;
		i--;
	}
}

char	*ft_itoa(int n)
{
	char	*str;
	int		nlen;

	nlen = ft_numlen(n);
	str = (char *)malloc(sizeof(char) * (nlen + 1));
	if (!str)
		return (NULL);
	if (n == 0)
		ft_strlcpy(str, "0", 2);
	else if (n == -2147483648)
		ft_strlcpy(str, "-2147483648", 12);
	else
		ft_normal_number(str, n, nlen);
	return (str);
}
