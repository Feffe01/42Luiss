#include "push_swap.h"

int check_int(t_stacks *stacks, char *str)
{
	long value;
	int sign;
	size_t i;

	value = 0;
	sign = 1;
	i = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]))
			error_exit(stacks);
		value = value * 10 + (str[i] - '0');
		if (sign == 1 && value > 2147483647)
			error_exit(stacks);
		if (sign == -1 && -value < -2147483648)
			error_exit(stacks);
		i++;
	}
	return (sign * value);
}

void check_duplicates(t_stacks *stacks)
{
	int i;
	int j;

	i = 0;
	while (i < stacks->a_len - 1)
	{
		j = i + 1;
		while (j < stacks->a_len && stacks->a[i] != stacks->a[j])
			j++;
		if (j < stacks->a_len)
			error_exit(stacks);
		i++;
	}
}

void check_order(t_stacks *stacks)
{
	int i;

	i = 0;
	while (i < stacks->a_len - 1)
	{
		if (stacks->a[i] > stacks->a[i + 1])
			return ;
		i++;
	}
	free(stacks->a);
	exit(0);
}

void check_a(t_stacks *stacks)
{
	ft_printf("check duplicates\n");
	check_duplicates(stacks);
	ft_printf("check order\n");
	check_order(stacks);
	ft_printf("end checks\n");
}