#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && s1[i] == s2[i] && (s1[i] || s2[i]))
		i++;
	if (i == n)
		return (0);
	else
		return ((unsigned char) s1[i] - (unsigned char) s2[i]);
}

#include "get_next_line.h"
int main(int argc, char** argv)
{
    char* fileName;
    int fd;
    int i;
	char *string;

	printf("File selezionato: %s\n", argv[1]);

	if (ft_strncmp(argv[1], "1", 2) == 0)
	{
		fileName = "1-brouette.txt";

		fd = open(fileName, O_RDWR);

		if(fd == -1)
			printf("\nError Opening File\n");
		else{
			printf("\nFile %s opened successfully\n", fileName);
		}

		string = get_next_line(fd);

		i = 0;
		while (string)
		{
			printf("-Riga %d: %s\n", ++i, string);
			free(string);
			string = get_next_line(fd);
		}
	}

	else if (ft_strncmp(argv[1], "2", 2) == 0)
	{
   		fileName = "2-otarie.txt";

    	fd = open(fileName, O_RDWR);

		if(fd == -1)
			printf("\nError Opening File\n");
		else{
			printf("\nFile %s opened successfully\n", fileName);
		}

		string = get_next_line(fd);

		i = 0;
		while (string)
		{
			printf("-Riga %d: %s\n", ++i, string);
			free(string);
			string = get_next_line(fd);
		}
	}

	else if (ft_strncmp(argv[1], "3", 2) == 0)
	{
		fileName = "3-oneline.txt";

		fd = open(fileName, O_RDWR);

		if(fd == -1)
			printf("\nError Opening File\n");
		else{
			printf("\nFile %s opened successfully\n", fileName);
		}

		string = get_next_line(fd);

		i = 0;
		while (string)
		{
			printf("-Riga %d: %s\n", ++i, string);
			free(string);
			string = get_next_line(fd);
		}
	}

	else if (ft_strncmp(argv[1], "4", 2) == 0)
	{
		fileName = "4-u.txt";

		fd = open(fileName, O_RDWR);

		if(fd == -1)
			printf("\nError Opening File\n");
		else{
			printf("\nFile %s opened successfully\n", fileName);
		}

		string = get_next_line(fd);

		i = 0;
		while (string)
		{
			printf("-Riga %d: %s\n", ++i, string);
			free(string);
			string = get_next_line(fd);
		}
	}

	else if (ft_strncmp(argv[1], "5", 2) == 0)
	{
		fileName = "5-empty.txt";

		fd = open(fileName, O_RDWR);

		if(fd == -1)
			printf("\nError Opening File\n");
		else{
			printf("\nFile %s opened successfully\n", fileName);
		}

		string = get_next_line(fd);

		i = 0;
		while (string)
		{
			printf("-Riga %d: %s\n", ++i, string);
			free(string);
			string = get_next_line(fd);
		}
	}

	else if (ft_strncmp(argv[1], "6", 2) == 0)
	{
		fileName = "6-newline.txt";

		fd = open(fileName, O_RDWR);

		if(fd == -1)
			printf("\nError Opening File\n");
		else{
			printf("\nFile %s opened successfully\n", fileName);
		}

		string = get_next_line(fd);

		i = 0;
		while (string)
		{
			printf("-Riga %d: %s\n", ++i, string);
			free(string);
			string = get_next_line(fd);
		}
	}

	else if (ft_strncmp(argv[1], "7", 2) == 0)
	{
		fileName = "7-onechar.txt";

		fd = open(fileName, O_RDWR);

		if(fd == -1)
			printf("\nError Opening File\n");
		else{
			printf("\nFile %s opened successfully\n", fileName);
		}

		string = get_next_line(fd);

		i = 0;
		while (string)
		{
			printf("-Riga %d: %s\n", ++i, string);
			free(string);
			string = get_next_line(fd);
		}
	}

	else if (ft_strncmp(argv[1], "8", 2) == 0)
	{
		fileName = "8-twochar.txt";

		fd = open(fileName, O_RDWR);

		if(fd == -1)
			printf("\nError Opening File\n");
		else{
			printf("\nFile %s opened successfully\n", fileName);
		}

		string = get_next_line(fd);

		i = 0;
		while (string)
		{
			printf("-Riga %d: %s\n", ++i, string);
			free(string);
			string = get_next_line(fd);
		}
	}

	else if (ft_strncmp(argv[1], "9", 2) == 0)
	{
		fileName = "9-linew.txt";

		fd = open(fileName, O_RDWR);

		if(fd == -1)
			printf("\nError Opening File\n");
		else{
			printf("\nFile %s opened successfully\n", fileName);
		}

		string = get_next_line(fd);

		i = 0;
		while (string)
		{
			printf("-Riga %d: %s\n", ++i, string);
			free(string);
			string = get_next_line(fd);
		}
	}

	else if (ft_strncmp(argv[1], "10", 2) == 0)
	{
		fileName = "10-b.txt";

		fd = open(fileName, O_RDWR);

		if(fd == -1)
			printf("\nError Opening File\n");
		else{
			printf("\nFile %s opened successfully\n", fileName);
		}

		string = get_next_line(fd);

		i = 0;
		while (string)
		{
			printf("-Riga %d: %s\n", ++i, string);
			free(string);
			string = get_next_line(fd);
		}
	}

	else if (ft_strncmp(argv[1], "11", 2) == 0)
	{
		fileName = "11-bg.txt";

		fd = open(fileName, O_RDWR);

		if(fd == -1)
			printf("\nError Opening File\n");
		else{
			printf("\nFile %s opened successfully\n", fileName);
		}

		string = get_next_line(fd);

		i = 0;
		while (string)
		{
			printf("-Riga %d: %s\n", ++i, string);
			free(string);
			string = get_next_line(fd);
		}
	}

	else if (ft_strncmp(argv[1], "12", 2) == 0)
	{
		fileName = "12-bigben.txt";

		fd = open(fileName, O_RDWR);

		if(fd == -1)
			printf("\nError Opening File\n");
		else{
			printf("\nFile %s opened successfully\n", fileName);
		}

		string = get_next_line(fd);

		i = 0;
		while (string)
		{
			printf("-Riga %d: %s\n", ++i, string);
			free(string);
			string = get_next_line(fd);
		}
	}

	else if (ft_strncmp(argv[1], "13", 2) == 0)
	{
		fileName = "13-personalized.txt";

		fd = open(fileName, O_RDWR);

		if(fd == -1)
			printf("\nError Opening File\n");
		else{
			printf("\nFile %s opened successfully\n", fileName);
		}

		string = get_next_line(fd);

		i = 0;
		while (string)
		{
			printf("-Riga %d: %s\n", ++i, string);
			free(string);
			string = get_next_line(fd);
		}
	}

	else
		printf("Error: the number is wrong");
    return 0;
}
