/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_make.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:12:41 by wonyocho          #+#    #+#             */
/*   Updated: 2024/01/17 15:51:08 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	get_img_data(t_game *g);

void	setting_map(t_game *g)
{
	get_img_data(g);
	fill_with_tiles(g);
	put_elements(g);
}

static void	get_img_data(t_game *g)
{
	g->img_tile = mlx_new_image(g->mlx, 40, 40);
	g->img_wall = mlx_new_image(g->mlx, 40, 40);
	g->img_item = mlx_new_image(g->mlx, 40, 40);
	g->img_goal = mlx_new_image(g->mlx, 40, 40);
	g->img_player = mlx_new_image(g->mlx, 40, 40);
	g->img_tile = mlx_xpm_file_to_image(g->mlx, "textures/Grass.xpm",
			&g->img_wid, &g->img_hei);
	g->img_wall = mlx_xpm_file_to_image(g->mlx, "textures/Wall.xpm",
			&g->img_wid, &g->img_hei);
	g->img_item = mlx_xpm_file_to_image(g->mlx, "textures/Item.xpm",
			&g->img_wid, &g->img_hei);
	g->img_goal = mlx_xpm_file_to_image(g->mlx, "textures/Goal.xpm",
			&g->img_wid, &g->img_hei);
	g->img_player = mlx_xpm_file_to_image(g->mlx, "textures/Player.xpm",
			&g->img_wid, &g->img_hei);
}

void	fill_with_tiles(t_game *g)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < g->win_hei * 40)
	{
		mlx_put_image_to_window(g->mlx, g->win, g->img_tile, x, y);
		x = x + 40;
		if (x == g->win_wid * 40)
		{
			x = 0;
			y = y + 40;
		}
	}
}

void	put_elements(t_game *g)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	x = 0;
	y = 0;
	while (g->map[i])
	{
		if (g->map[i] == '1')
			mlx_put_image_to_window(g->mlx, g->win, g->img_wall, x, y);
		else if (g->map[i] == 'C')
			mlx_put_image_to_window(g->mlx, g->win, g->img_item, x + 9, y + 9);
		else if (g->map[i] == 'E')
			mlx_put_image_to_window(g->mlx, g->win, g->img_goal, x, y);
		else if (g->map[i] == 'P')
			mlx_put_image_to_window(g->mlx, g->win, g->img_player, x, y);
		x = x + 40;
		if (x == g->win_wid * 40)
		{
			x = 0;
			y = y + 40;
		}
		i++;
	}
}
