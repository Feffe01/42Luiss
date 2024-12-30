/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgiampa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 17:42:56 by fgiampa           #+#    #+#             */
/*   Updated: 2024/12/28 17:43:38 by fgiampa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_moves(char **map, int x, int y, t_checker *check)
{
	if (map[y][x] == 'C')
		check->check_c += 1;
	if (map[y][x] == 'E')
		check->check_e = 1;
	if (map[y][x] == '1')
		return ;
	else
		map[y][x] = '1';
	check_moves(map, x + 1, y, check);
	check_moves(map, x - 1, y, check);
	check_moves(map, x, y + 1, check);
	check_moves(map, x, y - 1, check);
}

void	check_path(char *map_string, t_vars *vars)
{
	t_checker	check;
	char		**map_copy;

	check.check_c = 0;
	check.check_e = 0;
	map_copy = ft_split(map_string, '\n');
	check_moves(map_copy, vars->p_x, vars->p_y, &check);
	free_matrix(map_copy);
	if (check.check_c != vars->coins || check.check_e == 0)
		error_map("There is not a valid path");
	else
		ft_printf("Valid path found\n\n");
}
