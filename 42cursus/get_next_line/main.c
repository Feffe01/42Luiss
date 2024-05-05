#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

//#include "get_next_line.h"
// int main(){

//     char* fileName = "1-brouette.txt";

//     int fd = open(fileName, O_RDWR);

//     if(fd == -1)
//         printf("\nError Opening File\n");
//     else{
//         printf("\nFile %s opened successfully\n", fileName);
//     }

//     char *string = get_next_line(fd);

//     int i = 0;
// 	while (string)
// 	{
// 		printf("Riga %d: %s\n-", ++i, string);
//         free(string);
// 		string = get_next_line(fd);
// 	}

//     return 0;
// }

#include "get_next_line_bonus.h"
int main(){

    char* fileName[] = {"1-brouette.txt", "2-otarie.txt"};

    int fd[] ={open(fileName[0], O_RDWR), open(fileName[1], O_RDWR)};

    int j = 0;

    if(fd[0] == -1 || fd[1] == -1)
        printf("\nError Opening File\n");
    else{
        printf("\nFiles opened successfully\n");
    }

    char *string = get_next_line(fd[j]);

    int i = 0;
	while (string)
	{
		printf("Riga %d: %s\n-", ++i, string);
        (j == 0) ? (j = 1) : (j = 0);
		string = get_next_line(fd[j]);
	}

    return 0;
}
