/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:47:39 by wonyocho          #+#    #+#             */
/*   Updated: 2024/01/17 20:55:53 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
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
	int		c_count;
	int		valid_c_count;
	int		walk_count;
	int		flag;
}t_game;

char		**ft_split(const char *s, char c);
int			ft_memcmp(const void *s1, const void *s2, size_t n);

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

// FT_PRINTF
int			ft_printf(const char *format, ...);
int			ft_putnbr(int n, int count);
int			ft_putnbr_u(unsigned int n, int count);
int			print_char(va_list ap, int count);
int			print_string(va_list ap, int count);
int			print_decimal_integer(va_list ap, int count);
int			print_unsigned_integer(va_list ap, int count);

// map_error_check.c
void		map_error_check(t_game *g);
// map_valid_path.c
int			find_player(t_game *g);
int			check_valid_path(t_game *g, int i, char *map_copy);

// map_read_files.c
void		read_map_file(char *filename, t_game *g);
char		*ft_strdup_no_nl(const char *s1);

// map_make.c
void		setting_map(t_game *g);
void		fill_with_tiles(t_game *g);
void		put_elements(t_game *g);

// map_rendering.c
void		render(t_game *g, char key);

// play_key_hook.c
int			hook_key_press(int keycode, t_game *g);

// main.c
void		print_exit(char *msg);
#endif