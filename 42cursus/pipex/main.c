#include "pipex.h"

char	*find_path(char *cmd, char **env)
{

}

void	child1(int *fd, char *infile, char *cmd_str)
{
	int					file;
	extern char	**environ;
	char				**cmd;

	file = open(infile, O_RDONLY);
	if (file == -1)
	{
		perror("Error opening infile");
		exit(1);
	}
	cmd = ft_split(cmd_str, ' ');
	dup2(file, STDIN_FILENO);
	close(file);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[0]);
	close(fd[1]);
	execve(find_path(cmd[0], environ), cmd, environ);
	free(cmd);
	perror("Error executing child1");
	exit(1);
}

void	child2(int *fd, char *outfile, char **cmd)
{
	int	file;
	extern char **environ;

	file = open(outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (file == -1)
	{
		perror("Error opening infile");
		exit(1);
	}
	dup2(file, STDOUT_FILENO);
	close(file);
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	close(fd[1]);
	execve(cmd[0], cmd, environ);
	perror("Error executing child2");
	exit(1);
}

int	main(int argc, char **argv)
{
	int	fd[2];
	int	pid1;
	int	pid2;

	if (argc !=  5)
		return 1;
	if (pipe(fd) == -1)
		return 2;
	pid1 = fork();
	if (pid1 < 0)
		return 3;
	if(pid1 == 0)
		child1(fd, argv[1], argv[2]);
	pid2 = fork();
	if (pid2 < 0)
		return 4;
	if(pid2 == 0)
		child2(fd, argv[4], argv[3]);
	close(fd[0]);
	close(fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return 0;
}
