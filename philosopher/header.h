/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 16:55:07 by wonyocho          #+#    #+#             */
/*   Updated: 2024/09/22 08:57:42 by wonyocho         ###   ########.fr       */
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

// check.c
int		check_main_status(t_data *data);
int		check_philo_status(t_data *data, t_philo *philo);
int		check_full_philo(t_data *data, t_philo *philo);
int		check_dead_philo(t_data *data, t_philo *philo);

// free.c
void 	free_all(pthread_t *threads, pthread_mutex_t *forks, t_philo *philo);

// init.c
int		init_data(char **argv, int argc, t_data *data);
int		init_mutex(t_data *data, pthread_mutex_t **forks);
int		init_philo(t_data *data, pthread_mutex_t *forks, t_philo **philo);

// routine.c
int		get_fork(t_data *data, t_philo *philo);
int		do_eat(t_data *data, t_philo *philo);
int		do_sleep(t_data *data, t_philo *philo);
int 	do_think(t_data *data, t_philo *philo);

// run.c
void	start(t_data *data, t_philo *philo, pthread_t *threads);
void	*routine(void *arg);
void	monitoring(t_data *data, t_philo *philo);
void 	destroy_mutex(t_data *data, pthread_mutex_t *forks);

// utils.c
int		ft_atoi(const char *str);
int		check_argv(char **argv);
long	set_time(void);
void	usleep_philo(long time, t_data *data);
void	print_status(t_philo *philo, const char *str);

#endif
