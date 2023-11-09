/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 13:39:47 by wonyocho          #+#    #+#             */
/*   Updated: 2023/11/09 12:52:36 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*keep_read(int fd, char *line)
{
	char	*buf;
	int		read_byte;

	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	read_byte = read(fd, buf, BUFFER_SIZE);
	if (read_byte == -1 || read_byte == 0)
		return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*line;
}
