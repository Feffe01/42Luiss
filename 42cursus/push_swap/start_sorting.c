#include "push_swap.h"

t_node	*get_cheapest(t_node **lst)
{
	t_node	*cheap;
	t_node	*temp;

	temp = *lst;
	while(temp)
	{
		if (temp->cheapest)
			cheap = temp;
		temp = temp->next;
	}
	return (cheap);
}

void move_cheapest_a(t_node **a, t_node **b)
{
	t_node *cheap_a;
	t_node *target;

	cheap_a = get_cheapest(a);
	target = cheap_a->target;
	while(cheap_a->above_median == target->above_median
		&& cheap_a->prev && target->prev)
	{
		if(cheap_a->above_median)
			rotate_both(a, b);
		else
			rev_rotate_both(a, b);
	}
	while(cheap_a->prev)
	{
		if (cheap_a->above_median)
			rotate_a(a);
		else
			rev_rotate_a(a);
	}
	while(target->prev)
	{
		if (target->above_median)
			rotate_b(b);
		else
			rev_rotate_b(b);
	}
	push_b(a, b);
}

void move_cheapest_b(t_node **a, t_node **b)
{
	t_node *cheap_b;
	t_node *target;

	cheap_b = get_cheapest(b);
	target = cheap_b->target;
	while(cheap_b->above_median == target->above_median
		&& cheap_b->prev && target->prev)
	{
		if(cheap_b->above_median)
			rotate_both(a, b);
		else
			rev_rotate_both(a, b);
	}
	while(cheap_b->prev)
	{
		if (cheap_b->above_median)
			rotate_b(b);
		else
			rev_rotate_b(b);
	}
	while(target->prev)
	{
		if (target->above_median)
			rotate_a(a);
		else
			rev_rotate_a(a);
	}
	push_a(a, b);
}

void	min_on_top(t_node **a)
{
	t_node *min;

	min = find_min(a);
	while(min->prev)
	{
		if(min->above_median)
			rotate_a(a);
		else
			rev_rotate_a(a);
	}
}

void start_sorting(t_node **a, t_node **b)
{
	int	a_len;

	a_len = stack_size(*a);
	if(a_len-- > 3 && !is_ordered(a))
		push_b(a, b);
	if(a_len-- > 3 && !is_ordered(a))
		push_b(a, b);
	while(a_len-- > 3 && !is_ordered(a))
	{
		setup_nodes_a(a, b);
		move_cheapest_a(a, b);
	}
	sort_three_a(a);
	while(*b)
	{
		setup_nodes_b(a, b);
		move_cheapest_b(a, b);
	}
	min_on_top(a);
}