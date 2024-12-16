#include "so_long.h"

int render_frame(t_vars* vars)
{
	createGrid(&(vars->img), 0, 0, WIN_WIDTH, WIN_HEIGHT, create_trgb(0, 198, 233, 249));
	createCircle(&(vars->img), vars->playerX + CHAR_WIDTH / 2, vars->playerY + CHAR_WIDTH / 2, CHAR_WIDTH / 2, create_trgb(0, 255, 0, 0));

	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	return 0;
}

int main(void)
{
	t_vars vars;

	vars.playerX = 0;
	vars.playerY = 0;

	vars.mlx = mlx_init();
	if (!vars.mlx)
	{
		fprintf(stderr, "Error: Failed to initialize MLX\n");
		return (1);
	}

	vars.win = mlx_new_window(vars.mlx, WIN_WIDTH, WIN_HEIGHT, "so_long");
	if (!vars.win)
	{
		fprintf(stderr, "Error: Failed to create window\n");
		return (1);
	}

	vars.img.img = mlx_new_image(vars.mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!vars.img.img)
	{
		fprintf(stderr, "Error: Failed to create image\n");
		return (1);
	}

	vars.img.addr = mlx_get_data_addr(vars.img.img, &vars.img.bits_per_pixel,
																		&vars.img.line_length, &vars.img.endian);
	if (!vars.img.addr)
	{
		fprintf(stderr, "Error: Failed to get image address\n");
		return (1);
	}

	render_frame(&vars);

	mlx_hook(vars.win, 17, 1L << 17, onXPress, &vars);
	mlx_key_hook(vars.win, key_hook, &vars);

	mlx_loop(vars.mlx);

	return (0);
}
