/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 12:52:15 by wonyocho          #+#    #+#             */
/*   Updated: 2024/01/10 19:45:03 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

// read .ber files
void	read_map_file(char *filename, t_game *game)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	line = get_next_line(fd);
	/* 맵 에러 체크 하는 함수 작성*/
	game->win_wid = ft_strlen(line) - 1;
	game->win_hei = 0;
	game->map_info = ft_strdup_no_nl(line);
	free(line);
	while (line)
	{
		game->win_hei++;
		line = get_next_line(fd);
		/* 맵 에러 체크 하는 함수 작성*/
		if (line == NULL)
			break ;
		delete_nl(line);
		if (line)
			game->map_info = ft_append(game->map_info, line);
		free(line);
	}
	close(fd);
}

void	delete_nl(char *str)
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
	size_t			len_src;
	unsigned int	i;

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

// int main()
// {
// 	char *s1 = ft_strdup_no_nl("hello\n");
// 	char *s2 = ft_strdup_no_nl("world\n");

// 	s1 = ft_strjoin_no_nl(s1, s2);
// 	printf("%s\n", s1);
// }