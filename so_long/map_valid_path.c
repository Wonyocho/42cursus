/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_valid_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:21:20 by wonyocho          #+#    #+#             */
/*   Updated: 2024/01/16 11:47:18 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	find_player(t_game *g)
{
	int	i;

	i = 0;
	while (g->map[i])
	{
		if (g->map[i] == 'P')
			return (i);
		i++;
	}
	return (-1);
}

int	check_valid_path(t_game *g, int i, char *map_copy)
{
	char	temp;

	temp = map_copy[i];
	if (map_copy[i] == 'X' || map_copy[i] == '1')
		return (0);
	if (map_copy[i] == 'C')
		g->valid_c_count++;
	map_copy[i] = 'X';
	if (temp == 'E')
	{
		g->flag++;
		return (0);
	}
	check_valid_path(g, i + 1, map_copy);
	check_valid_path(g, i - g->win_wid, map_copy);
	check_valid_path(g, i + g->win_wid, map_copy);
	check_valid_path(g, i - 1, map_copy);
	return (0);
}
