/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   displayer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgiampa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 17:48:43 by fgiampa           #+#    #+#             */
/*   Updated: 2024/12/28 17:48:46 by fgiampa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_image(t_vars *vars, char type, int x, int y)
{
	if (type != '1')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->floor_img, x, y);
	else
		mlx_put_image_to_window(vars->mlx, vars->win, vars->wall_img, x, y);
	if (type == 'U')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->up_img, x, y);
	if (type == 'D' || type == 'P')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->down_img, x, y);
	if (type == 'L')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->left_img, x, y);
	if (type == 'R')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->right_img, x, y);
	if (type == 'C')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->coin_img, x, y);
	if (type == 'E')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->exit_img, x, y);
}

void	display_map(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	while (vars->map[i])
	{
		j = 0;
		while (vars->map[i][j])
		{
			put_image(vars, vars->map[i][j], j * PIXELS, i * PIXELS);
			j++;
		}
		i++;
	}
}
