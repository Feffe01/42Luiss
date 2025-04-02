#include "philo.h"

int	check_death(philo_node *p)
{
	pthread_mutex_lock(&(p->status_mutex));
	if (p->stop_sim == 1 || p->status == DEAD)
	{
		pthread_mutex_unlock(&(p->status_mutex));
		return 0;
	}
	pthread_mutex_unlock(&(p->status_mutex));
	return 1;
}