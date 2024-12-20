#include "so_long.h"

int array_len(char **array)
{
	int i;

	i = 0;
	while (array[i])
		i++;
	return i;
}

int render_frame(t_vars* vars)
{
	createGrid(&(vars->screen), 0, 0, WIN_WIDTH, WIN_HEIGHT, create_trgb(0, 198, 233, 249));
	createCircle(&(vars->screen), vars->playerX + TILE_WIDTH / 2, vars->playerY + TILE_WIDTH / 2, TILE_WIDTH / 2, create_trgb(0, 255, 0, 0));

	mlx_put_image_to_window(vars->mlx, vars->win, vars->screen.img, 0, 0);
	return 0;
}