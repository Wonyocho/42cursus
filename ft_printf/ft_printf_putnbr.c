/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putnbr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 15:52:54 by wonyocho          #+#    #+#             */
/*   Updated: 2023/11/26 16:12:49 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c, int count)
{
	write(1, &c, 1);
	count++;
	return (count);
}

int	ft_putnbr(int n, int count)
{
	int	array[10];
	int	i;
	int	j;

	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		count = count + 11;
	}
	else if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
		count++;
	}
	i = 0;
	while(n > 0)
	{
		array[10 - i - 1] = n % 10; //i = 0, array[9] = 2    i = 1,array[8] = 4,
		n = n / 10;
		i++;
	} // i = 2;
	j = 10 - i; //j = 8, i = 2
	while (i > 0)
	{
		write(1, &array[j], 1);
		j++;
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
