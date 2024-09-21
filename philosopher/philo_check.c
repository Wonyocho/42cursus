/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 20:04:22 by wonyocho          #+#    #+#             */
/*   Updated: 2024/09/21 20:10:36 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	check_status(t_data *data)
{
	int	status;
	
	pthread_mutex_lock(&data->mutex_dead);
	status = data->dead_flag;
	pthread_mutex_unlock(&data->mutex_dead);
	return (status);
}
