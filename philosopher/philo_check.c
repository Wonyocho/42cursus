/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 20:04:22 by wonyocho          #+#    #+#             */
/*   Updated: 2024/09/22 01:05:22 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	check_main_status(t_data *data)
{
	int	status;
	
	pthread_mutex_lock(&data->mutex_dead);
	status = data->stop_flag;
	pthread_mutex_unlock(&data->mutex_dead);
	return (status);
}

int	check_philo_status(t_data *data, t_philo *philo)
{
	int	i;
	int	ended_philo;

	i = 0;
	ended_philo = 0;
	while (i < data->p_num)
	{
		if (check_dead_philo() == -1)
			return (-1);
		if (check_full_philo() == -1)
			return (-1);
		i++;
	}
	pthread_mutex_lock(&data->mutex_meal);
	if (data->eat_num != -1 && ended_philo == data->p_num)
	{
		
	}
}
