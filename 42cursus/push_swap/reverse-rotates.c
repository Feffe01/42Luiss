#include "push_swap.h"

void rev_rotate(int *stack, int len)
{
	int temp;
	int i;

	if (!stack[0] || !stack[1])
		return ;
	i = 0;
	temp = stack[i];
	while (i < len - 1)
	{
		stack[i] = stack[i + 1];
		i++;
	}
	stack[i] = temp;
}

void rev_rotate_a(t_stacks *stacks)
{
	ft_printf("rra\n");
	rev_rotate(stacks->a, stacks->a_len);
}

void rev_rotate_b(t_stacks *stacks)
{
	ft_printf("rrb\n");
	rev_rotate(stacks->b, stacks->b_len);
}

void rev_rotate_both(t_stacks *stacks)
{
	ft_printf("rrr\n");
	rev_rotate(stacks->a, stacks->a_len);
	rev_rotate(stacks->b, stacks->b_len);
}