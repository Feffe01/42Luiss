/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgiampa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 10:17:36 by fgiampa           #+#    #+#             */
/*   Updated: 2025/01/17 10:17:37 by fgiampa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_node **stack)
{
	t_node	*first;
	t_node	*second;

	first = rm_first_node(stack);
	second = rm_first_node(stack);
	add_node_start(stack, first);
	add_node_start(stack, second);
}

void	swap_a(t_node **a)
{
	if (!(*a)->next)
		return ;
	swap(a);
	ft_printf("sa\n");
}

void	swap_b(t_node **b)
{
	if (!(*b)->next)
		return ;
	swap(b);
	ft_printf("sb\n");
}

void	swap_both(t_node **a, t_node **b)
{
	if (!(*a)->next || !(*b)->next)
		return ;
	swap(a);
	swap(b);
	ft_printf("ss\n");
}
