#include "philo.h"

void	take_fork_ts(philo_node *p)
{
	struct timeval	time;
	long						timestamp_ms;

	gettimeofday(&time, NULL);
	timestamp_ms = time.tv_sec * 1000 + time.tv_usec / 1000;
	printf("%ld %d has taken a fork\n", timestamp_ms, p->index);
}

void	is_eating_ts(philo_node *p)
{
	struct timeval	time;
	long						timestamp_ms;

	gettimeofday(&time, NULL);
	timestamp_ms = time.tv_sec * 1000 + time.tv_usec / 1000;
	printf("%ld %d is eating\n", timestamp_ms, p->index);
	pthread_mutex_lock(&(p->status_mutex));
	p->status = EATING;
	pthread_mutex_unlock(&(p->status_mutex));
}

void	is_sleeping_ts(philo_node *p)
{
	struct timeval	time;
	long						timestamp_ms;

	gettimeofday(&time, NULL);
	timestamp_ms = time.tv_sec * 1000 + time.tv_usec / 1000;
	printf("%ld %d is sleeping\n", timestamp_ms, p->index);
	pthread_mutex_lock(&(p->status_mutex));
	p->status = SLEEPING;
	pthread_mutex_unlock(&(p->status_mutex));
}

void	is_thinking_ts(philo_node *p)
{
	struct timeval	time;
	long						timestamp_ms;

	gettimeofday(&time, NULL);
	timestamp_ms = time.tv_sec * 1000 + time.tv_usec / 1000;
	printf("%ld %d is thinking\n", timestamp_ms, p->index);
	pthread_mutex_lock(&(p->status_mutex));
	p->status = THINKING;
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