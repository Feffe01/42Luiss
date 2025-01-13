#include "push_swap.h"

void	set_targets_b(t_node **a, t_node **b)
{
	t_node	*n_a;
	t_node	*n_b;
	bool		target_found;

	if(!(*a) || !(*b))
		return ;
	n_b = *b;
	while (n_b)
	{
		n_b->target = NULL;
		n_a = *a;
		target_found = false;
		while (n_a)
		{
			if ((!n_b->target && n_b->nbr < n_a->nbr)
				|| (n_b->target && n_b->nbr < n_a->nbr
				&& n_a->nbr - n_b->nbr < n_b->target->nbr - n_b->nbr))
			{
				target_found = true;
				n_b->target = n_a;
			}
			n_a = n_a->next;
		}
		if (!target_found)
			n_b->target = find_min(a);
		n_b = n_b->next;
	}
}

void	setup_nodes_b(t_node **a, t_node **b)
{
	set_indexes(a);
	set_indexes(b);
	set_targets_b(a, b);
	calc_cost(b, a);
	set_cheapest(b);
}