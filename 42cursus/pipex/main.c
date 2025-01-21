#include "pipex.h"

int main()
{
	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int arrSize = sizeof(arr) / sizeof(int);
	int start, end;
	int fd[2];
	if (pipe(fd) == -1)
	{
		ft_printf("Pipe failed");
		return 1;
	}
	
	int id = fork();
	if (id == -1)
	{
		ft_printf("Fork failed");
		return 2;
	}

	if (id == 0)
	{
		start = 0;
		end = arrSize / 2;
	}
	else
	{
		start = arrSize / 2;
		end = arrSize;
	}

	int sum = 0;
	int i;
	for (i = start; i < end; i++)
		sum += arr[i];

	ft_printf("Partial sum: %d\n", sum);

	if (id == 0)
	{
		close(fd[0]);
		write(fd[1], &sum, sizeof(sum));
		close(fd[1]);
	}
	else
	{
		int sumfromchild;
		close(fd[1]);
		read(fd[0], &sumfromchild, sizeof(sumfromchild));
		close(fd[0]);

		int total = sum + sumfromchild;
		ft_printf("Total: %d\n", total);
		wait(NULL);
	}

	return 0;
}