/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_csdiu.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 15:01:21 by wonyocho          #+#    #+#             */
/*   Updated: 2023/11/25 16:06:21 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	print_char(va_list ap, int count)
{
	char	c;

	c = va_arg(ap, int);
	if (write(1, &c, 1) == -1)
		return (-1);
	else
		count++;
	return (count);
}

int	print_string(va_list ap, int count)
{
	char	*str;

	str = va_arg(ap, char *);
	if (str == NULL)
	{
		write(1, "(null)", 6);
		count++;
		return (count);
	}
	while (*str)
	{
		if (write(1, str++, 1) == -1)
			return (-1);
		count++;
	}
	return (count);
}

int	print_decimal_integer(va_list ap, int count)
{
	int	n;

	n = va_arg(ap, int);
	count = ft_putnbr(n, 1, count);
	return (count);
}

int	print_unsigned_integer(va_list ap, int count)
{
	unsigned int	n;

	n = va_arg(ap, unsigned int);
	count = ft_putnbr_u(n, 1, count);
	return (count);
}
