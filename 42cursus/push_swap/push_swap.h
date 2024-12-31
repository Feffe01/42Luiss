#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct s_stacks
{
	int	*a;
	int	*b;
	int	a_len;
	int	b_len;
	int a_min;
	int b_min;
	int b_max;
}	t_stacks;

void	error_exit();

int		array_len(int *array);
void	print_stacks (t_stacks *stack);
void	check_min_max (t_stacks *stacks);

void	swap(int *stack);
void	swap_a(t_stacks *stack);
void	swap_b(t_stacks *stack);
void	swap_both(t_stacks *stack);

void	rotate_a(t_stacks *stack);
void	rotate_b(t_stacks *stack);
void	rotate_both(t_stacks *stack);

void	rev_rotate_a(t_stacks *stack);
void	rev_rotate_b(t_stacks *stack);
void	rev_rotate_both(t_stacks *stack);

void	push_a(t_stacks *stack);
void	push_b(t_stacks *stack);

void	sort(t_stacks *stacks);
void	sort_3a(t_stacks *stacks);

void	start_sorting(t_stacks *stacks);

#endif