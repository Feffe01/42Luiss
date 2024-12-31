#include "push_swap.h"

void error_exit(t_stacks *stacks)
{
	write(2, "\033[1;31mError\033[0m", 16);
	write(2, "\n", 1);
	if(stacks->a)
		free(stacks->a);
	if(stacks->b)
		free(stacks->b);
	exit(EXIT_FAILURE);
}