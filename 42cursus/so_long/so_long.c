/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgiampa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 17:51:11 by fgiampa           #+#    #+#             */
/*   Updated: 2024/12/28 17:51:14 by fgiampa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game_over(t_vars *vars)
{
	free_matrix(vars->map);
	mlx_destroy_window(vars->mlx, vars->win);
	exit(1);
}

void	initialize_images(t_vars *vars)
{
	int	a;

	a = PIXELS;
	vars->coin_img = mlx_xpm_file_to_image(vars->mlx,
			"assets/coin.xpm", &a, &a);
	vars->exit_img = mlx_xpm_file_to_image(vars->mlx,
			"assets/exit.xpm", &a, &a);
	vars->floor_img = mlx_xpm_file_to_image(vars->mlx,
			"assets/floor.xpm", &a, &a);
	vars->up_img = mlx_xpm_file_to_image(vars->mlx,
			"assets/up.xpm", &a, &a);
	vars->down_img = mlx_xpm_file_to_image(vars->mlx,
			"assets/down.xpm", &a, &a);
	vars->right_img = mlx_xpm_file_to_image(vars->mlx,
			"assets/right.xpm", &a, &a);
	vars->left_img = mlx_xpm_file_to_image(vars->mlx,
			"assets/left.xpm", &a, &a);
	vars->wall_img = mlx_xpm_file_to_image(vars->mlx,
			"assets/wall.xpm", &a, &a);
}

void	initialize_vars(t_vars *vars)
{
	vars->mlx = mlx_init();
	vars->coins = 0;
	vars->points = 0;
	vars->moves = 0;
	vars->p_x = 0;
	vars->p_y = 0;
	vars->win_w = 0;
	vars->win_h = 0;
	initialize_images(vars);
}

int	main(int argc, char **argv)
{
	t_vars	vars;

	if (argc != 2)
	{
		write(2, "\033[1;31mError\033[0m", 16);
		ft_printf("\nNumber of arguments is not 2\n");
		exit(EXIT_FAILURE);
	}
	initialize_vars(&vars);
	check_filename(argv[1]);
	read_map(&vars, argv[1]);
	vars.win = mlx_new_window(vars.mlx, vars.win_w, vars.win_h, "so_long");
	display_map(&vars);
	mlx_hook(vars.win, 17, 1L << 17, on_close_win, &vars);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
