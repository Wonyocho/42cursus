/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 14:58:35 by wonyocho          #+#    #+#             */
/*   Updated: 2023/10/12 17:33:27 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	power_ten(int count)
{
	int	n;

	n = 1;
	while (count > 0)
	{
		n = n * 10;
		count--;
	}
	return (n);
}

char	*ft_itoa(int n)
{
	int		count;
	int		num;
	char	*arr;
	int		i;

	num = n;
	count = 0;
	if (n < 0)
		num *= -1;
	while (num % 10)
	{
		count++;
		num = num / 10;
	}
	i = 0;
	if (n < 0)
	{
		arr = (char *)malloc(sizeof(char) * count + 2);
		arr[i++] = '-';
		if (n == -2147483648)
		{
			arr = "-2147483648\0";
			return (arr);
		}
	}
	else
		arr = (char *)malloc(sizeof(char) * count + 1);
	while (count > 0)
	{
		if (n < 0)
			n *= -1;
		arr[i] = n  / power_ten(count - 1) + '0';
		n %= power_ten(count - 1);
		i++;
		count--;
	}
	arr[i] = '\0';
	return (arr);
}

#include <stdio.h>

int	main ()
{
	int	a = 0;

	printf("%s", ft_itoa(a));
}

