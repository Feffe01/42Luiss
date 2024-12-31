#include "push_swap.h"

void ending(t_stacks *stacks)
{
	if (stacks->b[0] < stacks->a[0])
	{
		if (stacks->b[0] > stacks->a[stacks->a_len - 1])
			push_a(stacks);
		else if (stacks->b[0] < stacks->a_min)
		{
			while (stacks->a[0] > stacks->a[stacks->a_len - 1])
				rev_rotate_a(stacks);
			push_a(stacks);
		}
		else
			rev_rotate_a(stacks);
	}
	else if (stacks->b[0] > stacks->a_max)
	{
		while (stacks->a[0] > stacks->a[stacks->a_len - 1])
			rev_rotate_a(stacks);
		push_a(stacks);
	}
	else
		rotate_a(stacks);
}

void fill_b(t_stacks *stacks)
{
	if (stacks->a[0] > stacks->b[0])
	{
		if (stacks->a[0] < stacks->b[stacks->b_len - 1])
			push_b(stacks);
		else if (stacks->a[0] > stacks->b_max)
		{
			while (stacks->b[0] < stacks->b[stacks->b_len - 1])
				rev_rotate_b(stacks);
			push_b(stacks);
		}
		else
			rev_rotate_b(stacks);
	}
	else if (stacks->a[0] < stacks->b_min)
	{
		while (stacks->b[0] < stacks->b[stacks->b_len - 1])
			rev_rotate_b(stacks);
		push_b(stacks);
	}
	else
		rotate_b(stacks);
}

void start_sorting(t_stacks *stacks)
{
	while (stacks->a_len > 3)
	{
		while (stacks->a[0] > stacks->a[stacks->a_len - 1])
			rev_rotate_a(stacks);
		fill_b(stacks);
	}
	sort_3a(stacks);
	while (stacks->b[0] < stacks->b[stacks->b_len - 1])
		rev_rotate_b(stacks);
	while (stacks->b_len > 0)
		ending(stacks);
	while (stacks->a[0] > stacks->a[stacks->a_len - 1])
		rev_rotate_a(stacks);
}