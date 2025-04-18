/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_forks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgiampa <fgiampa@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 00:31:09 by fgiampa           #+#    #+#             */
/*   Updated: 2025/04/18 00:50:55 by fgiampa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_fork_list(t_fork *forks)
{
	t_fork	*temp;

	while (forks)
	{
		temp = forks->next;
		pthread_mutex_destroy(&(forks->mutex));
		free(forks);
		forks = temp;
	}
}

t_fork	*find_fork(t_fork *lst, int index)
{
	while (lst)
	{
		if (lst->index == index)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

t_fork	*last_fork(t_fork *lst)
{
	while (lst)
	{
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

t_fork	*create_fork(int index)
{
	t_fork	*node;

	node = (t_fork *)malloc(sizeof(*node));
	if (!node)
		return (NULL);
	node->index = index;
	if (pthread_mutex_init(&(node->mutex), NULL) != 0)
	{
		free(node);
		return (NULL);
	}
	node->next = NULL;
	return (node);
}

void	add_fork(t_fork **lst, t_fork *new)
{
	t_fork	*last;

	if (lst)
	{
		if (*lst)
		{
			last = last_fork(*lst);
			last->next = new;
		}
		else
			*lst = new;
	}
}
