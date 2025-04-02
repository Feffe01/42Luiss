#include "philo.h"

void	free_philo_list(philo_node *philos)
{
	philo_node *temp;
	while (philos)
	{
		temp = philos->next;
		free(philos);
		philos = temp;
	}
}

philo_node	*last_philo_node(philo_node *lst)
{
	while (lst)
	{
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

philo_node	*create_philo_node(int index, t_data *data)
{
	philo_node	*node;
	struct timeval	time;
	long						timestamp_ms;

	node = (philo_node *)malloc(sizeof(*node));
	if (!node)
		return (NULL);
	node->index = index;
	node->status = SLEEPING;
	node->num_philos = data->num_philos;
	node->time_die = data->time_die;
	gettimeofday(&time, NULL);
	timestamp_ms = time.tv_sec * 1000 + time.tv_usec / 1000;
	node->time_last_eat = timestamp_ms;
	node->time_eat = data->time_eat;
	node->time_sleep = data->time_sleep;
	node->num_meals = data->num_meals;
	node->stop_sim = 0;
	if (pthread_mutex_init(&(node->status_mutex), NULL) != 0)
	{
		free(node);
		return (NULL);
	}
	if(index - 1 < 1)
		node->right_fork = find_fork_node(data->fst_fork, data->num_philos);
	else
		node->right_fork = find_fork_node(data->fst_fork, index - 1);
	node->left_fork = find_fork_node(data->fst_fork, index);
	node->next = NULL;
	return (node);
}

void	add_philo_node(philo_node **lst, philo_node *new)
{
	philo_node	*last;

	if (lst)
	{
		if (*lst)
		{
			last = last_philo_node(*lst);
			last->next = new;
		}
		else
			*lst = new;
	}
}
