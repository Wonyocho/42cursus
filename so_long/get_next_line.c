/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 11:43:43 by wonyocho          #+#    #+#             */
/*   Updated: 2024/01/11 17:26:17 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*ft_append(char *saved_line, char *buf)
{
	char	*temp;

	temp = ft_strjoin(saved_line, buf);
	free(saved_line);
	return (temp);
}

static char	*read_file(int fd, char *saved_line)
{
	char	*buf;
	int		read_byte;

	if (!saved_line)
		saved_line = ft_calloc(1, sizeof(char));
	buf = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buf)
		return (NULL);
	read_byte = 1;
	while (read_byte > 0)
	{
		read_byte = read(fd, buf, BUFFER_SIZE);
		if (read_byte == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[read_byte] = '\0';
		saved_line = ft_append(saved_line, buf);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	free(buf);
	return (saved_line);
}

static char	*ft_line(char *saved_line)
{
	char	*line;
	int		i;

	i = 0;
	if (!saved_line[i])
		return (NULL);
	while (saved_line[i] && saved_line[i] != '\n')
		i++;
	if (!(ft_strchr(saved_line, '\n')))
		line = ft_calloc(i + 1, sizeof(char));
	else
		line = ft_calloc(i + 2, sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (saved_line[i] && saved_line[i] != '\n')
	{
		line[i] = saved_line[i];
		i++;
	}
	if (saved_line[i] && saved_line[i] == '\n')
		line[i] = '\n';
	return (line);
}

static char	*ft_next(char *saved_line)
{
	int		i;
	int		j;
	char	*leftover;

	i = 0;
	while (saved_line[i] && saved_line[i] != '\n')
		i++;
	if (!saved_line[i])
	{
		free(saved_line);
		return (NULL);
	}
	leftover = ft_calloc((ft_strlen(saved_line) - i + 1), sizeof(char));
	if (!leftover)
	{
		free (saved_line);
		saved_line = NULL;
		return (NULL);
	}
	i++;
	j = 0;
	while (saved_line[i])
		leftover[j++] = saved_line[i++];
	free(saved_line);
	return (leftover);
}

char	*get_next_line(int fd)
{
	static char	*saved_line;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) == -1)
	{
		free (saved_line);
		saved_line = NULL;
		return (NULL);
	}
	saved_line = read_file(fd, saved_line);
	if (!saved_line)
	{
		free (saved_line);
		saved_line = NULL;
		return (NULL);
	}
	line = ft_line(saved_line);
	if (!line)
	{
		free (saved_line);
		saved_line = NULL;
		return (NULL);
	}
	saved_line = ft_next(saved_line);
	return (line);
}
