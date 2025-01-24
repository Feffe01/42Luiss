/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgiampa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 17:21:18 by fgiampa           #+#    #+#             */
/*   Updated: 2025/01/23 17:21:19 by fgiampa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_matrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
	return ;
}

char	*my_getenv(char **env, char *word)
{
	int	word_len;
	int	i;

	word_len = ft_strlen(word);
	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], word, word_len) == 0)
			return (env[i] + word_len);
		i++;
	}
	perror("PATH not found in environment");
	exit(1);
}

char	*find_path(char **cmd, char **env)
{
	char	*path_str;
	char	*cmd_str;
	char	**paths;
	int		i;

	path_str = my_getenv(env, "PATH=");
	paths = ft_split(path_str, ':');
	i = 0;
	while (paths[i])
	{
		path_str = ft_strjoin(paths[i], "/");
		cmd_str = ft_strjoin(path_str, cmd[0]);
		free(path_str);
		if (access(cmd_str, F_OK | X_OK) == 0)
		{
			free_matrix(paths);
			return (cmd_str);
		}
		free(cmd_str);
		i++;
	}
	free_matrix(paths);
	free_matrix(cmd);
	perror("Command not found");
	exit(127);
}
