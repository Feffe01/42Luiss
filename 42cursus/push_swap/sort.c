// #include "push_swap.h"

// void sort_3b(t_stacks *stacks)
// {
// 	if (stacks->b[0] < stacks->b[1] && stacks->b[1] < stacks->b[2]) // 1 2 3
// 	{
// 		swap_b(stacks);
// 		rev_rotate_b(stacks);
// 	}
// 	else if (stacks->b[0] > stacks->b[1] && stacks->b[1] < stacks->b[2] && stacks->b[0] > stacks->b[2]) // 3 1 2
// 	{
// 		rev_rotate_b(stacks);
// 		swap_b(stacks);
// 	}
// 	else if (stacks->b[0] > stacks->b[1] && stacks->b[0] < stacks->b[2]) // 2 1 3
// 		rev_rotate_b(stacks);
// 	else if (stacks->b[0] < stacks->b[1] && stacks->b[1] > stacks->b[2] && stacks->b[0] < stacks->b[2]) // 1 3 2
// 		rotate_b(stacks);
// 	else if (stacks->b[0] < stacks->b[1] && stacks->b[1] > stacks->b[2]) // 2 3 1
// 		swap_b(stacks);
// }

// void sort_3a(t_stacks *stacks)
// {
// 	if (stacks->a[0] > stacks->a[1] && stacks->a[1] > stacks->a[2]) // 3 2 1
// 	{
// 		swap_a(stacks);
// 		rev_rotate_a(stacks);
// 	}
// 	else if (stacks->a[0] > stacks->a[1] && stacks->a[1] < stacks->a[2] && stacks->a[0] > stacks->a[2]) // 3 1 2
// 		rotate_a(stacks);
// 	else if (stacks->a[0] > stacks->a[1] && stacks->a[0] < stacks->a[2]) // 2 1 3
// 		swap_a(stacks);
// 	else if (stacks->a[0] < stacks->a[1] && stacks->a[1] > stacks->a[2] && stacks->a[0] < stacks->a[2]) // 1 3 2
// 	{
// 		rev_rotate_a(stacks);
// 		swap_a(stacks);
// 	}
// 	else if (stacks->a[0] < stacks->a[1] && stacks->a[1] > stacks->a[2]) // 2 3 1
// 		rev_rotate_a(stacks);
// }

// void sort_2b(t_stacks *stacks)
// {
// 	if (stacks->b[0] < stacks->b[1])
// 		swap_b(stacks);
// }

// void sort_2a(t_stacks *stacks)
// {
// 	if (stacks->a[0] > stacks->a[1])
// 		swap_a(stacks);
// }

// void sort(t_stacks *stacks)
// {
// 	if (stacks->a_len <= 1)
// 		return;
// 	else if (stacks->a_len == 2)
// 		sort_2a(stacks);
// 	else if (stacks->a_len == 3)
// 		sort_3a(stacks);
// 	else
// 	{
// 		while (stacks->a[0] > stacks->a[stacks->a_len - 1])
// 			rev_rotate_a(stacks);
// 		check_order(stacks);
// 		push_b(stacks);
// 		start_sorting(stacks);
// 	}
// }