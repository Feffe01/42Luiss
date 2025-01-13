#include "push_swap.h"

t_node	*find_min(t_node **lst)
{
	t_node	*temp;
	t_node	*min;

	if(!(*lst))
		return NULL;
	temp = *lst;
	min = *lst;
	while (temp)
	{
		if(temp->nbr < min->nbr)
			min = temp;
		temp = temp->next;
	}
	return (min);
}

t_node	*find_max(t_node **lst)
{
	t_node	*temp;
	t_node	*max;

	if(!(*lst))
		return NULL;
	temp = *lst;
	max = *lst;
	while (temp)
	{
		if(temp->nbr > max->nbr)
			max = temp;
		temp = temp->next;
	}
	return (max);
}

void	sort_three_a(t_node **a)
{
	t_node *max;

	max = find_max(a);
	if (max == (*a))
		rotate_a(a);
	else if (max == (*a)->next)
		rev_rotate_a(a);
	if ((*a)->nbr > (*a)->next->nbr)
		swap_a(a);
}