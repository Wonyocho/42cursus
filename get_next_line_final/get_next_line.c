/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 11:43:43 by wonyocho          #+#    #+#             */
/*   Updated: 2023/11/14 16:25:37 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_append(char *saved_line, char *buf)
{
	char	*temp;

	temp = ft_strjoin(saved_line, buf);
	free(saved_line);
	return (temp);
}

char	*read_file(int fd, char *saved_line)
{
	char	*buf;
	int		read_byte;

	if (!saved_line)
	{
		saved_line = ft_calloc(1, sizeof(char));
		if (!saved_line)
			return (NULL);
	}
	buf = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buf)
	{
		free(saved_line);
		saved_line = NULL;
		return (NULL);
	}
	read_byte = 1;
	while (read_byte > 0)
	{
		read_byte = read(fd, buf, BUFFER_SIZE);
		if (read_byte == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[read_byte] = 0;
		saved_line = ft_append(saved_line, buf);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	free(buf);
	return (saved_line);
}

char	*ft_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!(ft_strchr(buffer, '\n')))
	{
		line = ft_calloc(i + 1, sizeof(char));
		if (!line)
			return (NULL);
	}
	else
	{
		line = ft_calloc(i + 2, sizeof(char));
		if (!line)
			return (NULL);
	}
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] && buffer[i] == '\n')
		line[i] = '\n';
	return (line);
}

char	*ft_next(char *buffer)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	line = ft_calloc((ft_strlen(buffer) - i + 1), sizeof(char));
	if (!line)
		return (NULL);
	i++;
	j = 0;
	while (buffer[i])
		line[j++] = buffer[i++];
	free(buffer);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*saved_line;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) == -1)
	{
		free(saved_line);
		saved_line = NULL;
		return (NULL);
	}
	saved_line = read_file(fd, saved_line);
	if (!saved_line)
		return (NULL);
	line = ft_line(saved_line);
	if (!line)
	{
		free (saved_line);
		saved_line = NULL;
		return (NULL);
	saved_line = ft_next(saved_line);
	return (line);
}
