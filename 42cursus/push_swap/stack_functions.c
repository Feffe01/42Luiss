#include "push_swap.h"

t_node *create_node(int nbr)
{
	t_node *node;

	node = (t_node *)malloc(sizeof(*node));
	if (!node)
		return (NULL);
	node->above_median = false;
	node->cheapest = false;
	node->index = -1;
	node->push_cost = -1;
	node->nbr = nbr;
	node->target = NULL;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

t_node *last_node(t_node *lst)
{
	while (lst)
	{
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

void add_node_end(t_node **lst, t_node *new)
{
	t_node *last;

	if (lst)
	{
		if (*lst)
		{
			last = last_node(*lst);
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

void add_node_start(t_node **lst, t_node *new)
{
	if (lst)
	{
		if (*lst)
		{
			new->next = *lst;
			new->prev = NULL;
			(*lst)->prev = new;
		}
		else
		{
			new->next = NULL;
			new->prev = NULL;
		}
		*lst = new;
	}
}

t_node *rm_last_node(t_node **lst)
{
	t_node *last;

	if (lst && *lst)
	{
		last = last_node(*lst);
		last->prev->next = NULL;
		last->prev = NULL;
		last->next = NULL;
		return (last);
	}
	return (NULL);
}

t_node *rm_first_node(t_node **lst)
{
	t_node *temp;

	if (lst && *lst)
	{
		temp = *lst;
		*lst = temp->next;
		if (*lst)
			(*lst)->prev = NULL;
		temp->prev = NULL;
		temp->next = NULL;
		return (temp);
	}
	return (NULL);
}

int stack_size(t_node *lst)
{
	int i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

void free_stack(t_node **lst)
{
	t_node *current;
	t_node *next;

	if (!lst)
		return;
	current = *lst;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*lst = NULL;
}