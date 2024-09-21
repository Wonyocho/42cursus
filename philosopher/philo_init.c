/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 15:27:38 by wonyocho          #+#    #+#             */
/*   Updated: 2024/09/22 00:42:38 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	init_data(char **argv, int argc, t_data *data)
{
	data->stop_flag = 0;
	data->p_num = ft_atoi(argv[1]);
	data->lifetime = ft_atoi(argv[2]);
	data->eat_time = ft_atoi(argv[3]);
	data->sleep_time = ft_atoi(argv[4]);
	data->eat_num = -1;
	if (argc == 6)
		data->eat_num = ft_atoi(argv[5]);
	if (data->p_num == 0 || data->lifetime == 0 || data->eat_time < 0
		|| data->sleep_time < 0)
		return (-1);
	return (1);
}

int	init_mutex(t_data *data, pthread_mutex_t **forks)
{
	int	i;

	if (pthread_mutex_init(&data->mutex_meal, NULL) == -1
		|| pthread_mutex_init(&data->mutex_dead, NULL) == -1
		|| (pthread_mutex_init(&data->mutex_print, NULL) == -1))
		return (-1);
	*forks = malloc(sizeof(pthread_mutex_t) * (data->p_num));
	if (!(*forks))
		return (-1);
	i = 0;
	while (i < data->p_num)
	{
		if (pthread_mutex_init(&(*forks)[i], NULL) == -1)
			return (-1);
		i++;
	}
	return (1);
}

int	init_philo(t_data *data, pthread_mutex_t *forks, t_philo **philo)
{
	int		i;
	long	start_time;

	start_time = set_time() + data->p_num;
	*philo = malloc(sizeof(t_philo) * (data->p_num));
	if (!(*philo))
		return (-1);
	i = 0;
	while (i < data->p_num)
	{
		(*philo)[i].id = i + 1;
		(*philo)[i].eat_cnt = 0;
		(*philo)[i].start = start_time;
		(*philo)[i].last = start_time;
		(*philo)[i].left = &forks[i];
		(*philo)[i].right = &forks[(i + 1) % data->p_num];
		(*philo)[i].data = data;
		i++;
	}
	return (1);
}
