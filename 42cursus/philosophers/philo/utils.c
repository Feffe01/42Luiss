#include "philo.h"

void	stop_simulation(void *first)
{
	philo_node *actual;

	actual = (philo_node *)first;
	while (actual)
	{
		actual->stop_sim = 1;
		actual = actual->next;
	}
}