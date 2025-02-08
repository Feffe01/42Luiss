/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgiampa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 09:43:33 by fgiampa           #+#    #+#             */
/*   Updated: 2025/01/17 09:43:36 by fgiampa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_node **a, t_node **b)
{
	t_node	*temp;

	if (!*b)
		return ;
	temp = rm_first_node(b);
	add_node_start(a, temp);
	ft_printf("pa\n");
}

void	push_b(t_node **a, t_node **b)
{
	t_node	*temp;

	if (!*a)
		return ;
	temp = rm_first_node(a);
	add_node_start(b, temp);
	ft_printf("pb\n");
}
