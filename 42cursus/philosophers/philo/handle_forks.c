#include "philo.h"

void	free_fork_list(fork_node *forks)
{
	fork_node *temp;
	while (forks)
	{
		temp = forks->next;
		pthread_mutex_destroy(&(forks->mutex));
		free(forks);
		forks = temp;
	}
}

fork_node	*find_fork_node(fork_node *lst, int index)
{
	while (lst)
	{
		if (lst->index == index)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

fork_node	*last_fork_node(fork_node *lst)
{
	while (lst)
	{
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

fork_node	*create_fork_node(int index)
{
	fork_node	*node;

	node = (fork_node *)malloc(sizeof(*node));
	if (!node)
		return (NULL);
	node->index = index;
	node->active = FALSE;
	if (pthread_mutex_init(&(node->mutex), NULL) != 0)
	{
		free(node);
		return (NULL);
	}
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

void	add_fork_node(fork_node **lst, fork_node *new)
{
	fork_node	*last;

	if (lst)
	{
		if (*lst)
		{
			last = last_fork_node(*lst);
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
