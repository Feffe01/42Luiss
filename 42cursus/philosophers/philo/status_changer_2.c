#include "philo.h"

void	has_done_ts(philo_node *p)
{
	struct timeval	time;
	long						timestamp_ms;

	gettimeofday(&time, NULL);
	timestamp_ms = time.tv_sec * 1000 + time.tv_usec / 1000;
	printf("%ld %d has done\n", timestamp_ms, p->index);
	pthread_mutex_lock(&(p->status_mutex));
	p->status = DONE;
	pthread_mutex_unlock(&(p->status_mutex));
}