#include "push_swap.h"

void rev_rotate(int *stack, int len)
{
	int temp;
	int i;

	i = len - 1;
	temp = stack[i];
	while (i > 0)
	{
		stack[i] = stack[i - 1];
		i--;
	}
	stack[i] = temp;
}

void rev_rotate_a(t_stacks *stacks)
{
	if (stacks->a_len < 2)
		return ;
	ft_printf("rra\n");
	rev_rotate(stacks->a, stacks->a_len);
}

void rev_rotate_b(t_stacks *stacks)
{
	if (stacks->b_len < 2)
		return ;
	ft_printf("rrb\n");
	rev_rotate(stacks->b, stacks->b_len);
}

void rev_rotate_both(t_stacks *stacks)
{
	if (stacks->a_len < 2 || stacks->b_len < 2)
		return ;
	ft_printf("rrr\n");
	rev_rotate(stacks->a, stacks->a_len);
	rev_rotate(stacks->b, stacks->b_len);
}