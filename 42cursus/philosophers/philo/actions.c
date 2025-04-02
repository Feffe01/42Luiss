#include "philo.h"

void	p_sleep(void *philo)
{
	philo_node			*p;

	p = (philo_node *)philo;
	is_sleeping_ts(p);
	usleep(p->time_sleep * 1000);
}

void	p_eat(void *philo)
{
	philo_node			*p;
	struct timeval	time;

	p = (philo_node *)philo;
	pthread_mutex_lock(&(p->right_fork->mutex));
	take_fork_ts(p);
	pthread_mutex_lock(&(p->left_fork->mutex));
	take_fork_ts(p);
	is_eating_ts(p);
	usleep(p->time_eat * 1000);
	pthread_mutex_unlock(&(p->right_fork->mutex));
	pthread_mutex_unlock(&(p->left_fork->mutex));
	gettimeofday(&time, NULL);
	p->time_last_eat = time.tv_sec * 1000 + time.tv_usec / 1000;
}
