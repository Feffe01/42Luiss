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

	node = (philo_node *)malloc(sizeof(*node));
	if (!node)
		return (NULL);
	node->index = index;
	node->status = SLEEPING;
	node->num_philos = data->num_philos;
	node->time_die = data->time_die;
	node->time_from_eat = 0;
	node->time_eat = data->time_eat;
	node->time_sleep = data->time_sleep;
	node->num_meals = data->num_meals;
	node->actual_meal = 0;
	if(index - 1 < 1)
		node->right_fork = find_fork_node(*(data->forks), data->num_philos);
	else
		node->right_fork = find_fork_node(*(data->forks), index - 1);
	node->left_fork = find_fork_node(*(data->forks), index);
	node->prev = NULL;
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
			new->prev = last;
			new->next = NULL;
			last->next = new;
		}
		else
		{
			new->next = NULL;
			new->prev = NULL;
			*lst = new;
		}
	}
}
