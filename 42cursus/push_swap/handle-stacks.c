/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle-stacks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgiampa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 09:58:19 by fgiampa           #+#    #+#             */
/*   Updated: 2025/01/17 09:58:22 by fgiampa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	stack_size(t_node *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

void	free_stack(t_node **lst)
{
	t_node	*current;
	t_node	*next;

	if (!lst)
		return ;
	current = *lst;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*lst = NULL;
}
