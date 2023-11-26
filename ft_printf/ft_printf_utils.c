/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 15:52:54 by wonyocho          #+#    #+#             */
/*   Updated: 2023/11/25 17:42:28 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n, int count)
{
	if (n < 0)
	{
		if (n == -2147483648)
			write(1, "-2147483648", 11);
		else
		{
			write(1, "-", 1);
			n = -n;
			ft_putnbr_fd(n, 1);
		}
	}
	else
	{
		if (n >= 10)
		{
			ft_putnbr_fd(n / 10, 1);
			ft_putnbr_fd(n % 10, 1);
		}
		else
		{
			ft_putchar_fd(n + '0', 1);
			count++;
		}
	}
	return (count);
}

int	ft_putnbr_u(unsigned int n, int count)
{
	char	arr[10];
	int		i;

	if (n == 0)
	{
		if (write(1, "0", 1) < 0)
			return (-1);
		count++;
	}
	while (n != 0)
	{
		arr[i++] = (n % 10) + '0';
		n = n / 10;
		// i++;
	}
	i--;
	while (i >= 0)
	{
		if (write(1, &arr[i--], 1) < 0)
			return (-1);
		// i--;
		count++;
	}
	return (count);
}
