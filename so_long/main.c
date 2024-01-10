/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 19:22:06 by wonyocho          #+#    #+#             */
/*   Updated: 2024/01/10 19:54:20 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	1. read_map_file -> map.ber 파일에서 GNL로 map_info에 저장
	2. mlx_init(), mlx_new_window -> 읽어온 정보 바탕으로 윈도우 띄우기
	3. setting_map -> 필드 깔아버리고 첫 화면. 벽, 아이템, 출구, 플레이어 배치.
*/

	// 확인용
	// printf("%s\n", game.map_info);
	// printf("%d\n", game.win_wid);
	// printf("%d\n", game.win_hei);
	// system("leaks a.out");

#include "header.h"

int	main(int argc, char **argv)
{
	t_game		game;
	t_data_img	imgs;
	void		*mlx;
	void		*win;

	read_map_file(argv[1], &game);
	mlx = mlx_init();
	win = mlx_new_window(mlx, game.win_wid * 40, game.win_hei * 40, "so_long");
	setting_map(mlx, win, &game, &imgs);
	mlx_loop(mlx);
}

// typedef struct s_data
// {
// 	void	*img;
// 	char	*addr;
// 	int		bits_per_pixel;
// 	int		length;
// 	int		endian;
// }t_data;

// typedef struct s_data
// {
// 	void	*img;
// 	char	*addr;
// 	int		width;
// 	int		height;
// }t_data;

// int	render_next_frame(void *YourStruct);

// IF PRESS ANY KEY, CLOSE WINDOW
// int	close(int keycode, t_vars *vars)
// {
// 	mlx_destroy_window(vars->mlx, vars->win);
// 	return (0);
// }

// void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int*)dst = color;
// }

// int	main(void)
// {
// 	t_vars	vars;
//
// 	vars.mlx = mlx_init();
// 	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
// 	mlx_hook(vars.win, 2, 1L<<0, close, &vars);
// 	mlx_key_hook(vars.win, key_hook, &vars);
// 	mlx_mouse_hook(vars.win, mouse_hook, &vars);
// 	// mlx_loop_hook(mlx, render_next_frame, YourStruct);
// 	mlx_loop(vars.mlx);
// }
