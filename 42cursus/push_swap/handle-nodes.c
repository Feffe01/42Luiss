/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle-nodes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgiampa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 09:58:05 by fgiampa           #+#    #+#             */
/*   Updated: 2025/01/17 09:58:10 by fgiampa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*create_node(int nbr)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(*node));
	if (!node)
		return (NULL);
	node->above_median = false;
	node->cheapest = false;
	node->index = -1;
	node->push_cost = LONG_MAX;
	node->nbr = nbr;
	node->target = NULL;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

void	add_node_end(t_node **lst, t_node *new)
{
	t_node	*last;

	if (lst)
	{
		if (*lst)
		{
			last = last_node(*lst);
			new->prev = last;
			new->next = NULL;
			last->next = new;
		}
		else
		{
			new->next = NULL;
			new->prev = NULL;
			*lst = new;
		}
	}
}

void	add_node_start(t_node **lst, t_node *new)
{
	if (lst)
	{
		if (*lst)
		{
			new->next = *lst;
			new->prev = NULL;
			(*lst)->prev = new;
		}
		else
		{
			new->next = NULL;
			new->prev = NULL;
		}
		*lst = new;
	}
}

t_node	*rm_last_node(t_node **lst)
{
	t_node	*last;

	if (lst && *lst)
	{
		last = last_node(*lst);
		last->prev->next = NULL;
		last->prev = NULL;
		last->next = NULL;
		return (last);
	}
	return (NULL);
}

t_node	*rm_first_node(t_node **lst)
{
	t_node	*temp;

	if (lst && *lst)
	{
		temp = *lst;
		*lst = temp->next;
		if (*lst)
			(*lst)->prev = NULL;
		temp->prev = NULL;
		temp->next = NULL;
		return (temp);
	}
	return (NULL);
}
