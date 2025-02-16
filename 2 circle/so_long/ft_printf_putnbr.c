/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putnbr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 10:32:39 by wonyocho          #+#    #+#             */
/*   Updated: 2024/01/12 13:27:30 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	case_minus(int n, int count)
{
	if (n == 0)
	{
		if (write(1, "0", 1) == -1)
			return (-1);
		return (count + 1);
	}
	if (n == -2147483648)
	{
		if (write(1, "-2147483648", 11) == -1)
			return (-1);
		count = count + 11;
	}
	else if (n < 0)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		n = -n;
		count++;
	}
	return (count);
}

int	ft_putnbr(int n, int count)
{
	int	array[10];
	int	i;

	i = 0;
	if (n <= 0)
	{
		count = case_minus(n, count);
		if (count == -1)
			return (-1);
		n = -n;
	}
	while (n > 0)
	{
		array[10 - i - 1] = n % 10 + '0';
		n = n / 10;
		i++;
	}
	while (i > 0)
	{
		if (write(1, &array[10 - i], 1) == -1)
			return (-1);
		i--;
		count++;
	}
	return (count);
}

int	ft_putnbr_u(unsigned int n, int count)
{
	char	arr[10];
	int		i;

	i = 0;
	if (n <= 0)
	{
		count = case_minus(n, count);
		n = -n;
	}
	while (n != 0)
	{
		arr[i++] = (n % 10) + '0';
		n = n / 10;
	}
	i--;
	while (i >= 0)
	{
		if (write(1, &arr[i--], 1) < 0)
			return (-1);
		count++;
	}
	return (count);
}
