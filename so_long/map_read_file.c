/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 12:52:15 by wonyocho          #+#    #+#             */
/*   Updated: 2024/01/17 20:35:20 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	delete_nl(char *str);
static void	append_lines(t_game *g, char *line, int fd);

void	read_map_file(char *filename, t_game *g)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		print_exit("Error\nFile open fail.");
	line = get_next_line(fd);
	if (line == NULL)
		print_exit("Error\nFile open fail.");
	g->win_wid = ft_strlen(line) - 1;
	g->win_hei = 0;
	g->map = ft_strdup_no_nl(line);
	free(line);
	append_lines(g, line, fd);
	map_error_check(g);
	close(fd);
}

static void	append_lines(t_game *g, char *line, int fd)
{
	while (line)
	{
		g->win_hei++;
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		delete_nl(line);
		if (line)
			g->map = ft_append(g->map, line);
		free(line);
	}
}

static void	delete_nl(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			str[i] = '\0';
		i++;
	}
}

char	*ft_strdup_no_nl(const char *s1)
{
	char			*dst;
	unsigned char	*src;
	unsigned int	i;
	size_t			len_src;

	i = 0;
	src = (unsigned char *)s1;
	len_src = ft_strlen(s1);
	dst = (char *)malloc(len_src + 1);
	if (!(dst))
		return (0);
	else
	{
		while (src[i] && src[i] != '\n')
		{
			dst[i] = src[i];
			i++;
		}
	}
	dst[i] = '\0';
	return (dst);
}
