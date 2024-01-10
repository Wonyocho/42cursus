/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_make.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:12:41 by wonyocho          #+#    #+#             */
/*   Updated: 2024/01/10 19:54:19 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	setting_map(void *mlx, void *win, t_game *game, t_data_img *imgs)
{
	get_img_data(mlx, imgs);
	fill_with_tiles(mlx, win, game, imgs);
	put_elements(mlx, win, game, imgs);
}

void	get_img_data(void *mlx, t_data_img *imgs)
{
	imgs->img_tile = mlx_new_image(mlx, 40, 40);
	imgs->img_wall = mlx_new_image(mlx, 40, 40);
	imgs->img_item = mlx_new_image(mlx, 40, 40);
	imgs->img_goal = mlx_new_image(mlx, 40, 40);
	imgs->img_player = mlx_new_image(mlx, 40, 40);
	imgs->img_tile = mlx_xpm_file_to_image(mlx, "textures/Grass.xpm",
			&imgs->img_wid, &imgs->img_hei);
	imgs->img_wall = mlx_xpm_file_to_image(mlx, "textures/Wall.xpm",
			&imgs->img_wid, &imgs->img_hei);
	imgs->img_item = mlx_xpm_file_to_image(mlx, "textures/Item.xpm",
			&imgs->img_wid, &imgs->img_hei);
	imgs->img_goal = mlx_xpm_file_to_image(mlx, "textures/Goal.xpm",
			&imgs->img_wid, &imgs->img_hei);
	imgs->img_player = mlx_xpm_file_to_image(mlx, "textures/Player.xpm",
			&imgs->img_wid, &imgs->img_hei);
}

void	fill_with_tiles(void *mlx, void *win, t_game *game, t_data_img *imgs)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < game->win_hei * 40)
	{
		mlx_put_image_to_window(mlx, win, imgs->img_tile, x, y);
		x = x + 40;
		if (x == game->win_wid * 40)
		{
			x = 0;
			y = y + 40;
		}
	}
}

void	put_elements(void *mlx, void *win, t_game *game, t_data_img *imgs)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	x = 0;
	y = 0;
	while (game->map_info[i])
	{
		if (game->map_info[i] == '1')
			mlx_put_image_to_window(mlx, win, imgs->img_wall, x, y);
		else if (game->map_info[i] == 'C')
			mlx_put_image_to_window(mlx, win, imgs->img_item, x + 10, y + 10);
		else if (game->map_info[i] == 'E')
			mlx_put_image_to_window(mlx, win, imgs->img_goal, x, y);
		else if (game->map_info[i] == 'P')
			mlx_put_image_to_window(mlx, win, imgs->img_player, x + 5, y + 5);
		x = x + 40;
		if (x == game->win_wid * 40)
		{
			x = 0;
			y = y + 40;
		}
		i++;
	}
}
