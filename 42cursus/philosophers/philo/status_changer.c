/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status_changer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgiampa <fgiampa@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 00:33:54 by fgiampa           #+#    #+#             */
/*   Updated: 2025/04/23 17:21:12 by fgiampa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	is_eating_ts(t_philo *p)
{
	struct timeval	time;
	long			timestamp_ms;

	pthread_mutex_lock(&(p->status_mutex));
	if (p->status != DEAD && p->stop_sim != 1)
	{
		gettimeofday(&time, NULL);
		timestamp_ms = time.tv_sec * 1000 + time.tv_usec / 1000;
		printf("%ld %d is eating\n", timestamp_ms, p->index);
		p->status = EATING;
	}
	pthread_mutex_unlock(&(p->status_mutex));
}

void	is_sleeping_ts(t_philo *p)
{
	struct timeval	time;
	long			timestamp_ms;

	pthread_mutex_lock(&(p->status_mutex));
	gettimeofday(&time, NULL);
	timestamp_ms = time.tv_sec * 1000 + time.tv_usec / 1000;
	if (p->status != DEAD && p->stop_sim != 1)
	{
		p->status = SLEEPING;
		printf("%ld %d is sleeping\n", timestamp_ms, p->index);
	}
	pthread_mutex_unlock(&(p->status_mutex));
}

void	is_thinking_ts(t_philo *p)
{
	struct timeval	time;
	long			timestamp_ms;

	pthread_mutex_lock(&(p->status_mutex));
	gettimeofday(&time, NULL);
	timestamp_ms = time.tv_sec * 1000 + time.tv_usec / 1000;
	if (p->status != DEAD && p->stop_sim != 1)
	{
		p->status = THINKING;
		printf("%ld %d is thinking\n", timestamp_ms, p->index);
	}
	pthread_mutex_unlock(&(p->status_mutex));
}

void	died_ts(t_philo *p)
{
	struct timeval	time;
	long			timestamp_ms;

	gettimeofday(&time, NULL);
	timestamp_ms = time.tv_sec * 1000 + time.tv_usec / 1000;
	printf("%ld %d died\n", timestamp_ms, p->index);
	p->status = DEAD;
}
