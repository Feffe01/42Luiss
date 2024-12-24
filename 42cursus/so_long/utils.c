#include "so_long.h"

int matrix_height(char **array)
{
	int i;

	i = 0;
	while (array[i])
		i++;
	return i;
}

void free_matrix(char **matrix)
{
	int i;

	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}