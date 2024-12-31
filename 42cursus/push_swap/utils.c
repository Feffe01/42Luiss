#include "push_swap.h"

void	check_min(t_stacks *stacks)
{
	int i;
	int temp;

	i = 0;
	temp = 2147483647;
	while (i < stacks->a_len)
	{
		if (stacks->a[i] < temp)
			temp = stacks->a[i];
		i++;
	}
	stacks->a_min = temp;

	i = 0;
	temp = 2147483647;
	while (i < stacks->b_len)
	{
		if (stacks->b[i] < temp)
			temp = stacks->b[i];
		i++;
	}
	stacks->b_min = temp;
}

void check_max (t_stacks *stacks)
{
	int	i;
	int	temp;

	i = 0;
	temp = -2147483648;
	while (i < stacks->b_len)
	{
		if (stacks->b[i] > temp)
			temp = stacks->b[i];
		i++;
	}
	stacks->b_max = temp;

	i = 0;
	temp = -2147483648;
	while (i < stacks->a_len)
	{
		if (stacks->a[i] > temp)
			temp = stacks->a[i];
		i++;
	}
	stacks->a_max = temp;
}

void check_min_max(t_stacks *stacks)
{
	check_min(stacks);
	check_max(stacks);
}

int array_len(int *array)
{
	int	i;

	if (!array)
		return (0);
	i = 0;
	while (array[i])
		i++;
	return (i);
}

void	print_stacks (t_stacks *stack)
{
	int i;

	ft_printf("\nA stack:\n");
	i = 0;
	while (i < stack->a_len)
	{
		ft_printf("%d\n", (stack->a)[i]);
		i++;
	}
	ft_printf("\nB stack:\n");
	i = 0;
	while (i < stack->b_len)
	{
		ft_printf("%d\n", (stack->b)[i]);
		i++;
	}
}