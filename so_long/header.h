/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:47:39 by wonyocho          #+#    #+#             */
/*   Updated: 2024/01/11 19:01:53 by wonyocho         ###   ########.fr       */
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
	void	*mlx;
	void	*win;
	char	*map;
	int		win_wid;
	int		win_hei;
	int		player_x;
	int		player_y;

	int		img_wid;
	int		img_hei;
	void	*img_tile;
	void	*img_wall;
	void	*img_item;
	void	*img_goal;
	void	*img_player;

	int		item_count;
}t_game;

// GET_NEXT_LINE
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 20
# endif

char		*ft_append(char *saved_line, char *buf);
char		*get_next_line(int fd);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strchr(const char *str, int c);
void		*ft_calloc(size_t count, size_t size);
int			ft_strlen(const char *str);

// map_read_files.c
void		read_map_file(char *filename, t_game *g);
static void	delete_nl(char *str);
static char	*ft_strdup_no_nl(const char *s1);

// map_make.c
void		setting_map(t_game *g);
void		get_img_data(t_game *g);
void		fill_with_tiles(t_game *g);
void		put_elements(t_game *g);

// key_hook.c
int			key_hook(int keycode, t_game *g);
static void	move_w(t_game *g);
static void	move_a(t_game *g);
static void	move_s(t_game *g);
static void	move_d(t_game *g);

// play_clear.c
void		game_clear(t_game *g, int item_ingame_count);

#endif