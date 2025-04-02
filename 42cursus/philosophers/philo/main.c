#include "philo.h"

void	*death_routine(void *first)
{
	philo_node	*actual;
	struct timeval	time;
	long						timestamp_ms;
	int	c;

	c = 1;
	while (c == 1)
	{
		actual = (philo_node *)first;
		while (actual)
		{
			gettimeofday(&time, NULL);
			timestamp_ms = time.tv_sec * 1000 + time.tv_usec / 1000;
			if (timestamp_ms - actual->time_last_eat >= actual->time_die)
			{
				pthread_mutex_lock(&(actual->status_mutex));
				if(actual->status != EATING && actual->status != DONE)
				{
					died_ts(actual);
					stop_simulation(first);
				}
				pthread_mutex_unlock(&(actual->status_mutex));
				c = 0;
			}
			if (c == 0)
				break ;
			actual = actual->next;
		}
		usleep(1000);
	}
	return NULL;
}

void	*philo_routine_even(void *philo)
{
	philo_node			*p;

	p = (philo_node *)philo;
	while (p->num_meals > 0 || p->num_meals < 0)
	{
		p_sleep(philo);
		if (check_death(p))
			break ;
		is_thinking_ts(p);
		if (check_death(p))
			break ;
		p_eat(philo);
		if (check_death(p))
			break ;
		p->num_meals--;
		if (p->num_meals == 0)
		{
			has_done_ts(p);
			break ;
		}
	}
	return NULL;
}

void	*philo_routine_odd(void *philo)
{
	philo_node			*p;

	p = (philo_node *)philo;
	while (p->num_meals > 0 || p->num_meals < 0)
	{
		p_eat(philo);
		if (check_death(p))
			break ;
		p->num_meals--;
		if (p->num_meals == 0)
		{
			has_done_ts(p);
			break ;
		}
		p_sleep(philo);
		if (check_death(p))
			break ;
		is_thinking_ts(p);
		if (check_death(p))
			break ;
	}
	return NULL;
}

void	start_threads(t_data *data)
{
	pthread_t		*threads;
	philo_node		*actual;
	int				i;

	threads = malloc(sizeof(pthread_t) * (data->num_philos + 1));
	if (!threads)
	{
		printf("Memory allocation error!\n");
		return ;
	}
	actual = data->fst_philo;
	i = 0;
	while (actual)
	{
		if(actual->index % 2 == 0)
			pthread_create(&threads[i], NULL, philo_routine_even, (void *)actual);
		else
			pthread_create(&threads[i], NULL, philo_routine_odd, (void *)actual);
		actual = actual->next;
		i++;
	}
	pthread_create(&threads[i], NULL, death_routine, (void *)data->fst_philo);
	i = 0;
	while (i < data->num_philos + 1)
	{
		pthread_join(threads[i], NULL);
		i++;
	}
	free(threads);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc < 5 || argc > 6)
	{
		printf("Wrong number of arguments.\n");
		return (1);
	}
	initializer(argc, argv, &data);
	start_threads(&data);
	return (0);
}
