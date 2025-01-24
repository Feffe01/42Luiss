/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgiampa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 17:20:55 by fgiampa           #+#    #+#             */
/*   Updated: 2025/01/23 17:21:00 by fgiampa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child1(int *fd, char *infile, char *cmd_str)
{
	extern char	**environ;
	int			file;
	char		**cmd;

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
	free_matrix(cmd);
	perror("Error executing child1");
	exit(1);
}

void	child2(int *fd, char *outfile, char *cmd_str)
{
	extern char	**environ;
	int			file;
	char		**cmd;

	file = open(outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (file == -1)
	{
		perror("Error opening outfile");
		exit(1);
	}
	cmd = ft_split(cmd_str, ' ');
	dup2(file, STDOUT_FILENO);
	close(file);
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	close(fd[1]);
	execve(find_path(cmd[0], environ), cmd, environ);
	free_matrix(cmd);
	perror("Error executing child2");
	exit(1);
}

int	check_status(int pid1, int pid2)
{
	int	status;

	waitpid(pid1, NULL, 0);
	if (waitpid(pid2, &status, 0) == -1)
		return (1);
	if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
		return (WEXITSTATUS(status));
	return (0);
}

int	main(int argc, char **argv)
{
	int	fd[2];
	int	pid1;
	int	pid2;

	if (argc != 5)
		return (1);
	if (pipe(fd) == -1)
		return (1);
	pid1 = fork();
	if (pid1 < 0)
		return (1);
	if (pid1 == 0)
		child1(fd, argv[1], argv[2]);
	pid2 = fork();
	if (pid2 < 0)
		return (1);
	if (pid2 == 0)
		child2(fd, argv[4], argv[3]);
	close(fd[0]);
	close(fd[1]);
	return (check_status(pid1, pid2));
}
