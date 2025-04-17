#include "philo.h"

void	stop_simulation(void *first)
{
	philo_node *actual;

	actual = (philo_node *)first;
	while (actual)
	{
		pthread_mutex_lock(&(actual->status_mutex));
		actual->stop_sim = 1;
		pthread_mutex_unlock(&(actual->status_mutex));
		actual = actual->next;
	}
}