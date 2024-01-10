/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:47:39 by wonyocho          #+#    #+#             */
/*   Updated: 2024/01/10 19:43:42 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>
# include <fcntl.h>
# include <mlx.h>

typedef struct s_game
{
	char	*map_info;
	int		win_wid;
	int		win_hei;
}t_game;

typedef struct s_data_img
{
	int		img_wid;
	int		img_hei;
	void	*img_tile;
	void	*img_wall;
	void	*img_item;
	void	*img_goal;
	void	*img_player;
}t_data_img;

// GET_NEXT_LINE
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 20
# endif

char	*ft_append(char *saved_line, char *buf);
char	*get_next_line(int fd);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *str, int c);
void	*ft_calloc(size_t count, size_t size);
size_t	ft_strlen(const char *str);

// map_read_files.c
void	setting_map(void *mlx, void *win, t_game *game, t_data_img *imgs);
void	read_map_file(char *filename, t_game *game);
void	delete_nl(char *str);
char	*ft_strdup_no_nl(const char *s1);

// map_make.c
void	setting_map(void *mlx, void *win, t_game *game, t_data_img *imgs);
void	fill_with_tiles(void *mlx, void *win, t_game *game, t_data_img *imgs);
void	get_img_data(void *mlx, t_data_img *imgs);
void	put_elements(void *mlx, void *win, t_game *game, t_data_img *imgs);

#endif