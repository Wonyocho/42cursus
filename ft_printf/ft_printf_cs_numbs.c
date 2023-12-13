/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_cs_numbs.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 10:29:37 by wonyocho          #+#    #+#             */
/*   Updated: 2023/12/13 10:27:14 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
		if (write(1, "(null)", 6) == -1)
			return (-1);
		count = count + 6;
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
	count = ft_putnbr(n, count);
	return (count);
}

int	print_unsigned_integer(va_list ap, int count)
{
	unsigned int	n;

	n = va_arg(ap, unsigned int);
	count = ft_putnbr_u(n, count);
	return (count);
}
