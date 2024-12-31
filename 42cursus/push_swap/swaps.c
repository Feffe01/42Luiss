#include "push_swap.h"

void swap(int *stack)
{
	int temp;

	temp = stack[0];
	stack[0] = stack[1];
	stack[1] = temp;
}

void swap_a(t_stacks *stacks)
{
	if (stacks->a_len < 2)
		return ;
	ft_printf("sa\n");
	swap(stacks->a);
}

void swap_b(t_stacks *stacks)
{
	if (stacks->b_len < 2)
		return ;
	ft_printf("sb\n");
	swap(stacks->b);
}

void swap_both(t_stacks *stacks)
{
	if (stacks->a_len < 2 || stacks->b_len < 2)
		return ;
	ft_printf("ss\n");
	swap(stacks->a);
	swap(stacks->b);
}