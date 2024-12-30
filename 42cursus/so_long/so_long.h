/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgiampa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 17:51:25 by fgiampa           #+#    #+#             */
/*   Updated: 2024/12/28 17:51:29 by fgiampa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include <mlx.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define W_KEY 119
# define A_KEY 97
# define S_KEY 115
# define D_KEY 100
# define ESC_KEY 65307
# define PIXELS 64

typedef struct s_checker
{
	int	check_c;
	int	check_e;
}	t_checker;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	char	**map;
	int		p_x;
	int		p_y;
	int		coins;
	int		points;
	int		moves;
	char	*coin_img;
	char	*exit_img;
	char	*floor_img;
	char	*down_img;
	char	*up_img;
	char	*left_img;
	char	*right_img;
	char	*wall_img;
	int		win_w;
	int		win_h;
}	t_vars;

int		on_close_win(t_vars *vars);
int		key_hook(int keycode, t_vars *vars);
int		matrix_height(char **array);
void	error_filename(char *description);
void	error_map(char *description);
void	read_map(t_vars *vars, char *filepath);
void	check_path(char *map_string, t_vars *vars);
void	check_walls(char **map);
void	check_form(char **map);
void	check_contents(char *map_string);
void	check_filename(char *filepath);
void	display_map(t_vars *vars);
void	put_image(t_vars *vars, char type, int x, int y);
void	go_up(t_vars *vars);
void	go_down(t_vars *vars);
void	go_left(t_vars *vars);
void	go_right(t_vars *vars);
void	game_over(t_vars *vars);
void	free_matrix(char **matrix);

#endif
