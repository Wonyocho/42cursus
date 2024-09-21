/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 16:54:57 by wonyocho          #+#    #+#             */
/*   Updated: 2024/09/21 17:41:21 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"


int	main(int argc, char **argv)
{
	t_data			data;
	t_philo			*philo;
	pthread_t		*threads;
	pthread_mutex_t	*forks;

	if (argc == 5 || argc == 6)
	{
		if (check_argv(argv) == -1 || init_data(argv, argc, &data) == -1)
			return (0);
		threads = malloc(sizeof(pthread_t) * (data.p_num));
		if (!threads)
			return (0);
		if (init_mutex(&data, &forks) == -1)
			return (0);
		if (init_philo(&data, forks, &philo) == -1)
			return (0);
		start(&data, philo, threads);
		free_all(threads, forks, philo);
	}
}
