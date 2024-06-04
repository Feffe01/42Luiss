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

#include "get_next_line_bonus.h"
int main(){

    char* fileName[] = {"12-bigben.txt", "9-linew.txt"};

    int fd[] ={open(fileName[0], O_RDWR), open(fileName[1], O_RDWR)};

    if(fd[0] == -1 || fd[1] == -1)
        printf("\nError Opening File\n");
    else{
        printf("\nFiles opened successfully\n");
    }

    int x = 0;
	int y = 0;
    int j = 0;
    char *string = get_next_line(fd[j]);
	while (string)
	{
		printf("-Riga %d: %s\n", (j == 0) ? ++x : ++y, string);
        (j == 0) ? (j = 1) : (j = 0);
		string = get_next_line(fd[j]);
	}

    return 0;
}
