#include "push_swap.h"

char **fix_input(char **argv, int *argc)
{
	char *new_input;
	char **temp;

	if (*argc < 2)
		exit(0);
	if (*argc == 2)
	{
		new_input = ft_strjoin("temp ", argv[1]);
		temp = ft_split(new_input, ' ');
		free(new_input);
		*argc = 0;
		while (temp[*argc])
			(*argc)++;
		return temp;
	}
	return argv;
}

void initialize(char **argv, int argc, t_stacks *stacks)
{
	int i;

	argv = fix_input(argv, &argc);
	stacks->a = (int *)ft_calloc(argc - 1, sizeof(int));
	if (!stacks->a)
		error_exit(stacks);
	stacks->b = NULL;
	stacks->b_len = 0;
	stacks->a_min = 2147483647;
	stacks->a_max = -2147483648;
	stacks->b_min = 2147483647;
	stacks->b_max = -2147483648;
	i = 1;
	while (argv[i])
	{
		(stacks->a)[i - 1] = check_int(stacks, argv[i]);
		i++;
	}
	stacks->a_len = i - 1;
}

int main(int argc, char **argv)
{
	t_stacks stacks;

	initialize(argv, argc, &stacks);
	check_a(&stacks);
	sort(&stacks);
	free(stacks.a);
	return (0);
}
