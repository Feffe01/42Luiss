/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgiampa <fgiampa@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 00:34:06 by fgiampa           #+#    #+#             */
/*   Updated: 2025/04/23 17:07:11 by fgiampa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	stop_simulation(void *first)
{
	t_philo	*actual;

	actual = (t_philo *)first;
	while (actual)
	{
		pthread_mutex_lock(&(actual->status_mutex));
		actual->stop_sim = 1;
		pthread_mutex_unlock(&(actual->status_mutex));
		actual = actual->next;
	}
}
