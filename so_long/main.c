/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 19:22:06 by wonyocho          #+#    #+#             */
/*   Updated: 2024/01/11 19:02:11 by wonyocho         ###   ########.fr       */
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
	// 	system("leaks a.out");

#include "header.h"

int	main(int argc, char **argv)
{
	t_game	g;
	int		keycode;
	int		fd;

	if (argc != 2)
		printf("Try again.\n");
	read_map_file(argv[1], &g);
	g.mlx = mlx_init();
	g.win = mlx_new_window(g.mlx, g.win_wid * 40, g.win_hei * 40, "so_long");
	setting_map(&g);
	mlx_key_hook(g.win, key_hook, &g);
	mlx_loop(g.mlx);
}
