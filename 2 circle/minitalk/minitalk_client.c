/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_client.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 16:53:38 by wonyocho          #+#    #+#             */
/*   Updated: 2024/02/26 11:33:22 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	bit_send(pid_t pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((c & (1 << bit)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(50);
		bit++;
	}
}

static void	str_send(pid_t pid, char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		bit_send(pid, str[i]);
		i++;
	}
	bit_send(pid, '\n');
	bit_send(pid, '\0');
}

int	main(int argc, char **argv)
{
	pid_t	to_pid;

	if (argc == 3 && argv[2][0] != '\0')
	{
		to_pid = ft_atoi(argv[1]);
		if (to_pid < 100 || to_pid > 99998)
		{
			ft_putstr_fd("PID Error!.\n", 1);
			return (0);
		}
		str_send(to_pid, argv[2]);
	}
	else
		ft_putstr_fd("ARGC Error!\n", 1);
	return (0);
}
