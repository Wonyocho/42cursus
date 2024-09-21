/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 20:01:03 by wonyocho          #+#    #+#             */
/*   Updated: 2024/09/22 01:22:11 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	get_fork(t_data *data, t_philo *philo)
{
	if (check_main_status(data) == -1)
		return (-1);
	if (philo->data->p_num == 1)
	{
		pthread_mutex_lock(philo->left);
		print_status(philo, "has taken a fork");
		pthread_mutex_unlock(philo->left);
		return (0);
	}
	pthread_mutex_lock(philo->left);
	print_status(philo, "has taken a fork");
	pthread_mutex_lock(philo->right);
	print_status(philo, "has taken a fork");
	return (1);
}

int	do_eat(t_data *data, t_philo *philo)
{
	int	result;

	result = 1;
	if (check_main_status(data) == -1)
	{
		pthread_mutex_unlock(philo->left);
		pthread_mutex_unlock(philo->right);
		return (-1);
	}
	print_status(philo, "is eating");
	pthread_mutex_lock(&data->mutex_meal);
	philo->last = set_time();
	pthread_mutex_unlock(&data->mutex_meal);
	usleep_philo(data->eat_time, data);
	pthread_mutex_lock(&data->mutex_meal);
	philo->eat_cnt++;
	if (data->eat_num == -1 && philo->eat_cnt >= data->eat_num)
		result = 0;
	pthread_mutex_unlock(&data->mutex_meal);
	pthread_mutex_unlock(philo->left);
	pthread_mutex_unlock(philo->right);
	if (check_main_status(data) == -1)
		return (-1);
	return (result);
}

int	do_sleep(t_data *data, t_philo *philo)
{
	if (check_main_status(data) == -1)
		return (-1);
	print_status(philo, "is sleeping");
	usleep_philo(data->sleep_time, data);
	printf("!\n");
	return (1);
}

int do_think(t_data *data, t_philo *philo)
{
	if (check_main_status(data) == -1)
		return (-1);
	print_status(philo, "is thinking");
	return (1);
}
