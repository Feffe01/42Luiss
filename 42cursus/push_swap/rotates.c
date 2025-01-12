#include "push_swap.h"

void rotate(t_node **lst)
{
	t_node *temp;

	temp = rm_first_node(lst);
	add_node_end(lst, temp);
}

void rotate_a(t_node **a)
{
	rotate(a);
	ft_printf("ra\n");
}

void rotate_b(t_node **b)
{
	rotate(b);
	ft_printf("rb\n");
}

void rotate_both(t_node **a, t_node **b)
{
	rotate(a);
	rotate(b);
	ft_printf("rr\n");
}