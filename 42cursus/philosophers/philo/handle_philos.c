/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_philos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgiampa <fgiampa@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 00:31:20 by fgiampa           #+#    #+#             */
/*   Updated: 2025/04/23 16:58:02 by fgiampa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_philo_list(t_philo *philos)
{
	t_philo	*temp;

	while (philos)
	{
		temp = philos->next;
		pthread_mutex_destroy(&(philos->status_mutex));
		pthread_mutex_destroy(&(philos->meals_mutex));
		free(philos);
		philos = temp;
	}
}

t_philo	*last_philo(t_philo *lst)
{
	while (lst)
	{
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

void	assign_forks(t_philo *node, t_data *data)
{
	if (data->num_philos == 1)
		node->right_fork = NULL;
	else if (node->index == 1)
		node->right_fork = find_fork(data->fst_fork, data->num_philos);
	else
		node->right_fork = find_fork(data->fst_fork, node->index - 1);
	node->left_fork = find_fork(data->fst_fork, node->index);
}

t_philo	*create_philo(int index, t_data *data)
{
	t_philo			*node;
	struct timeval	time;

	node = (t_philo *)malloc(sizeof(*node));
	if (!node)
		return (NULL);
	if (pthread_mutex_init(&(node->status_mutex), NULL) != 0)
		return (free(node), NULL);
	if (pthread_mutex_init(&(node->meals_mutex), NULL) != 0)
		return (free(node), NULL);
	node->index = index;
	node->status = SLEEPING;
	node->num_philos = data->num_philos;
	node->time_die = data->time_die;
	gettimeofday(&time, NULL);
	node->time_last_eat = time.tv_sec * 1000 + time.tv_usec / 1000;
	node->time_eat = data->time_eat;
	node->time_sleep = data->time_sleep;
	node->num_meals = data->num_meals;
	node->stop_sim = 0;
	node->next = NULL;
	assign_forks(node, data);
	return (node);
}

void	add_philo(t_philo **lst, t_philo *new)
{
	t_philo		*last;

	if (lst)
	{
		if (*lst)
		{
			last = last_philo(*lst);
			last->next = new;
		}
		else
			*lst = new;
	}
}
