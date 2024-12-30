#include "push_swap.h"

void error_exit(char *msg)
{
	write(2, "\033[1;31mError\033[0m", 16);
	ft_printf("\n%s\n", msg);
	exit(EXIT_FAILURE);
}