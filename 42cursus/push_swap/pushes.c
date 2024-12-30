// #include "push_swap.h"

// void copy_stack(int *dst, int *src, int size)
// {
// 	int i;

// 	i = 0;
// 	while (i < size)
// 	{
// 		dst[i] = src[i];
// 		i++;
// 	}
// }

// int *custom_realloc(int *ptr, int old_size, int new_size)
// {
// 	int *new_ptr;

// 	if (ptr == NULL)
// 		return (int *)ft_calloc(new_size, sizeof(int));
// 	if (new_size <= 0)
// 	{
// 		free(ptr);
// 		return NULL;
// 	}
// 	new_ptr = (int *)ft_calloc(new_size, sizeof(int));
// 	if (!new_ptr)
// 		error_exit("Reallocation failed");
// 	if (old_size < new_size)
// 		copy_stack(new_ptr, ptr, old_size);
// 	else
// 		copy_stack(new_ptr, ptr, new_size);
// 	free(ptr);
// 	return new_ptr;
// }

// void push(int **dst, int **src)
// {
// 	int num;
// 	int len_dst;
// 	int len_src;

// 	if (!src || !(*src))
// 		return;
// 	ft_printf("\nSTARTING PUSH\n");
// 	num = (*src)[0];
// 	len_dst = array_len(*dst);
// 	len_src = array_len(*src);
// 	ft_printf("\nARRAY LEN ENDED\nlen_dst: %d\nlen_src: %d\n", len_dst, len_src);
// 	rev_rotate(*src);
// 	ft_printf("\nSRC ROTATED\n");
// 	print_stacks(*src);
// 	*src = custom_realloc(*src, len_src, len_src - 1);
// 	*dst = custom_realloc(*dst, len_dst, len_dst + 1);
// 	ft_printf("dst final len: %d\n", array_len(*dst));
// 	if (*src == NULL || *dst == NULL)
// 		error_exit("Memory reallocation failed.");
// 	rotate(*dst);
// 	ft_printf("\nDST ROTATED\n");
// 	print_stacks(*dst);
// 	(*dst)[0] = num;
// }

// void push_a(int **a, int **b)
// {
// 	ft_printf("pa\n");
// 	push(a, b);
// }

// void push_b(int **a, int **b)
// {
// 	ft_printf("pb\n");
// 	push(b, a);
// }