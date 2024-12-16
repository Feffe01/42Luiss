#ifndef SO_LONG_H
#	define SO_LONG_H

#	include "libft/libft.h"
#	include <mlx.h>
#	include <X11/Xlib.h>
#	include <stdio.h>

# define WIN_WIDTH 1280
# define WIN_HEIGHT 640
# define CHAR_WIDTH 64

	typedef struct s_data
	{
		void *img;
		char *addr;
		int bits_per_pixel;
		int line_length;
		int endian;
	} t_data;

	typedef struct s_vars
	{
		t_data img;
		void *mlx;
		void *win;
		int playerX;
		int playerY;
	} t_vars;

	int create_trgb(unsigned int t, unsigned int r, unsigned int g, unsigned int b);
	unsigned int get_t(int trgb);
	unsigned int get_r(int trgb);
	unsigned int get_g(int trgb);
	unsigned int get_b(int trgb);

	int add_shade(int trgb, double intensity);
	int get_complementary(int trgb);

	void createGrid(t_data *img, int startingX, int startingY, int width, int height, int color);
	void createRectangle(t_data *data, int startingX, int startingY, int width, int height, int color);
	void createTriangle(t_data *data, int startingX, int startingY, int width, int height, int color);
	void createCircle(t_data *data, int centreX, int centreY, int r, int color);
	void createHexagon(t_data *data, int startingX, int startingY, int r, int color);
	void createGradientRectangle(t_data *data, int startingX, int startingY, int width, int height, unsigned int color);
	void createLGBTRectangle(t_data *data, int startingX, int startingY, int width, int height);
	void createChessTexture(t_data *data, int startingX, int startingY, int width, int height, int multiplier, unsigned int color);
	void createDiagonalTexture(t_data *data, int startingX, int startingY, int width, int height, int multiplier, unsigned int color);

	int onXPress(t_vars *vars);
	int key_hook(int keycode, t_vars *vars);
	int mouse_hook(int keycode, t_vars *vars);

	int render_frame(t_vars* vars);

	void go_up(t_vars* vars);
	void go_down(t_vars* vars);
	void go_left(t_vars* vars);
	void go_right(t_vars* vars);

#endif
