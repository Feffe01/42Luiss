/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgiampa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 09:32:04 by fgiampa           #+#    #+#             */
/*   Updated: 2025/01/17 09:32:07 by fgiampa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_limits(int sign, long value, t_node **lst, char **argv)
{
	if (sign == 1 && value > INT_MAX)
		error_exit_all(lst, argv);
	if (sign == -1 && -(value) < INT_MIN)
		error_exit_all(lst, argv);
}

int	check_int_all(t_node **lst, char *str, char **argv)
{
	long		value;
	int			sign;
	size_t		i;

	value = 0;
	sign = 1;
	i = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (str[i] == '\0')
		error_exit(lst, NULL);
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]))
			error_exit_all(lst, argv);
		value = value * 10 + (str[i] - '0');
		check_limits(sign, value, lst, argv);
		i++;
	}
	return (sign * value);
}

int	check_int(t_node **lst, char *str)
{
	long		value;
	int			sign;
	size_t		i;

	value = 0;
	sign = 1;
	i = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (str[i] == '\0')
		error_exit(lst, NULL);
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]))
			error_exit(lst, NULL);
		value = value * 10 + (str[i] - '0');
		check_limits(sign, value, lst, NULL);
		i++;
	}
	return (sign * value);
}

void	check_duplicates(t_node **lst)
{
	t_node	*current;
	t_node	*temp;

	current = *lst;
	while (current->next)
	{
		temp = current->next;
		while (temp)
		{
			if (current->nbr == temp->nbr)
				error_exit(lst, NULL);
			temp = temp->next;
		}
		current = current->next;
	}
}

bool	is_ordered(t_node **lst)
{
	t_node	*current;

	current = *lst;
	while (current->next)
	{
		if (current->nbr > current->next->nbr)
			return (false);
		current = current->next;
	}
	return (true);
}
