/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 17:36:56 by wonyocho          #+#    #+#             */
/*   Updated: 2024/09/24 11:18:01 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_atoi(const char *str)
{
	long long	sign;
	int			i;
	long long	result;

	sign = 1;
	i = 0;
	result = 0;
	while (str[i] == ' ' || (9 <= str[i] && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	if (!('0' <= str[i] && str[i] <= '9'))
		return (0);
	while ('0' <= str[i] && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return ((int)(result * sign));
}

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

long	set_time(void)
{
	struct timeval	now;
	long			result;

	gettimeofday(&now, NULL);
	result = ((size_t)now.tv_sec * 1000) + ((size_t)now.tv_usec / 1000);
	return (result);
}

void	usleep_philo(long time, t_data *data)
{
	long	end_time;

	end_time = set_time() + time;
	while (set_time() < end_time)
	{
		if (check_main_status(data) == -1)
			break ;
		usleep(100);
	}
}

void	print_status(t_philo *philo, const char *str)
{
	if (check_main_status(philo->data) == -1)
		return ;
	pthread_mutex_lock(&philo->data->mutex_print);
	printf("%ld %d %s\n", set_time() - philo->start, philo->id, str);
	pthread_mutex_unlock(&philo->data->mutex_print);
}