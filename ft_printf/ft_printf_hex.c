/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 10:30:32 by wonyocho          #+#    #+#             */
/*   Updated: 2023/12/13 10:22:13 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	case_zero(unsigned long long num, int count)
{
	if (num == 0)
	{
		if (write(1, "0", 1) == -1)
			return (-1);
		count++;
	}
	return (count);
}

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
	int			arr[20];

	i = 1;
	count = case_zero(address, count);
	while (address > 0)
	{
		arr[20 - i] = address % 16;
		address = address / 16;
		i++;
	}
	i = 20 - i + 1;
	while (i < 20)
	{
		if (write(1, &hex[arr[i]], 1) == -1)
			return (-1);
		count++;
		i++;
	}
	return (count);
}

int	printf_lower_hex(va_list ap, int count)
{
	const char		*hex = "0123456789abcdef";
	int				i;
	int				arr[16];
	unsigned int	num;

	num = va_arg(ap, unsigned int);
	count = case_zero(num, count);
	i = 0;
	while (num > 0)
	{
		arr[15 - i] = hex[num % 16];
		num = num / 16;
		i++;
	}
	while (i > 0)
	{
		if (write(1, &arr[16 - i], 1) == -1)
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
	int				arr[16];
	unsigned int	num;

	num = va_arg(ap, unsigned int);
	count = case_zero(num, count);
	i = 0;
	while (num > 0)
	{
		arr[15 - i] = hex[num % 16];
		num = num / 16;
		i++;
	}
	while (i > 0)
	{
		if (write(1, &arr[16 - i], 1) == -1)
			return (-1);
		count++;
		i--;
	}
	return (count);
}
