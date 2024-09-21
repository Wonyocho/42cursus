/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 16:54:57 by wonyocho          #+#    #+#             */
/*   Updated: 2024/09/21 15:59:37 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	check_argv(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (!('0' <= argv[i][j] && argv[i][j] <= '9'))
				return (-1);
			j++;
		}
		i++;
	}
	return (1);
}

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
		free_all(threads, forks, philo);
	}
	else
		printf("Error2\n");
}
