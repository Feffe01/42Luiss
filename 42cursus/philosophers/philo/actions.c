/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgiampa <fgiampa@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 00:30:31 by fgiampa           #+#    #+#             */
/*   Updated: 2025/04/23 17:36:10 by fgiampa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_fork_ts(t_philo *p)
{
	struct timeval	time;
	long			timestamp_ms;

	if (check_end(p) == 0)
	{
		gettimeofday(&time, NULL);
		timestamp_ms = time.tv_sec * 1000 + time.tv_usec / 1000;
		printf("%ld %d has taken a fork\n", timestamp_ms, p->index);
	}
}

void	p_sleep(void *philo)
{
	t_philo			*p;

	p = (t_philo *)philo;
	is_sleeping_ts(p);
	usleep(p->time_sleep * 1000);
}

void	p_eat(void *philo)
{
	t_philo			*p;
	struct timeval	time;

	p = (t_philo *)philo;
	if (!p->right_fork)
	{
		usleep((p->time_die + 2) * 1000);
		return ;
	}
	pthread_mutex_lock(&(p->right_fork->mutex));
	take_fork_ts(p);
	pthread_mutex_lock(&(p->left_fork->mutex));
	take_fork_ts(p);
	is_eating_ts(p);
	usleep(p->time_eat * 1000);
	pthread_mutex_unlock(&(p->left_fork->mutex));
	pthread_mutex_unlock(&(p->right_fork->mutex));
	gettimeofday(&time, NULL);
	p->time_last_eat = time.tv_sec * 1000 + time.tv_usec / 1000;
}
