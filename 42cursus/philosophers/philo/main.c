#include "philo.h"

void	*check_end_routine(void *first)
{
	int	c;

	while (1)
	{
		c = check_death(first);
		if (c)
			break;
		c = check_done(first);
		if (c)
			break;
		usleep(1000);
	}
	stop_simulation(first);
	return NULL;
}

// void	*philo_routine_even(void *philo)
// {
// 	philo_node			*p;

// 	p = (philo_node *)philo;
// 	while (p->num_meals > 0 || p->num_meals < 0)
// 	{
// 		p_sleep(philo);
// 		if (check_end(p))
// 			break ;
// 		is_thinking_ts(p);
// 		usleep(2000);
// 		if (check_end(p))
// 			break ;
// 		p_eat(philo);
// 		p->num_meals--;
// 		if (p->num_meals == 0)
// 			has_done_ts(p);
// 		if (check_end(p))
// 			break ;
// 	}
// 	return NULL;
// }

void	*philo_routine(void *philo)
{
	philo_node			*p;

	p = (philo_node *)philo;
	while (p->num_meals > 0 || p->num_meals < 0)
	{
		p_eat(philo);
		p->num_meals--;
		if (p->num_meals == 0)
			has_done_ts(p);
		if (check_end(p))
			break ;
		p_sleep(philo);
		if (check_end(p))
			break ;
		is_thinking_ts(p);
		usleep(1000);
		if (check_end(p))
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
		if(actual->index % 2 == 1)
			pthread_create(&threads[i], NULL, philo_routine, (void *)actual);
		actual = actual->next;
		i++;
	}
	usleep(1000);
	actual = data->fst_philo;
	i = 0;
	while (actual)
	{
		if(actual->index % 2 == 0)
			pthread_create(&threads[i], NULL, philo_routine, (void *)actual);
		actual = actual->next;
		i++;
	}
	pthread_create(&threads[i], NULL, check_end_routine, (void *)data->fst_philo);
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
	if (ft_atoi(argv[1]) < 1 || ft_atoi(argv[2]) < 0
			|| ft_atoi(argv[3]) < 0 || ft_atoi(argv[4]) < 0)
		return (1);
	if (argc == 6 && ft_atoi(argv[5]) < 1)
		return (1);
	initializer(argc, argv, &data);
	start_threads(&data);
	return (0);
}
