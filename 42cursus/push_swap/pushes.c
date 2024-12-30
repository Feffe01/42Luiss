#include "push_swap.h"

void enlarge(int *dst, int *src, int size)
{
	int i;

	ft_printf("enlarge size: %d\n", size);
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

	ft_printf("shrink size: %d\n", size);
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
		error_exit("Reallocation failed");
	if (old_size < new_size)
		enlarge(new_ptr, ptr, new_size);
	else
		shrink(new_ptr, ptr, new_size);
	free(ptr);
	return new_ptr;
}

void push_a(t_stacks *stack)
{
	int temp;

	if (!stack->b || !(stack->b)[0])
		return ;
	temp = (stack->b)[0];
	ft_printf("len_a: %d\nlen_b: %d\n", stack->b_len, stack->a_len);
	stack->b = custom_realloc(stack->b, stack->b_len, stack->b_len - 1);
	stack->b_len--;
	ft_printf("end of b\n");
	stack->a = custom_realloc(stack->a, stack->a_len, stack->a_len + 1);
	stack->a_len++;
	(stack->a)[0] = temp;
	ft_printf("end of a\n");
}

void push_b(t_stacks *stack)
{
	int temp;

	if (!stack->a || !(stack->a)[0])
		return ;
	temp = (stack->a)[0];
	ft_printf("len_a: %d\nlen_b: %d\n", stack->a_len, stack->b_len);
	stack->a = custom_realloc(stack->a, stack->a_len, stack->a_len - 1);
	stack->a_len--;
	stack->b = custom_realloc(stack->b, stack->b_len, stack->b_len + 1);
	stack->b_len++;
	(stack->b)[0] = temp;
}