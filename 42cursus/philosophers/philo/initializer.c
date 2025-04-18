/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgiampa <fgiampa@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 00:31:30 by fgiampa           #+#    #+#             */
/*   Updated: 2025/04/18 00:57:38 by fgiampa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	initialize_forks(t_data *data, int num_philos)
{
	t_fork	*new_fork;
	int		i;

	i = 1;
	while (i <= num_philos)
	{
		new_fork = create_fork(i);
		add_fork(&(data->fst_fork), new_fork);
		i++;
	}
}

void	initialize_philos(t_data *data, int num_philos)
{
	t_philo	*new_philo;
	int		i;

	i = 1;
	while (i <= num_philos)
	{
		new_philo = create_philo(i, data);
		add_philo(&(data->fst_philo), new_philo);
		i++;
	}
}

void	initializer(int argc, char **argv, t_data *data)
{
	data->num_philos = ft_atoi(argv[1]);
	data->time_die = ft_atoi(argv[2]);
	data->time_eat = ft_atoi(argv[3]);
	data->time_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->num_meals = ft_atoi(argv[5]);
	else
		data->num_meals = -1;
	data->fst_fork = NULL;
	data->fst_philo = NULL;
	initialize_forks(data, data->num_philos);
	initialize_philos(data, data->num_philos);
}
