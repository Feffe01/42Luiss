#include "so_long.h"

void update_mapString(char **mapString, char *line)
{
	char *newMapString;

	newMapString = ft_strjoin(*mapString, line);
	free(*mapString);
	*mapString = newMapString;
}

void scan_map(t_vars *vars, char **map)
{
	int i;
	int j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				vars->playerY = i;
				vars->playerX = j;
			}
			if (map[i][j] == 'C')
				vars->coins += 1;
			j++;
		}
		vars->WinWidth = j * PIXELS;
		i++;
	}
	vars->WinHeight = i * PIXELS;
}

void read_map(t_vars *vars, char *filepath)
{
	int fd;
	char *mapString;
	char **map;
	char *line;

	fd = open(filepath, O_RDONLY);
	if (fd == -1)
	{
		perror("\033[1;31mError\033[0m\nFile can't be opened");
		exit(EXIT_FAILURE);
	}
	line = "";
	mapString = ft_calloc(1, 1);
	while (line)
	{
		line = get_next_line(fd);
		if (line != NULL)
			update_mapString(&mapString, line);
		free(line);
	}
	ft_printf("map: \n%s\n\n", mapString);
	if (!mapString[0])
		error_map("Map doesn't exist");
	map = ft_split(mapString, '\n');
	check_contents(mapString);
	check_form(map);
	check_walls(map);
	scan_map(vars, map);
	check_path(mapString, vars);
	vars->map = map;
	free(mapString);
}