#include "so_long.h"

void go_up(t_vars* vars)
{
	if (vars->playerY - TILE_WIDTH >= 0)
		vars->playerY = vars->playerY - TILE_WIDTH;
	render_frame(vars);
}

void go_down(t_vars* vars)
{
	if (vars->playerY + TILE_WIDTH <= WIN_HEIGHT - TILE_WIDTH)
		vars->playerY = vars->playerY + TILE_WIDTH;
	render_frame(vars);
}

void go_left(t_vars* vars)
{
	if (vars->playerX - TILE_WIDTH >= 0)
		vars->playerX = vars->playerX - TILE_WIDTH;
	render_frame(vars);
}

void go_right(t_vars* vars)
{
	if (vars->playerX + TILE_WIDTH <= WIN_WIDTH - TILE_WIDTH)
		vars->playerX = vars->playerX + TILE_WIDTH;
	render_frame(vars);
}