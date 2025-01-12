#include "push_swap.h"

void rev_rotate(t_node **lst)
{
	t_node *temp;

	temp = rm_last_node(lst);
	add_node_start(lst, temp);
}

void rev_rotate_a(t_node **a)
{
	rev_rotate(a);
	ft_printf("rra\n");
}

void rev_rotate_b(t_node **b)
{
	rev_rotate(b);
	ft_printf("rrb\n");
}

void rev_rotate_both(t_node **a, t_node **b)
{
	rev_rotate(a);
	rev_rotate(b);
	ft_printf("rrr\n");
}