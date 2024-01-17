/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:58:50 by wonyocho          #+#    #+#             */
/*   Updated: 2024/01/17 15:55:32 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	move_w(t_game *g);
static void	move_a(t_game *g);
static void	move_s(t_game *g);
static void	move_d(t_game *g);

int	hook_key_press(int keycode, t_game *g)
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
	{
		mlx_destroy_window(g->mlx, g->win);
		exit(0);
	}
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
	if (g->map[i - g->win_wid] == 'E' && g->item_count == g->c_count)
		print_exit("Congratulations!");
	if (g->map[i - g->win_wid] != '1' && g->map[i - g->win_wid] != 'E')
	{
		if (g->map[i - g->win_wid] == 'C')
			g->item_count++;
		g->map[i] = '0';
		g->map[i - g->win_wid] = 'P';
		g->walk_count++;
		ft_printf("walkcount: %d\n", g->walk_count);
	}
	render(g, 'w');
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
	if (g->map[i - 1] == 'E' && g->item_count == g->c_count)
		print_exit("Congratulations!");
	if (g->map[i - 1] != '1' && g->map[i - 1] != 'E')
	{
		if (g->map[i - 1] == 'C')
			g->item_count++;
		g->map[i] = '0';
		g->map[i - 1] = 'P';
		g->walk_count++;
		ft_printf("walkcount: %d\n", g->walk_count);
	}
	render(g, 'a');
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
	if (g->map[i + g->win_wid] == 'E' && g->item_count == g->c_count)
		print_exit("Congratulations!");
	if (g->map[i + g->win_wid] != '1' && g->map[i + g->win_wid] != 'E')
	{
		if (g->map[i + g->win_wid] == 'C')
			g->item_count++;
		g->map[i] = '0';
		g->map[i + g->win_wid] = 'P';
		g->walk_count++;
		ft_printf("walkcount: %d\n", g->walk_count);
	}
	render(g, 's');
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
	if (g->map[i + 1] == 'E' && g->item_count == g->c_count)
		print_exit("Congratulations!");
	if (g->map[i + 1] != '1' && g->map[i + 1] != 'E')
	{
		if (g->map[i + 1] == 'C')
			g->item_count++;
		g->map[i] = '0';
		g->map[i + 1] = 'P';
		g->walk_count++;
		ft_printf("walkcount: %d\n", g->walk_count);
	}
	render(g, 'd');
}
