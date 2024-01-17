/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_rendering.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:50:31 by wonyocho          #+#    #+#             */
/*   Updated: 2024/01/17 21:03:51 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	render_by_key(t_game *g, char key, int x, int y);

void	render(t_game *g, char key)
{
	int	x;
	int	y;
	int	i;

	x = 0;
	y = 0;
	i = 0;
	while (g->map[i])
	{
		if (g->map[i] == 'P')
		{
			mlx_put_image_to_window(g->mlx, g->win, g->img_player, x, y);
			break ;
		}
		x = x + 40;
		if (x == g->win_wid * 40)
		{
			x = 0;
			y = y + 40;
		}
		i++;
	}
	render_by_key(g, key, x, y);
}

static void	render_by_key(t_game *g, char key, int x, int y)
{
	int	i;

	i = find_player(g);
	if (key == 'w' && g->map[i + g->win_wid] != '1')
		mlx_put_image_to_window(g->mlx, g->win, g->img_tile, x, y + 40);
	else if (key == 'a' && g->map[i + 1] != '1')
		mlx_put_image_to_window(g->mlx, g->win, g->img_tile, x + 40, y);
	else if (key == 's' && g->map[i - g->win_wid] != '1')
		mlx_put_image_to_window(g->mlx, g->win, g->img_tile, x, y - 40);
	else if (key == 'd' && g->map[i - 1] != '1')
		mlx_put_image_to_window(g->mlx, g->win, g->img_tile, x - 40, y);
}
