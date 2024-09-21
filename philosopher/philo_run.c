/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_run.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 16:58:45 by wonyocho          #+#    #+#             */
/*   Updated: 2024/09/21 20:43:25 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	start(t_data *data, t_philo *philo, pthread_t *threads)
{
	int	i;

	i = 0;
	while (i < data->p_num)
		pthread_create(&threads[i], NULL, routine, &philo[i++]);
	
}

void	*routine(void *arg)
{
	t_philo *philo;
	t_data	*data;

	philo = (t_philo *)arg;
	data = philo->data;
	while (set_time() < philo->start)
		usleep(100);
	if (philo->id % 2 == 0)
		wait_philo(data->eat_time / 2, data);
	while (1)
	{
		if (get_fork(philo, data) != 1)
			break ;
		// 먹고
		// 자고
		// 생각하고(포크 들고 내려놓는)
	}
	return (NULL);
}
