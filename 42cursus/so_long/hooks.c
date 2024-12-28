/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgiampa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 17:49:19 by fgiampa           #+#    #+#             */
/*   Updated: 2024/12/28 17:49:22 by fgiampa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	on_close_win(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
}

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == ESC_KEY)
		on_close_win(vars);
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
