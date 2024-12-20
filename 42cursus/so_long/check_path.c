#include "so_long.h"

void check_moves (char **map, int x, int y, int *checkC, int *checkE)
{
	if (map[y][x] == 'C')
		*checkC = 1;
	if (map[y][x] == 'E')
		*checkE = 1;
	if (map[y][x] == '1')
		return ;
	else
		map[y][x] = '1';
	check_moves(map, x + 1, y, checkC, checkE);
	check_moves(map, x - 1, y, checkC, checkE);
	check_moves(map, x, y + 1, checkC, checkE);
	check_moves(map, x, y - 1, checkC, checkE);
}

void check_path (char **map, int playerX, int playerY) {
	int checkC;
	int checkE;
	char **mapCopy;

	checkC = 0;
	checkE = 0;
	mapCopy = map;
	check_moves(mapCopy, playerX, playerY, &checkC, &checkE);
	if (checkC == 0 || checkE == 0)
		error_map("There is not a valid path");
	else
		ft_printf("Valid path found\n");
}