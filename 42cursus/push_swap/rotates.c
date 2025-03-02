/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotates.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgiampa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 09:44:24 by fgiampa           #+#    #+#             */
/*   Updated: 2025/01/17 09:44:27 by fgiampa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_node **lst)
{
	t_node	*temp;

	temp = rm_first_node(lst);
	add_node_end(lst, temp);
}

void	rotate_a(t_node **a)
{
	rotate(a);
	ft_printf("ra\n");
}

void	rotate_b(t_node **b)
{
	rotate(b);
	ft_printf("rb\n");
}

void	rotate_both(t_node **a, t_node **b)
{
	rotate(a);
	rotate(b);
	ft_printf("rr\n");
}
