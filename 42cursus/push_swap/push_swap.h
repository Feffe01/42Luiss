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
}	t_stacks;

void	error_exit(char *msg);

int		array_len(int *array);
void	print_stacks (t_stacks *stack);

void	swap(int *stack);
void	swap_a(t_stacks *stack);
void	swap_b(t_stacks *stack);
void	swap_both(t_stacks *stack);

void	rotate(int *stack, int len);
void	rotate_a(t_stacks *stack);
void	rotate_b(t_stacks *stack);
void	rotate_both(t_stacks *stack);

void	rev_rotate(int *stack, int len);
void	rev_rotate_a(t_stacks *stack);
void	rev_rotate_b(t_stacks *stack);
void	rev_rotate_both(t_stacks *stack);

// void	push_a(int **a, int **b);
// void	push_b(int **a, int **b);

#endif