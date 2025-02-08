/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgiampa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 09:37:11 by fgiampa           #+#    #+#             */
/*   Updated: 2025/01/17 09:37:13 by fgiampa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_node **a, t_node **b)
{
	if (is_ordered(a))
		return ;
	if (stack_size(*a) == 2)
		swap_a(a);
	else if (stack_size(*a) == 3)
		sort_three_a(a);
	else
		start_sorting(a, b);
}

void	init_a(char **argv, t_node **a)
{
	int			i;
	t_node		*new_node;

	if (!*argv)
	{
		free(argv);
		error_exit(a, NULL);
	}
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

void	init_a_allocated(char **argv, t_node **a)
{
	int			i;
	t_node		*new_node;

	if (!*argv)
	{
		free(argv);
		error_exit(a, NULL);
	}
	i = 0;
	while (argv[i])
	{
		new_node = create_node(check_int_all(a, argv[i], argv));
		if (!new_node)
			error_exit(a, NULL);
		add_node_end(a, new_node);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (1);
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		init_a_allocated(argv, &a);
	}
	else
	{
		argv = argv + 1;
		init_a(argv, &a);
	}
	check_duplicates(&a);
	sort(&a, &b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
