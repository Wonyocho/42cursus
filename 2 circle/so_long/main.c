/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 19:22:06 by wonyocho          #+#    #+#             */
/*   Updated: 2024/01/17 21:06:35 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	hook_exit_window(t_game *g);
static void	check_ber(char *filename);

int	main(int argc, char **argv)
{
	t_game	g;

	if (argc != 2)
		print_exit("Error\nFile name error.");
	check_ber(argv[1]);
	read_map_file(argv[1], &g);
	g.mlx = mlx_init();
	if (!g.mlx)
		print_exit("Error\nTry again.");
	g.win = mlx_new_window(g.mlx, g.win_wid * 40, g.win_hei * 40, "so_long");
	if (!g.win)
		print_exit("Error\nTry again.");
	setting_map(&g);
	mlx_hook(g.win, 2, 0, hook_key_press, &g);
	mlx_hook(g.win, 17, 0, hook_exit_window, &g);
	mlx_loop(g.mlx);
}

void	print_exit(char *msg)
{
	ft_printf("%s\n", msg);
	exit(0);
}

static int	hook_exit_window(t_game *g)
{
	mlx_destroy_window(g->mlx, g->win);
	exit (0);
}

static void	check_ber(char *filename)
{
	char	**cmp;
	int		flag;

	cmp = ft_split(filename, '.');
	while (*cmp)
		cmp++;
	--cmp;
	flag = ft_memcmp(*cmp, "ber", 3);
	if (flag != 0)
		print_exit("Error\nFile name error");
}
