#include "push_swap.h"

// void	print_stacks(t_node **a, t_node **b)
// {
// 	t_node *current_a;
// 	t_node *current_b;

// 	ft_printf("==========\n");
// 	ft_printf("STACK A\n");
// 	if (!a || !*a)
// 		ft_printf("[Empty]\n");
// 	else
// 	{
// 		current_a = *a;
// 		while (current_a)
// 		{
// 			ft_printf("%d. %d t:%d cost:%d\n", current_a->index, current_a->nbr, current_a->target->nbr, current_a->push_cost);
// 			current_a = current_a->next;
// 		}
// 	}
// 	ft_printf("----------\n");
// 	ft_printf("STACK B\n");
// 	if (!b || !*b)
// 		ft_printf("[Empty]\n");
// 	else
// 	{
// 		current_b = *b;
// 		while (current_b)
// 		{
// 			if(current_b->target)
// 				ft_printf("%d. %d t:%d cost:%d\n", current_b->index, current_b->nbr, current_b->target->nbr, current_b->push_cost);
// 			else
// 				ft_printf("%d. %d cost:%d\n", current_b->index, current_b->nbr, current_b->push_cost);
// 			current_b = current_b->next;
// 		}
// 	}
// 	ft_printf("==========\n\n");
// }

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
	else
		argv = argv + 1;
	init_a(argv, &a);

	check_duplicates(&a);

	if(is_ordered(&a))
		return (0);

	if (stack_size(a) == 2)
		swap_a(&a);
	else if (stack_size(a) == 3)
		sort_three_a(&a);
	else
		start_sorting(&a, &b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
