#include "so_long.h"

int onCloseWin(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
}

int key_hook(int keycode, t_vars *vars)
{
	if (keycode == ESC_KEY)
		onCloseWin(vars);
	if (keycode == W_KEY)
		go_up(vars);
	if (keycode == S_KEY)
		go_down(vars);
	if (keycode == A_KEY)
		go_left(vars);
	if (keycode == D_KEY)
		go_right(vars);
	return (0);
}