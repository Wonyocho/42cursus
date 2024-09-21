/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 16:55:07 by wonyocho          #+#    #+#             */
/*   Updated: 2024/09/21 16:00:30 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

#include <unistd.h>		// usleep
#include <stdio.h>
#include <stdlib.h>		// malloc
#include <string.h>		// memset
#include <sys/time.h>	// gettimeofday
#include <pthread.h>	// pthread_

typedef struct s_data
{
	int				p_num;
	int				lifetime;
	int				eat_time;
	int 			sleep_time;
	int				eat_num;
	int				stop_flag;
	pthread_mutex_t	mutex_meal;
	pthread_mutex_t	mutex_print;
	pthread_mutex_t	mutex_dead;
}	t_data;

typedef struct s_philo
{
	int				id;
	int				eat_cnt;
	long			start;
	long			last;
	t_data			*data;
	pthread_t		thread;
	pthread_mutex_t	*left;
	pthread_mutex_t	*right;
}	t_philo;

int	ft_atoi(const char *str);

int	init_data(char **argv, int argc, t_data *data);
int	init_mutex(t_data *data, pthread_mutex_t **forks);
int	init_philo(t_data *data, pthread_mutex_t *forks, t_philo **philo);

void free_all(pthread_t *threads, pthread_mutex_t *forks, t_philo *philos);

#endif
