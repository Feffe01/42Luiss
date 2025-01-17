/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgiampa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 09:32:34 by fgiampa           #+#    #+#             */
/*   Updated: 2025/01/17 09:32:36 by fgiampa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_exit(t_node **a, t_node **b)
{
	write(2, "Error\n", 6);
	free_stack(a);
	free_stack(b);
	exit(EXIT_FAILURE);
}

void	error_exit_all(t_node **a, char **str)
{
	int	i;

	write(2, "Error\n", 6);
	free_stack(a);
	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
	exit(EXIT_FAILURE);
}
