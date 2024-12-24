#ifndef SO_LONG_H
#	define SO_LONG_H

#	include "libft/libft.h"
#	include <mlx.h>
#	include <fcntl.h>
#	include <stdio.h>
#	include <stdlib.h>
# include <unistd.h>

# define W_KEY 119
# define A_KEY 97
# define S_KEY 115
# define D_KEY 100
# define ESC_KEY 65307
# define PIXELS 64
typedef struct s_vars
	{
		void *mlx;
		void *win;
		char **map;
		int playerX;
		int playerY;
		int coins;
		int points;
		int moves;
		char *coinImg;
		char *exitImg;
		char *floorImg;
		char *playerDown;
		char *playerUp;
		char *playerLeft;
		char *playerRight;
		char *wallImg;
		int WinWidth;
		int WinHeight;
	} t_vars;

	int onCloseWin(t_vars *vars);
	int key_hook(int keycode, t_vars *vars);
	int matrix_height(char **array);
	void error_filename(char *description);
	void error_map(char *description);
	void read_map(t_vars *vars, char *filepath);
	void check_path (char *mapString, t_vars *vars);
	void check_walls(char **map);
	void check_form(char **map);
	void check_contents(char *mapString);
	void check_filename (char *filepath);
	void display_map (t_vars *vars);
	void put_image (t_vars *vars, char type, int x, int y);
	void go_up(t_vars *vars);
	void go_down(t_vars *vars);
	void go_left(t_vars *vars);
	void go_right(t_vars *vars);
	void game_over(t_vars *vars);
	void free_matrix(char **matrix);

#endif
