#include "push_swap.h"

void rotate(int *stack, int len)
{
	int temp;
	int i;

	i = 0;
	temp = stack[i];
	while (i < len - 1)
	{
		stack[i] = stack[i + 1];
		i++;
	}
	stack[i] = temp;
}

void rotate_a(t_stacks *stacks)
{
	if (stacks->a_len < 2)
		return ;
	ft_printf("ra\n");
	rotate(stacks->a, stacks->a_len);
}

void rotate_b(t_stacks *stacks)
{
	if (stacks->b_len < 2)
		return ;
	ft_printf("rb\n");
	rotate(stacks->b, stacks->b_len);
}

void rotate_both(t_stacks *stacks)
{
	if (stacks->a_len < 2 || stacks->b_len < 2)
		return ;
	ft_printf("rr\n");
	rotate(stacks->a, stacks->a_len);
	rotate(stacks->b, stacks->b_len);
}