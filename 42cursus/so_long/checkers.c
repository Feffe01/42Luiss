/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgiampa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 17:47:50 by fgiampa           #+#    #+#             */
/*   Updated: 2024/12/28 17:47:55 by fgiampa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_walls(char **map)
{
	int	lines_num;
	int	lines_len;
	int	i;
	int	j;

	lines_num = matrix_height(map);
	lines_len = ft_strlen(map[0]);
	i = 0;
	while (map[i])
	{
		if (i == 0 || i == lines_num - 1)
		{
			j = 0;
			while (map[i][j] == '1')
				j++;
			if (j != lines_len)
				error_map("Map is not surrounded by walls (top or bottom)");
		}
		else
		{
			if (map[i][0] != '1' || map[i][lines_len - 1] != '1')
				error_map("Map is not surrounded by walls (left or right)");
		}
		i++;
	}
}

void	check_form(char **map)
{
	int	firstlen;
	int	len;
	int	i;

	firstlen = ft_strlen(map[0]);
	i = 1;
	while (map[i])
	{
		len = ft_strlen(map[i]);
		if (len != firstlen)
			error_map("Map is not rectangular");
		i++;
	}
}

void	check_quantities(int coins, int starts, int exits)
{
	if (coins < 1)
		error_map("There are not collectibles C");
	if (starts < 1)
		error_map("There is not a starting point P");
	if (starts > 1)
		error_map("More than one starting point P found");
	if (exits < 1)
		error_map("There is not a map exit E");
	if (exits > 1)
		error_map("More than one map exit E found");
}

void	check_contents(char *map_string)
{
	int	coins;
	int	starts;
	int	exits;
	int	i;

	coins = 0;
	starts = 0;
	exits = 0;
	i = 0;
	while (map_string[i])
	{
		if (map_string[i] == 'C')
			coins++;
		else if (map_string[i] == 'P')
			starts++;
		else if (map_string[i] == 'E')
			exits++;
		else if (map_string[i] != '\n' && map_string[i] != '1'
			&& map_string[i] != '0')
			error_map(ft_strjoin("Character not valid: ", &map_string[i]));
		i++;
	}
	check_quantities(coins, starts, exits);
}

void	check_filename(char *filepath)
{
	size_t	len;
	char	**path;
	char	*filename;

	path = ft_split(filepath, '/');
	filename = path[matrix_height(path) - 1];
	len = ft_strlen(filename);
	if (filename[len - 1] != 'r')
		error_filename("File type is not .ber");
	if (filename[len - 2] != 'e')
		error_filename("File type is not .ber");
	if (filename[len - 3] != 'b')
		error_filename("File type is not .ber");
	if (filename[len - 4] != '.')
		error_filename("File type is not .ber");
	if (!filename[len - 5])
		error_filename("File name not valid");
	free_matrix(path);
}
