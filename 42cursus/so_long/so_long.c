#include "so_long.h"

void game_over(t_vars *vars)
{
	free_matrix(vars->map);
	mlx_destroy_window(vars->mlx, vars->win);
	exit(1);
}

void initialize_vars(t_vars *vars)
{
	int a;

	a = PIXELS;
	vars->mlx = mlx_init();
	vars->coins = 0;
	vars->points = 0;
	vars->moves = 0;
	vars->playerX = 0;
	vars->playerY = 0;
	vars->coinImg = mlx_xpm_file_to_image(vars->mlx, "assets/coin.xpm", &a, &a);
	vars->exitImg = mlx_xpm_file_to_image(vars->mlx, "assets/exit.xpm", &a, &a);
	vars->floorImg = mlx_xpm_file_to_image(vars->mlx, "assets/floor.xpm", &a, &a);
	vars->playerUp = mlx_xpm_file_to_image(vars->mlx, "assets/playerUp.xpm", &a, &a);
	vars->playerDown = mlx_xpm_file_to_image(vars->mlx, "assets/playerDown.xpm", &a, &a);
	vars->playerRight = mlx_xpm_file_to_image(vars->mlx, "assets/playerDown.xpm", &a, &a);
	vars->playerLeft = mlx_xpm_file_to_image(vars->mlx, "assets/playerDown.xpm", &a, &a);
	vars->wallImg = mlx_xpm_file_to_image(vars->mlx, "assets/wall.xpm", &a, &a);
	vars->WinWidth = 0;
	vars->WinHeight = 0;
}

int main(int argc, char **argv)
{
	t_vars vars;

	if (argc != 2)
	{
		write(2, "\033[1;31mError\033[0m", 16);
		ft_printf("\nNumber of arguments is not 2\n");
		exit(EXIT_FAILURE);
	}
	initialize_vars(&vars);
	check_filename(argv[1]);
	read_map(&vars, argv[1]);
	vars.win = mlx_new_window(vars.mlx, vars.WinWidth, vars.WinHeight, "so_long");
	display_map(&vars);
	mlx_hook(vars.win, 17, 1L << 17, onCloseWin, &vars);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
