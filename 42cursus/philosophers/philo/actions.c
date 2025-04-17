#include "philo.h"

void	take_fork_ts(philo_node *p)
{
	struct timeval	time;
	long						timestamp_ms;

	gettimeofday(&time, NULL);
	timestamp_ms = time.tv_sec * 1000 + time.tv_usec / 1000;
	pthread_mutex_lock(&(p->status_mutex));
	if (p->status != DEAD && p->stop_sim != 1)
		printf("%ld %d has taken a fork\n", timestamp_ms, p->index);
	pthread_mutex_unlock(&(p->status_mutex));
}

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
	pthread_mutex_lock(&(p->left_fork->mutex));
	take_fork_ts(p);
	if (!p->right_fork)
	{
		pthread_mutex_unlock(&(p->left_fork->mutex));
		usleep((p->time_die + 2) * 1000);
		return ;
	}
	pthread_mutex_lock(&(p->right_fork->mutex));
	take_fork_ts(p);
	is_eating_ts(p);
	usleep(p->time_eat * 1000);
	pthread_mutex_unlock(&(p->left_fork->mutex));
	pthread_mutex_unlock(&(p->right_fork->mutex));
	gettimeofday(&time, NULL);
	p->time_last_eat = time.tv_sec * 1000 + time.tv_usec / 1000;
}
