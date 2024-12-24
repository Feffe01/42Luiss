#include "so_long.h"

void put_image (t_vars *vars, char type, int x, int y)
{
	if (type != '1')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->floorImg, x, y);
	else
		mlx_put_image_to_window(vars->mlx, vars->win, vars->wallImg, x, y);
	if (type == 'U')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->playerUp, x, y);
	if (type == 'D' || type == 'P')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->playerDown, x, y);
	if (type == 'L')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->playerLeft, x, y);
	if (type == 'R')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->playerRight, x, y);
	if (type == 'C')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->coinImg, x, y);
	if (type == 'E')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->exitImg, x, y);
}

void display_map (t_vars *vars)
{
	int i;
	int j;

	i = 0;
	while (vars->map[i])
	{
		j = 0;
		while (vars->map[i][j])
		{
			put_image(vars, vars->map[i][j], j * PIXELS, i * PIXELS);
			j++;
		}
		i++;
	}
}