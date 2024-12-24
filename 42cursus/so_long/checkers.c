#include "so_long.h"

void check_walls(char **map)
{
	int numOfLines;
	int linesLen;
	int i;
	int j;

	numOfLines = matrix_height(map);
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

void check_filename (char *filepath)
{
	size_t len;
	char **path;
	char *filename;

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