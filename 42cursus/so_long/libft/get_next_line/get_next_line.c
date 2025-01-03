/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgiampa <fgiampa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 16:02:01 by fgiampa           #+#    #+#             */
/*   Updated: 2024/06/04 15:14:55 by fgiampa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_next_line(char *container)
{
	int		i;
	int		j;
	char	*new_cont;

	i = 0;
	while (container[i] && container[i] != '\n')
		i++;
	if (container[i] == '\n')
		i++;
	new_cont = ft_calloc_gnl(gnl_strlen(container) - i + 1, sizeof(char));
	j = 0;
	while (container[i])
	{
		new_cont[j++] = container[i];
		i++;
	}
	free(container);
	return (new_cont);
}

char	*ft_create_line(char *container)
{
	int		i;
	char	*betterline;

	i = 0;
	while (container[i] && container[i] != '\n')
		i++;
	if (container[i] == '\n')
		i++;
	betterline = ft_calloc_gnl(i + 1, sizeof(char));
	i = 0;
	while (container[i] && container[i] != '\n')
	{
		betterline[i] = container[i];
		i++;
	}
	if (container[i] == '\n')
		betterline[i] = '\n';
	return (betterline);
}

char	*ft_read_line(int fd, char *container)
{
	int		bytes_read;
	char	*buffer;

	if (!container)
		container = ft_calloc_gnl(1, 1);
	buffer = ft_calloc_gnl(BUFFER_SIZE + 1, sizeof(char));
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytes_read] = 0;
		container = ft_strjoin_gnl(container, buffer);
		if (gnl_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (container);
}

char	*get_next_line(int fd)
{
	static char	*container[OPEN_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	container[fd] = ft_read_line(fd, container[fd]);
	if (!container[fd] || container[fd][0] == 0)
	{
		free(container[fd]);
		return (NULL);
	}
	line = ft_create_line(container[fd]);
	container[fd] = ft_next_line(container[fd]);
	return (line);
}
