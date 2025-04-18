/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgiampa <fgiampa@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 00:30:55 by fgiampa           #+#    #+#             */
/*   Updated: 2025/04/18 00:57:49 by fgiampa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_end(t_philo *p)
{
	pthread_mutex_lock(&(p->status_mutex));
	if (p->stop_sim == 1 || p->status == DEAD)
	{
		pthread_mutex_unlock(&(p->status_mutex));
		return (1);
	}
	pthread_mutex_unlock(&(p->status_mutex));
	return (0);
}

int	check_death(void *first)
{
	t_philo			*actual;
	struct timeval	time;
	long			timestamp_ms;

	actual = (t_philo *)first;
	while (actual)
	{
		pthread_mutex_lock(&(actual->status_mutex));
		if (actual->status != EATING)
		{
			gettimeofday(&time, NULL);
			timestamp_ms = time.tv_sec * 1000 + time.tv_usec / 1000;
			if (timestamp_ms - actual->time_last_eat >= actual->time_die)
			{
				died_ts(actual);
				pthread_mutex_unlock(&(actual->status_mutex));
				return (1);
			}
		}
		pthread_mutex_unlock(&(actual->status_mutex));
		actual = actual->next;
	}
	return (0);
}

int	check_done(void *first)
{
	t_philo	*actual;

	actual = (t_philo *)first;
	while (actual)
	{
		pthread_mutex_lock(&(actual->status_mutex));
		if (actual->status != DONE)
		{
			pthread_mutex_unlock(&(actual->status_mutex));
			return (0);
		}
		pthread_mutex_unlock(&(actual->status_mutex));
		actual = actual->next;
	}
	return (1);
}
