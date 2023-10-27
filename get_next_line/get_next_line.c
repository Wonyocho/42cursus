/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 13:39:47 by wonyocho          #+#    #+#             */
/*   Updated: 2023/10/27 14:16:16 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_saving_line(int fd, char *saved_line)
{
	char	*buf;
	int		read_byte;

	read_byte = 1;
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	while (!(ft_strchr(saved_line, '\n')) && read_byte != 0)
	{
		read_byte = read(fd, buf, BUFFER_SIZE);
		if (read_byte == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[read_byte] = '\0';
		saved_line = ft_strjoin(saved_line, buf);
	}
	free(buf);
	return (saved_line);
}

char	*ft_get_line(char *saved_line)
{
	char	*result;
	int		i;
	int		n;

	i = 0;
	n = 0;
	while (saved_line[i] != '\n')
		i++;
	result = (char *)malloc(sizeof(char) * i);
	if (!result)
		return (NULL);
	while (n < i)
	{
		result[n] = saved_line[n];
		n++;
	}
	result[n] = '\0';
	return (result);
}

char	*ft_leftover(char *saved_line)
{
	char	*leftover;
	int		i;
	int		n;

	i = 0;
	n = 0;
	while (saved_line[i] != '\n' && saved_line[i])
		i++;
	leftover = (char *)malloc(sizeof(char) * ft_strlen(saved_line) - i);
	if (!leftover)
		return (NULL);
	i++;
	while (saved_line[i])
	{
		leftover[n] = saved_line[i];
		n++;
		i++;
	}
	return (leftover);
}

char	*get_next_line(int fd)
{
	static char	*saved_line;
	char		*line;

	if (fd == -1 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!saved_line)
		saved_line = ft_strdup("");
	saved_line = ft_saving_line(fd, saved_line);
	if (!saved_line)
		return (NULL);
	line = ft_get_line(saved_line);
	saved_line = ft_leftover(saved_line);
	return (line);
}

// int	main (void)
// {
// 	int	fd;

// 	fd = open("test.txt", O_RDONLY);
// 	printf("1) GNL 1:%s\n", get_next_line(fd));
// 	printf("1) GNL 2:%s\n", get_next_line(fd));
// 	printf("1) GNL 3:%s\n", get_next_line(fd));
// 	printf("1) GNL 4:%s\n", get_next_line(fd));
// 	printf("1) GNL 5:%s\n", get_next_line(fd));
// 	printf("1) GNL 6:%s\n", get_next_line(fd));
// }
