#include "so_long.h"

void check_filename (char *filepath)
{
	size_t len;
	char **path;
	char *filename;

	path = ft_split(filepath, '/');
	filename = path[array_len(path) - 1];
	len = ft_strlen(filename);
	if (filename[len - 1] != 'r')
		error_filename("File type is not .ber");
	if (filename[len - 2] != 'e')
		error_filename("File type is not .ber");
	if (filename[len - 3] != 'b')
		error_filename("File type is not .ber");
	if (filename[len - 4] != '.')
		error_filename("File type is not .ber");
	if (!ft_strtrim(filename, ".ber")[0])
		error_filename("File name not valid");
}

int main(int n, char **s)
{
	t_vars vars;

	if (n != 2)
	{
		write(2, "\033[1;31mError\n\033[0m", 16);
		ft_printf("Number of arguments is not 2\n");
		exit(EXIT_FAILURE);
	}

	check_filename(s[1]);
	read_map(&vars, s[1]);

	vars.mlx = mlx_init();

	vars.win = mlx_new_window(vars.mlx, WIN_WIDTH, WIN_HEIGHT, "so_long");

	vars.screen.img = mlx_new_image(vars.mlx, WIN_WIDTH, WIN_HEIGHT);

	vars.screen.addr = mlx_get_data_addr(vars.screen.img, &vars.screen.bits_per_pixel,
																		&vars.screen.line_length, &vars.screen.endian);

	vars.playerX = 0;
	vars.playerY = 0;
	render_frame(&vars);

	mlx_hook(vars.win, 17, 1L << 17, onCloseWin, &vars);
	mlx_key_hook(vars.win, key_hook, &vars);

	mlx_loop(vars.mlx);

	return (0);
}
