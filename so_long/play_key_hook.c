/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_key_hook.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:58:50 by wonyocho          #+#    #+#             */
/*   Updated: 2024/01/11 19:05:24 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	key_hook(int keycode, t_game *g)
{
	if (keycode == 13)
		move_w(g);
	else if (keycode == 0)
		move_a(g);
	else if (keycode == 1)
		move_s(g);
	else if (keycode == 2)
		move_d(g);
	if (keycode == 53)
		exit(0);
	return (0);
}

static void	move_w(t_game *g)
{
	int	i;

	i = 0;
	while (i++ < ft_strlen(g->map))
	{
		if (g->map[i] == 'P')
			break ;
	}
	if (g->map[i - g->win_wid] == 'E')
		exit(0);
	if (g->map[i - g->win_wid] != '1' && g->map[i - g->win_wid] != 'E')
	{
		g->map[i] = '0';
		g->map[i - g->win_wid] = 'P';
	}
	fill_with_tiles(g);
	put_elements(g);
}

static void	move_a(t_game *g)
{
	int	i;

	i = 0;
	while (i++ < ft_strlen(g->map))
	{
		if (g->map[i] == 'P')
			break ;
	}
	if (g->map[i - 1] == 'E')
	{
		printf("clear!\n");
		exit(0);
	}
	if (g->map[i - 1] != '1' && g->map[i - 1] != 'E')
	{
		g->map[i] = '0';
		g->map[i - 1] = 'P';
	}
	fill_with_tiles(g);
	put_elements(g);
}

static void	move_s(t_game *g)
{
	int	i;

	i = 0;
	while (i++ < ft_strlen(g->map))
	{
		if (g->map[i] == 'P')
			break ;
	}
	if (g->map[i + g->win_wid] == 'E')
	{
		printf("clear!\n");
		exit(0);
	}
	if (g->map[i + g->win_wid] != '1' && g->map[i + g->win_wid] != 'E')
	{
		g->map[i] = '0';
		g->map[i + g->win_wid] = 'P';
	}
	fill_with_tiles(g);
	put_elements(g);
}

static void	move_d(t_game *g)
{
	int	i;

	i = 0;
	while (i++ < ft_strlen(g->map))
	{
		if (g->map[i] == 'P')
			break ;
	}
	if (g->map[i + 1] == 'E')
	{
		printf("clear!\n");
		exit(0);
	}
	if (g->map[i + 1] != '1' && g->map[i + 1] != 'E')
	{
		g->map[i] = '0';
		g->map[i + 1] = 'P';
	}
	fill_with_tiles(g);
	put_elements(g);
}
// 	// if (game->map_info[i - game->wid] == 'C')
// 	// 	game->col_cnt++;
// 		// && game->all_col == game->col_cnt)