#include "push_swap.h"

void error_exit(t_stacks *stacks)
{
	write(2, "Error\n", 6);
	if(stacks->a)
		free(stacks->a);
	if(stacks->b)
		free(stacks->b);
	exit(EXIT_FAILURE);
}
