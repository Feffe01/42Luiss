#include "push_swap.h"

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

	ft_printf("A stack:\n");
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