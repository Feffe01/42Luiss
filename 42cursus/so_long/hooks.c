#include "so_long.h"

int onXPress(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}

int key_hook(int keycode, t_vars *vars)
{
	if (keycode == 65307) // ESC
		mlx_destroy_window(vars->mlx, vars->win);
	if (keycode == 119)
		go_up(vars);
	if (keycode == 115)
		go_down(vars);
	if (keycode == 97)
		go_left(vars);
	if (keycode == 100)
		go_right(vars);
	return (0);
}

int mouse_hook(int keycode, t_vars *vars)
{
	keycode = keycode;
	render_frame(vars);
	return (0);
}