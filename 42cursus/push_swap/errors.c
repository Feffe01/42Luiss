#include "push_swap.h"

void error_exit()
{
	write(2, "\033[1;31mError\033[0m", 16);
	write(2, "\n", 1);
	exit(EXIT_FAILURE);
}