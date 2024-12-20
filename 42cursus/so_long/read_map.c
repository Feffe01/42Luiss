#include "so_long.h"

void check_contents(char *map)
{
	int coins;
	int starts;
	int exits;
	int i;

	if (!map[0])
		error_map("Map doesn't exist");
	coins = 0;
	starts = 0;
	exits = 0;
	i = 0;
	while (map[i])
	{
		if (map[i] == 'C')
			coins++;
		else if (map[i] == 'P')
			starts++;
		else if (map[i] == 'E')
			exits++;
		else if (map[i] != '\n' && map[i] != '1' && map[i] != '0')
			error_map(ft_strjoin(ft_strjoin("The character ", &map[i]), " is not valid"));
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

char *read_map(char *filepath)
{
	int fd;
	char *map;
	char *line;

	fd = open(filepath, O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening the file");
		exit(EXIT_FAILURE);
	}
	line = "";
	map = "";
	while (line)
	{
		line = get_next_line(fd);
		ft_printf("%s\n", line);
		if (line != NULL)
			map = ft_strjoin(map, line);
	}
	ft_printf("map: %s\n", map);
	check_contents(map);
	// check_form(map);
	// check_walls(map);
	// check_path(map);
	return(map);
}