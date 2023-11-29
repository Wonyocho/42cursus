/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 12:39:49 by wonyocho          #+#    #+#             */
/*   Updated: 2023/11/26 13:37:39 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_address(va_list ap, int count)
{
	unsigned long long	address;
	void				*ptr;

	if (write(1, "0x", 2) < 0)
		return (-1);
	count = count + 2;
	ptr = va_arg(ap, void *);
	if (ptr == NULL)
	{
		if (write(1, "0", 1) < 0)
			return (-1);
		count++;
		return (count);
	}
	address = (unsigned long long)ptr;
	count = print_address(address, count);
	return (count);
}

int	print_address(unsigned long long address, int count)
{
	int			i;
	const char	*hex = "0123456789abcdef";
	int			arr[16];

	i = 0;
	while (address > 0)
	{
		arr[15 - i] = hex[address % 16];
		address = address / 16;
		i++;
	}
	while (i > -1)
	{
		if (write(1, &arr[15 - i], 1) == -1)
			return (-1);
		count++;
		i--;
	}
	return (count - 1);
}

int	printf_lower_hex(va_list ap, int count)
{
	const char		*hex = "0123456789abcdef";
	int				i;
	int				j;
	int				arr[16];
	unsigned int	num;

	num = va_arg(ap, unsigned int);
	i = 0;
	while (num > 0)
	{
		arr[15 - i] = hex[num % 16];
		num = num / 16;
		i++;
	}
	while (i > 0)
	{
		j = arr[16 - i];
		if (write(1, &j, 1) == -1)
			return (-1);
		count++;
		i--;
	}
	return (count);
}

int	printf_upper_hex(va_list ap, int count)
{
	const char		*hex = "0123456789ABCDEF";
	int				i;
	int				j;
	int				arr[16];
	unsigned int	num;

	num = va_arg(ap, unsigned int);
	i = 0;
	while (num > 0)
	{
		arr[15 - i] = hex[num % 16];
		num = num / 16;
		i++;
	}
	while (i > 0)
	{
		j = arr[16 - i];
		if (write(1, &j, 1) == -1)
			return (-1);
		count++;
		i--;
	}
	return (count);
}
