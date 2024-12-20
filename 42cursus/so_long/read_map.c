#include "so_long.h"

void find_player(t_vars *vars, char **map)
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
			j++;
		}
		i++;
	}
}

void check_walls(char **map)
{
	int numOfLines;
	int linesLen;
	int i;
	int j;

	numOfLines = array_len(map);
	linesLen = ft_strlen(map[0]);
	if (numOfLines < 3)
		error_map("Map is not surrounded by walls");
	i = 0;
	while (map[i])
	{
		if (i == 0 || i == numOfLines - 1)
		{
			j = 0;
			while (map[i][j] == '1')
				j++;
			if (j != linesLen)
				error_map("Map is not surrounded by walls (top or bot)");
		}
		else
		{
			if (map[i][0] != '1' || map[i][linesLen - 1] != '1')
				error_map("Map is not surrounded by walls (left or right)");
		}
		i++;
	}
}

void check_form(char **map)
{
	int firstlen;
	int len;
	int i;

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

void check_contents(char *mapString)
{
	int coins;
	int starts;
	int exits;
	int i;

	coins = 0;
	starts = 0;
	exits = 0;
	i = 0;
	while (mapString[i])
	{
		if (mapString[i] == 'C')
			coins++;
		else if (mapString[i] == 'P')
			starts++;
		else if (mapString[i] == 'E')
			exits++;
		else if (mapString[i] != '\n' && mapString[i] != '1' && mapString[i] != '0')
			error_map(ft_strjoin(ft_strjoin("The character ", &mapString[i]), " is not valid"));
		i++;
	}
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
	mapString = "";
	while (line)
	{
		line = get_next_line(fd);
		if (line != NULL)
			mapString = ft_strjoin(mapString, line);
	}
	ft_printf("map: \n%s\n\n", mapString);
	if (!mapString[0])
		error_map("Map doesn't exist");
	map = ft_split(mapString, '\n');
	check_contents(mapString);
	check_form(map);
	check_walls(map);
	find_player(vars, map);
	check_path(map, vars->playerX, vars->playerY);
	vars->map = map;
}