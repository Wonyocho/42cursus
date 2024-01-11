/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_clear.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 17:30:23 by wonyocho          #+#    #+#             */
/*   Updated: 2024/01/11 19:01:49 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	game_clear(t_game *g, int item_ingame_count)
{
	if (g->item_count == item_ingame_count)
		printf("You've Got Bonus! Congratlations!\n");
	else
		printf("Stage Clear!\n");
	exit(0);
}

int	*exit_game(t_game *g)
{
	mlx_destroy_window(g->mlx, g->win);
	exit(0);
}
