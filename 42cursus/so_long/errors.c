#include "so_long.h"

void error_filename(char *description)
{
	ft_printf("Error\nFile not valid: %s\n", description);
	exit(EXIT_FAILURE);
}

void error_map(char *description)
{
	ft_printf("Error\nMap is not valid: %s\n", description);
	exit(EXIT_FAILURE);
}