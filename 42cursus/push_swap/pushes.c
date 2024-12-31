#include "push_swap.h"

void enlarge(int *dst, int *src, int size)
{
	int i;

	i = size - 1;
	while (i > 0)
	{
		dst[i] = src[i - 1];
		i--;
	}
}

void shrink(int *dst, int *src, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		dst[i] = src[i + 1];
		i++;
	}
}

int *custom_realloc(int *ptr, int old_size, int new_size)
{
	int *new_ptr;

	if (ptr == NULL)
		return (int *)ft_calloc(new_size, sizeof(int));
	if (new_size <= 0)
	{
		free(ptr);
		return NULL;
	}
	new_ptr = (int *)ft_calloc(new_size, sizeof(int));
	if (!new_ptr)
		error_exit();
	if (old_size < new_size)
		enlarge(new_ptr, ptr, new_size);
	else
		shrink(new_ptr, ptr, new_size);
	free(ptr);
	return new_ptr;
}

void push_a(t_stacks *stacks)
{
	int temp;

	if (!stacks->b || !(stacks->b)[0])
		return ;
	temp = (stacks->b)[0];
	stacks->b = custom_realloc(stacks->b, stacks->b_len, stacks->b_len - 1);
	stacks->b_len--;
	stacks->a = custom_realloc(stacks->a, stacks->a_len, stacks->a_len + 1);
	stacks->a_len++;
	(stacks->a)[0] = temp;
	if (temp <= stacks->a_min || temp >= stacks->b_max || temp <= stacks->b_min)
		check_min_max(stacks);
	ft_printf("pa\n");
}

void push_b(t_stacks *stacks)
{
	int temp;

	if (!stacks->a || !(stacks->a)[0])
		return ;
	temp = (stacks->a)[0];
	stacks->a = custom_realloc(stacks->a, stacks->a_len, stacks->a_len - 1);
	stacks->a_len--;
	stacks->b = custom_realloc(stacks->b, stacks->b_len, stacks->b_len + 1);
	stacks->b_len++;
	(stacks->b)[0] = temp;
	if (temp <= stacks->a_min || temp >= stacks->b_max || temp <= stacks->b_min)
		check_min_max(stacks);
	ft_printf("pb\n");
}