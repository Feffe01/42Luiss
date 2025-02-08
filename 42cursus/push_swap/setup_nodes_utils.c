/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_nodes_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgiampa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 09:52:14 by fgiampa           #+#    #+#             */
/*   Updated: 2025/01/17 09:52:23 by fgiampa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	calc_cost(t_node **lst1, t_node **lst2)
{
	t_node	*temp;

	if (!(*lst1) || !(*lst2))
		return ;
	temp = *lst1;
	while (temp)
	{
		temp->push_cost = temp->index;
		if (!(temp->above_median))
			temp->push_cost = stack_size(*lst1) - temp->index;
		if (temp->target->above_median)
			temp->push_cost += temp->target->index;
		else
			temp->push_cost += stack_size(*lst2) - temp->target->index;
		temp = temp->next;
	}
}

void	set_cheapest(t_node **lst)
{
	t_node	*temp;
	t_node	*cheap;

	if (!(*lst))
		return ;
	temp = *lst;
	cheap = *lst;
	cheap->cheapest = true;
	while (temp)
	{
		if (temp->push_cost < cheap->push_cost)
		{
			cheap->cheapest = false;
			cheap = temp;
			cheap->cheapest = true;
		}
		temp = temp->next;
	}
}

void	set_indexes(t_node **lst)
{
	t_node	*current;
	long	i;
	long	median;

	if (!(*lst))
		return ;
	current = *lst;
	i = 0;
	median = stack_size(*lst) / 2;
	while (current)
	{
		current->index = i;
		current->above_median = (i <= median);
		current = current->next;
		i++;
	}
}
