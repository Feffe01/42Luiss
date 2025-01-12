#include "push_swap.h"

int check_int(t_node **lst, char *str)
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
			error_exit(lst, NULL);
		value = value * 10 + (str[i] - '0');
		if (sign == 1 && value > INT_MAX)
			error_exit(lst, NULL);
		if (sign == -1 && -value < INT_MIN)
			error_exit(lst, NULL);
		i++;
	}
	return (sign * value);
}

void check_duplicates(t_node **lst)
{
	t_node *current;
	t_node *temp;

	current = *lst;
	while (current->next)
	{
		temp = current->next;
		while (temp)
		{
			if(current->nbr == temp->nbr)
				error_exit(lst, NULL);
			temp = temp->next;
		}
		current = current->next;
	}
}

void check_order(t_node **lst)
{
	t_node *current;

	current = *lst;
	while (current->next)
	{
		if (current->nbr > current->next->nbr)
			return ;
		current = current->next;
	}
	free_stack(lst);
	exit(0);
}
