#include "philo.h"

void	is_eating_ts(philo_node *p)
{
	struct timeval	time;
	long						timestamp_ms;

	gettimeofday(&time, NULL);
	timestamp_ms = time.tv_sec * 1000 + time.tv_usec / 1000;
	pthread_mutex_lock(&(p->status_mutex));
	if (p->status != DEAD && p->stop_sim != 1)
	{
		printf("%ld %d is eating\n", timestamp_ms, p->index);
		if (p->status != DONE)
			p->status = EATING;
	}
	pthread_mutex_unlock(&(p->status_mutex));
}

void	is_sleeping_ts(philo_node *p)
{
	struct timeval	time;
	long						timestamp_ms;

	gettimeofday(&time, NULL);
	timestamp_ms = time.tv_sec * 1000 + time.tv_usec / 1000;
	pthread_mutex_lock(&(p->status_mutex));
	if (p->status != DEAD && p->stop_sim != 1)
		printf("%ld %d is sleeping\n", timestamp_ms, p->index);
	pthread_mutex_unlock(&(p->status_mutex));
}

void	is_thinking_ts(philo_node *p)
{
	struct timeval	time;
	long						timestamp_ms;

	gettimeofday(&time, NULL);
	timestamp_ms = time.tv_sec * 1000 + time.tv_usec / 1000;
	pthread_mutex_lock(&(p->status_mutex));
	if (p->status != DEAD && p->stop_sim != 1)
		printf("%ld %d is thinking\n", timestamp_ms, p->index);
	pthread_mutex_unlock(&(p->status_mutex));
}

void	died_ts(philo_node *p)
{
	struct timeval	time;
	long						timestamp_ms;

	gettimeofday(&time, NULL);
	timestamp_ms = time.tv_sec * 1000 + time.tv_usec / 1000;
	printf("%ld %d died\n", timestamp_ms, p->index);
	p->status = DEAD;
}

void	has_done_ts(philo_node *p)
{
	pthread_mutex_lock(&(p->status_mutex));
	if (p->status != DEAD)
		p->status = DONE;
	pthread_mutex_unlock(&(p->status_mutex));
}