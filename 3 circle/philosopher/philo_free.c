/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 15:45:49 by wonyocho          #+#    #+#             */
/*   Updated: 2024/09/21 19:59:20 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	free_all(pthread_t *threads, pthread_mutex_t *forks, t_philo *philo)
{
	if (threads)
		free(threads);
	if (philo)
		free(philo);
	if (forks)
		free(forks);
}
