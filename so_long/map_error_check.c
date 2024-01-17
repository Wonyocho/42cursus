/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 17:30:53 by wonyocho          #+#    #+#             */
/*   Updated: 2024/01/17 20:08:01 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	check_essential(t_game *g);
static void	check_rectangular(t_game *g);
static void	check_surrorunded_walls(t_game *g);
static void	check_elements(t_game *g);

void	map_error_check(t_game *g)
{
	int		i;
	char	*map_copy;
	int		flag;

	if (g->win_wid > 60 || g->win_hei > 30)
		print_exit("Error\nMap is too big!");
	map_copy = ft_strdup_no_nl(g->map);
	i = find_player(g);
	check_essential(g);
	check_rectangular(g);
	check_surrorunded_walls(g);
	check_elements(g);
	flag = check_valid_path(g, i, map_copy);
	if (g->valid_c_count != g->c_count || g->flag != 1)
		print_exit("Error\nMap File Error!");
	free(map_copy);
}

static void	check_essential(t_game *g)
{
	int	i;

	i = 0;
	while (g->map[i])
	{
		if (g->map[i] != '1' && g->map[i] != '0' && g->map[i] != 'P'
			&& g->map[i] != 'C' && g->map[i] != 'E')
		{
			print_exit("Error\nMap File Error!");
		}
		else if (g->map[i] == 'C')
			g->c_count++;
		i++;
	}
}

static void	check_rectangular(t_game *g)
{
	if (g->win_wid * g->win_hei != ft_strlen(g->map))
		print_exit("Error\nMap file Error!");
}

static void	check_surrorunded_walls(t_game *g)
{
	int	i;

	i = 0;
	while (i < ft_strlen(g->map))
	{
		if (i < g->win_wid)
		{
			if (g->map[i] != '1')
				print_exit("Error\nMap File Error!");
		}
		else if (i % g->win_wid == 0 || i % g->win_wid == g->win_wid - 1)
		{
			if (g->map[i] != '1')
				print_exit("Error\nMap File Error!");
		}
		else if (i > ft_strlen(g->map) - g->win_wid)
		{
			if (g->map[i] != '1')
				print_exit("Error\nMap File Error!");
		}
		i++;
	}
}

static void	check_elements(t_game *g)
{
	int	c_count;
	int	p_count;
	int	e_count;
	int	i;

	c_count = 0;
	p_count = 0;
	e_count = 0;
	i = 0;
	while (g->map[i])
	{
		if (g->map[i] == 'C')
			c_count++;
		if (g->map[i] == 'P')
			p_count++;
		if (g->map[i] == 'E')
			e_count++;
		i++;
	}
	if (p_count != 1)
		print_exit("Error\nMap File Error!");
	if (e_count < 1)
		print_exit("Error\nMap File Error!");
	if (c_count < 1)
		print_exit("Error\nMap File Error!");
}
