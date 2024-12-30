#include "push_swap.h"

void rotate(int *stack, int len)
{
	int temp;
	int i;

	if (!stack[0] || !stack[1])
		return ;
	i = len - 1;
	temp = stack[i];
	while (i > 0)
	{
		stack[i] = stack[i - 1];
		i--;
	}
	stack[i] = temp;
}

void rotate_a(t_stacks *stacks)
{
	ft_printf("ra\n");
	rotate(stacks->a, stacks->a_len);
}

void rotate_b(t_stacks *stacks)
{
	ft_printf("rb\n");
	rotate(stacks->b, stacks->b_len);
}

void rotate_both(t_stacks *stacks)
{
	ft_printf("rr\n");
	rotate(stacks->a, stacks->a_len);
	rotate(stacks->b, stacks->b_len);
}