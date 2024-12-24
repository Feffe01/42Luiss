#include "so_long.h"

void go_up(t_vars *vars)
{
	char **map;
	int x;
	int y;

	map = vars->map;
	x = vars->playerX;
	y = vars->playerY;
	if ((map[y - 1][x] != '1' && map[y - 1][x] != 'E') || (map[y - 1][x] == 'E' && vars->coins == vars->points))
	{
		vars->playerY -= 1;
		ft_printf("Moves: %d\n", ++vars->moves);
		if (map[y - 1][x] == 'C')
		{
			vars->points += 1;
			map[y - 1][x] = '0';
			ft_printf("Points: %d\n", vars->points);
		}
		if (map[y - 1][x] == 'E')
			game_over(vars);
		put_image(vars, 'U', x * PIXELS, (y - 1) * PIXELS);
		put_image(vars, '0', x * PIXELS, y * PIXELS);
	}
}

void go_down(t_vars *vars)
{
	char **map;
	int x;
	int y;

	map = vars->map;
	x = vars->playerX;
	y = vars->playerY;
	if ((map[y + 1][x] != '1' && map[y + 1][x] != 'E') || (map[y + 1][x] == 'E' && vars->coins == vars->points))
	{
		vars->playerY += 1;
		ft_printf("Moves: %d\n", ++vars->moves);
		if (map[y + 1][x] == 'C')
		{
			vars->points += 1;
			map[y + 1][x] = '0';
			ft_printf("Points: %d\n", vars->points);
		}
		if (map[y + 1][x] == 'E')
			game_over(vars);
		put_image(vars, 'D', x * PIXELS, (y + 1) * PIXELS);
		put_image(vars, '0', x * PIXELS, y * PIXELS);
	}
}

void go_left(t_vars *vars)
{
	char **map;
	int x;
	int y;

	map = vars->map;
	x = vars->playerX;
	y = vars->playerY;
	if ((map[y][x - 1] != '1' && map[y][x - 1] != 'E') || (map[y][x - 1] == 'E' && vars->coins == vars->points))
	{
		vars->playerX -= 1;
		ft_printf("Moves: %d\n", ++vars->moves);
		if (map[y][x - 1] == 'C')
		{
			vars->points += 1;
			map[y][x - 1] = '0';
			ft_printf("Points: %d\n", vars->points);
		}
		if (map[y][x - 1] == 'E')
			game_over(vars);
		put_image(vars, 'L', (x - 1) * PIXELS, y * PIXELS);
		put_image(vars, '0', x * PIXELS, y * PIXELS);
	}
}

void go_right(t_vars *vars)
{
	char **map;
	int x;
	int y;

	map = vars->map;
	x = vars->playerX;
	y = vars->playerY;
	if ((map[y][x + 1] != '1' && map[y][x + 1] != 'E') || (map[y][x + 1] == 'E' && vars->coins == vars->points))
	{
		vars->playerX += 1;
		ft_printf("Moves: %d\n", ++vars->moves);
		if (map[y][x + 1] == 'C')
		{
			vars->points += 1;
			map[y][x + 1] = '0';
			ft_printf("Points: %d\n", vars->points);
		}
		if (map[y][x + 1] == 'E')
			game_over(vars);
		put_image(vars, 'R', (x + 1) * PIXELS, y * PIXELS);
		put_image(vars, '0', x * PIXELS, y * PIXELS);
	}
}