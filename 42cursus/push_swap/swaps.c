#include "push_swap.h"

void swap(int *stack)
{
	int temp;

	if (!stack[0] || !stack[1])
		return ;
	temp = stack[0];
	stack[0] = stack[1];
	stack[1] = temp;
}

void swap_a(t_stacks *stacks)
{
	ft_printf("sa\n");
	swap(stacks->a);
}

void swap_b(t_stacks *stacks)
{
	ft_printf("sb\n");
	swap(stacks->b);
}

void swap_both(t_stacks *stacks)
{
	ft_printf("ss\n");
	swap(stacks->a);
	swap(stacks->b);
}