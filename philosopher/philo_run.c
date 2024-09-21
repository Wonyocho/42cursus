/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_run.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 16:58:45 by wonyocho          #+#    #+#             */
/*   Updated: 2024/09/22 00:43:56 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	start(t_data *data, t_philo *philo, pthread_t *threads)
{
	int	i;

	i = 0;
	while (i < data->p_num)
	{
		pthread_create(&threads[i], NULL, routine, &philo[i]);
		i++;
	}
	monitoring(data, philo);
}

void	*routine(void *arg)
{
	t_philo *philo;
	t_data	*data;

	printf("!\n");
	philo = (t_philo *)arg;
	data = philo->data;
	while (set_time() < philo->start)
		usleep(100);
	if (philo->id % 2 == 0)
		usleep_philo(data->eat_time / 2, data);
	while (1)
	{
		if (get_fork(data, philo) != 1)
			break ;
		if (do_eat(data, philo) != 1)
			break ;
		if (do_sleep(data, philo) != 1)
			break ;
		if (do_think(data, philo) != 1)
			break ;
	}
	return (NULL);
}

void	monitoring(t_data *data, t_philo *philo)
{
	while (1)
	{
		if (check_main_status(data) == -1)
			break ;
		if (check_philo_status(data, philo) == -1)
			break;
		usleep_philo(1, data);
	}
}