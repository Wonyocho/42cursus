/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 15:27:14 by wonyocho          #+#    #+#             */
/*   Updated: 2024/01/09 15:41:59 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOK_H
# define HOOK_H

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}t_vars;

// MOUSE HOOK
int	mouse_hook(int button, int x, int y, t_vars *vars)
{
	printf("Mousehook Detected!\n");
	return (0);
}

// KEY HOOK
int	key_hook(int keycode, t_vars *vars)
{
	printf("Keyhook Detected!\n");
	return (0);
}

#endif