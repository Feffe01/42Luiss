/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgiampa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 17:50:51 by fgiampa           #+#    #+#             */
/*   Updated: 2024/12/28 17:50:53 by fgiampa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update_mapstring(char **mapstring, char *line)
{
	char	*newmapstring;

	newmapstring = ft_strjoin(*mapstring, line);
	free(*mapstring);
	*mapstring = newmapstring;
}

void	scan_map(t_vars *vars, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				vars->p_y = i;
				vars->p_x = j;
			}
			if (map[i][j] == 'C')
				vars->coins += 1;
			j++;
		}
		vars->win_w = j * PIXELS;
		i++;
	}
	vars->win_h = i * PIXELS;
}

void	check_map(t_vars *vars, char *mapstring)
{
	char	**map;

	if (!mapstring[0])
		error_map("Map doesn't exist");
	ft_printf("map: \n%s\n\n", mapstring);
	map = ft_split(mapstring, '\n');
	check_contents(mapstring);
	check_form(map);
	check_walls(map);
	scan_map(vars, map);
	check_path(mapstring, vars);
	vars->map = map;
	free(mapstring);
}

void	read_map(t_vars *vars, char *filepath)
{
	int		fd;
	char	*mapstring;
	char	*line;

	fd = open(filepath, O_RDONLY);
	if (fd == -1)
	{
		perror("\033[1;31mError\033[0m\nFile can't be opened");
		exit(EXIT_FAILURE);
	}
	line = "";
	mapstring = ft_calloc(1, 1);
	while (line)
	{
		line = get_next_line(fd);
		if (line != NULL)
			update_mapstring(&mapstring, line);
		free(line);
	}
	check_map(vars, mapstring);
}
