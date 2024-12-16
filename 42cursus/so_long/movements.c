#include "so_long.h"

void go_up(t_vars* vars)
{
	if (vars->playerY - CHAR_WIDTH >= 0)
		vars->playerY = vars->playerY - CHAR_WIDTH;
	render_frame(vars);
}

void go_down(t_vars* vars)
{
	if (vars->playerY + CHAR_WIDTH <= WIN_HEIGHT - CHAR_WIDTH)
		vars->playerY = vars->playerY + CHAR_WIDTH;
	render_frame(vars);
}

void go_left(t_vars* vars)
{
	if (vars->playerX - CHAR_WIDTH >= 0)
		vars->playerX = vars->playerX - CHAR_WIDTH;
	render_frame(vars);
}

void go_right(t_vars* vars)
{
	if (vars->playerX + CHAR_WIDTH <= WIN_WIDTH - CHAR_WIDTH)
		vars->playerX = vars->playerX + CHAR_WIDTH;
	render_frame(vars);
}