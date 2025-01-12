#include "push_swap.h"

void	print_stacks(t_node **a, t_node **b)
{
	t_node *current_a;
	t_node *current_b;

	ft_printf("==========\n");
	ft_printf("STACK A\n");
	if (!a || !*a)
		ft_printf("[Empty]\n");
	else
	{
		current_a = *a;
		while (current_a)
		{
			ft_printf("%d\n", current_a->nbr);
			current_a = current_a->next;
		}
	}
	ft_printf("----------\n");
	ft_printf("STACK B\n");
	if (!b || !*b)
		ft_printf("[Empty]\n");
	else
	{
		current_b = *b;
		while (current_b)
		{
			ft_printf("%d\n", current_b->nbr);
			current_b = current_b->next;
		}
	}
	ft_printf("==========\n\n");
}

void	init_a(char **argv, t_node **a)
{
	int i;
	t_node *new_node;

	i = 0;
	while (argv[i])
	{
		new_node = create_node(check_int(a, argv[i]));
		if (!new_node)
			error_exit(a, NULL);
		add_node_end(a, new_node);
		i++;
	}
}

int main(int argc, char **argv)
{
	t_node *a;
	t_node *b;

	a = NULL;
	b = NULL;
	if (argc < 2 || !argv[1][0])
		return (1);
	if (argc == 2)
		argv = ft_split(argv[1], ' ');
	ft_printf("--Init a--\n\n");
	init_a(argv, &a);
	print_stacks(&a, &b);
	ft_printf("--Checking duplicates--\n\n");
	check_duplicates(&a);
	ft_printf("--Checking order--\n\n");
	check_order(&a);
	// if (stack_size(&a) == 2)
	// else if (stack_size(&a) == 3)
	// else

	ft_printf("--Push B 3 times--\n\n");
	push_b(&a, &b);
	push_b(&a, &b);
	push_b(&a, &b);
	print_stacks(&a, &b);

	ft_printf("--Rev Rotate both--\n\n");
	rev_rotate_both(&a, &b);
	print_stacks(&a, &b);

	ft_printf("--Rotate both--\n\n");
	rotate_both(&a, &b);
	print_stacks(&a, &b);

	ft_printf("--Swap A--\n\n");
	swap_a(&a);

	ft_printf("--Swap B--\n\n");
	swap_b(&b);
	print_stacks(&a, &b);

	ft_printf("--Swap Both--\n\n");
	swap_both(&a, &b);
	print_stacks(&a, &b);

	ft_printf("--Push A 3 times--\n\n");
	push_a(&a, &b);
	push_a(&a, &b);
	push_a(&a, &b);

	ft_printf("--Result--\n\n");
	print_stacks(&a, &b);
	return (0);
}
