/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgiampa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 10:17:26 by fgiampa           #+#    #+#             */
/*   Updated: 2025/01/17 10:17:28 by fgiampa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_both(t_node *cheap, t_node *target, t_node **a, t_node **b)
{
	while (cheap->above_median == target->above_median
		&& cheap->prev && target->prev)
	{
		if (cheap->above_median)
			rotate_both(a, b);
		else
			rev_rotate_both(a, b);
	}
}

void	move_cheapest_a(t_node **a, t_node **b)
{
	t_node	*cheap_a;
	t_node	*target;

	cheap_a = get_cheapest(a);
	target = cheap_a->target;
	move_both(cheap_a, target, a, b);
	while (cheap_a->prev)
	{
		if (cheap_a->above_median)
			rotate_a(a);
		else
			rev_rotate_a(a);
	}
	while (target->prev)
	{
		if (target->above_median)
			rotate_b(b);
		else
			rev_rotate_b(b);
	}
	push_b(a, b);
}

void	move_cheapest_b(t_node **a, t_node **b)
{
	t_node	*cheap_b;
	t_node	*target;

	cheap_b = get_cheapest(b);
	target = cheap_b->target;
	move_both(cheap_b, target, a, b);
	while (cheap_b->prev)
	{
		if (cheap_b->above_median)
			rotate_b(b);
		else
			rev_rotate_b(b);
	}
	while (target->prev)
	{
		if (target->above_median)
			rotate_a(a);
		else
			rev_rotate_a(a);
	}
	push_a(a, b);
}

void	min_on_top(t_node **a)
{
	t_node	*min;

	min = find_min(a);
	while (min->prev)
	{
		if (min->above_median)
			rotate_a(a);
		else
			rev_rotate_a(a);
	}
}

void	start_sorting(t_node **a, t_node **b)
{
	int	a_len;

	a_len = stack_size(*a);
	if (a_len-- > 3 && !is_ordered(a))
		push_b(a, b);
	if (a_len-- > 3 && !is_ordered(a))
		push_b(a, b);
	while (a_len-- > 3 && !is_ordered(a))
	{
		setup_nodes_a(a, b);
		move_cheapest_a(a, b);
	}
	sort_three_a(a);
	while (*b)
	{
		setup_nodes_b(a, b);
		move_cheapest_b(a, b);
	}
	min_on_top(a);
}
