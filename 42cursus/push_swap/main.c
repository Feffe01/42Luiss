#include "push_swap.h"

int is_number(char *str)
{
	int i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void initialize(char **argv, int argc, t_stacks *stacks)
{
	int i;

	if (argc < 2)
		error_exit("Not enough arguments.");
	stacks->a = (int *)ft_calloc(argc - 1, sizeof(int));
	if (!stacks->a)
		error_exit("Memory allocation failed.");
	i = 1;
	while (argv[i])
	{
		if (is_number(argv[i]))
			(stacks->a)[i - 1] = ft_atoi(argv[i]);
		else
			error_exit("Every argument has to be a number");
		i++;
	}
	stacks->a_len = i - 1;
	stacks->b = NULL;
	stacks->b_len = 0;
}

int main(int argc, char **argv)
{
	t_stacks stacks;

	initialize(argv, argc, &stacks);

	print_stacks(&stacks);

	while (stacks.a_len > 0)
	{
		ft_printf("\nPUSH\n\n");
		push_b(&stacks);
		print_stacks(&stacks);
	}

	ft_printf("\nLAST PUSH\n\n");
	push_b(&stacks);
	print_stacks(&stacks);
	// ft_printf("\nROTATION\n\n");
	// rotate_a(&stacks);
	// print_stacks(&stacks);
	// ft_printf("\nREVERSE ROTATION\n\n");
	// rev_rotate_a(&stacks);
	// print_stacks(&stacks);
	// ft_printf("\nSWAP\n\n");
	// swap_a(&stacks);
	// print_stacks(&stacks);

	free(stacks.a);
	return (0);
}