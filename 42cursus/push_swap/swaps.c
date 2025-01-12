#include "push_swap.h"

void swap(t_node **stack)
{
	t_node	*first;
	t_node	*second;

	first = *stack;
	second = (*stack)->next;
	first->prev = second;
	first->next = second->next;
	second->prev = NULL;
	second->next = first;
	*stack = second;
}

void swap_a(t_node **a)
{
	if (!(*a)->next)
		return ;
	swap(a);
	ft_printf("sa\n");
}

void swap_b(t_node **b)
{
	if (!(*b)->next)
		return ;
	swap(b);
	ft_printf("sb\n");
}

void swap_both(t_node **a, t_node **b)
{
	if (!(*a)->next || !(*b)->next)
		return ;
	swap(a);
	swap(b);
	ft_printf("ss\n");
}