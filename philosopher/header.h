/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 16:55:07 by wonyocho          #+#    #+#             */
/*   Updated: 2024/09/15 17:09:04 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>		// usleep
#include <stdio.h>
#include <stdlib.h>		// malloc
#include <string.h>		// memset
#include <sys/time.h>	// gettimeofday
#include <pthread.h>	// pthread_

typedef struct s_input
{
	int	number_of_philo;
	int	time_to_die;
	int	time_to_eat;
	int time_to_sleep;
}	t_input;
