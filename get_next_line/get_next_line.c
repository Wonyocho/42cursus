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


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajordan- <ajordan-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 10:12:14 by ajordan-          #+#    #+#             */
/*   Updated: 2021/10/20 10:04:09 by ajordan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
*	GET_NEXT_LINE
*	-------------
*	DESCRIPTION
*	This function takes an opened file descriptor and returns its next line.
*	This function has undefined behavior when reading from a binary file.
*	PARAMETERS
*	#1. A file descriptor 
*	RETURN VALUES
*	If successful, get_next_line returns a string with the full line ending in
*	a line break (`\n`) when there is one. 
*	If an error occurs, or there's nothing more to read, it returns NULL.
*	----------------------------------------------------------------------------
*	AUXILIARY FUNCTIONS
*	-------------------
*	READ_TO_LEFT_STR
*	-----------------
*	DESCRIPTION
*	Takes the opened file descriptor and saves on a "buff" variable what readed
*	from it. Then joins it to the cumulative static variable for the persistence
*	of the information.
*	PARAMETERS
*	#1. A file descriptor.
*	#2. The pointer to the cumulative static variable from previous runs of
*	get_next_line.
*	RETURN VALUES
*	The new static variable value with buffer joined for the persistence of the info,
*	or NULL if error.
*/

#include "get_next_line.h"
#include <unistd.h>
//#include <stdio.h>
//#include <fcntl.h>

char	*ft_read_to_left_str(int fd, char *left_str)
{
	char	*buff;
	int		rd_bytes;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	rd_bytes = 1;
	while (!ft_strchr(left_str, '\n') && rd_bytes != 0)
	{
		rd_bytes = read(fd, buff, BUFFER_SIZE);
		if (rd_bytes == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[rd_bytes] = '\0';
		left_str = ft_strjoin(left_str, buff);
	}
	free(buff);
	return (left_str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*left_str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	left_str = ft_read_to_left_str(fd, left_str);
	if (!left_str)
		return (NULL);
	line = ft_get_line(left_str);
	left_str = ft_new_left_str(left_str);
	return (line);
}

/*int	main(void)
{
	char	*line;
	int		i;
	int		fd1;
	int		fd2;
	int		fd3;
	fd1 = open("tests/test.txt", O_RDONLY);
	fd2 = open("tests/test2.txt", O_RDONLY);
	fd3 = open("tests/test3.txt", O_RDONLY);
	i = 1;
	while (i < 7)
	{
		line = get_next_line(fd1);
		printf("line [%02d]: %s", i, line);
		free(line);
		line = get_next_line(fd2);
		printf("line [%02d]: %s", i, line);
		free(line);
		line = get_next_line(fd3);
		printf("line [%02d]: %s", i, line);
		free(line);
		i++;
	}
	close(fd1);
	close(fd2);
	close(fd3);
	return (0);
}*/
