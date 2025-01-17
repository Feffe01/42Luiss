/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_nodes_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgiampa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 09:50:03 by fgiampa           #+#    #+#             */
/*   Updated: 2025/01/17 09:50:05 by fgiampa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_targets_a(t_node **a, t_node **b)
{
	t_node	*n_a;
	t_node	*n_b;
	bool	target_found;

	n_a = *a;
	while (n_a)
	{
		n_a->target = NULL;
		n_b = *b;
		target_found = false;
		while (n_b)
		{
			if ((!n_a->target && n_a->nbr > n_b->nbr)
				|| (n_a->target && n_a->nbr > n_b->nbr
					&& n_a->nbr - n_b->nbr < n_a->nbr - n_a->target->nbr))
			{
				target_found = true;
				n_a->target = n_b;
			}
			n_b = n_b->next;
		}
		if (!target_found)
			n_a->target = find_max(b);
		n_a = n_a->next;
	}
}

void	setup_nodes_a(t_node **a, t_node **b)
{
	if (!(*a) || !(*b))
		return ;
	set_indexes(a);
	set_indexes(b);
	set_targets_a(a, b);
	calc_cost(a, b);
	set_cheapest(a);
}
