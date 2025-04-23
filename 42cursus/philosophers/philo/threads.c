/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgiampa <fgiampa@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 01:11:06 by fgiampa           #+#    #+#             */
/*   Updated: 2025/04/23 16:59:44 by fgiampa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*check_routine(void *first)
{
	while (1)
	{
		if (check_death(first))
			break ;
		if (check_done(first))
			break ;
		usleep(3000);
	}
	stop_simulation(first);
	return (NULL);
}

void	*philo_routine(void *philo)
{
	t_philo			*p;

	p = (t_philo *)philo;
	while (1)
	{
		p_eat(philo);
		pthread_mutex_lock(&(p->meals_mutex));
		if (p->num_meals > 0)
			p->num_meals--;
		pthread_mutex_unlock(&(p->meals_mutex));
		if (check_end(p))
			break ;
		p_sleep(philo);
		if (check_end(p))
			break ;
		is_thinking_ts(p);
		if (check_end(p))
			break ;
		usleep(1000);
	}
	return (NULL);
}

void	start_odd_threads(t_data *data, pthread_t *threads)
{
	t_philo	*actual;
	int		i;

	actual = data->fst_philo;
	i = 0;
	while (actual)
	{
		if (actual->index % 2 == 1)
			pthread_create(&threads[i], NULL, philo_routine, (void *)actual);
		actual = actual->next;
		i++;
	}
}

void	start_even_threads(t_data *data, pthread_t *threads)
{
	t_philo	*actual;
	int		i;

	actual = data->fst_philo;
	i = 0;
	while (actual)
	{
		if (actual->index % 2 == 0)
			pthread_create(&threads[i], NULL, philo_routine, (void *)actual);
		actual = actual->next;
		i++;
	}
}

void	start_threads(t_data *data)
{
	pthread_t	*threads;
	int			i;

	threads = malloc(sizeof(pthread_t) * (data->num_philos + 1));
	if (!threads)
		return ((void)printf("Memory allocation error!\n"));
	start_odd_threads(data, threads);
	usleep(1000);
	start_even_threads(data, threads);
	pthread_create(&threads[data->num_philos], NULL,
		check_routine, (void *)data->fst_philo);
	i = 0;
	while (i < data->num_philos + 1)
	{
		pthread_join(threads[i], NULL);
		i++;
	}
	free(threads);
}
