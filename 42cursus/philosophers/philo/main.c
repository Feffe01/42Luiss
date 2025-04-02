#include "philo.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if(argc < 5 || argc > 6)
	{
		printf("Wrong number of arguments.");
		return(1);
	}
	initializer(argc, argv, &data);
	printf("%d\n%d\n%d\n", data.fst_philo->index, data.fst_philo->left_fork->index, data.fst_philo->right_fork->index);
}