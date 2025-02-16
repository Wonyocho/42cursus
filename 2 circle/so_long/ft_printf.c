/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 10:28:24 by wonyocho          #+#    #+#             */
/*   Updated: 2024/01/16 11:52:00 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	print_percent(int cnt)
{
	if (write(1, "%%", 1) < 0)
		return (-1);
	cnt++;
	return (cnt);
}

static int	change(va_list ap, const char *format, int cnt)
{
	int	tmp;

	tmp = cnt;
	if (*format == 'c')
		return (print_char(ap, cnt));
	else if (*format == 's')
		cnt = print_string(ap, cnt);
	else if (*format == 'd')
		cnt = print_decimal_integer(ap, cnt);
	else if (*format == 'u')
		cnt = print_unsigned_integer(ap, cnt);
	else if (*format == '%')
		cnt = print_percent(cnt);
	if (tmp > cnt)
		return (-1);
	return (cnt);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;

	count = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			count = change(ap, format, count);
			if (count == -1)
				return (-1);
		}
		else
		{
			if (write(1, format, 1) < 0)
				return (-1);
			count++;
		}
		format++;
	}
	va_end(ap);
	return (count);
}
