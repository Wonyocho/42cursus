/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 10:06:06 by wonyocho          #+#    #+#             */
/*   Updated: 2023/11/26 16:13:31 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	print_percent(int cnt)
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
	else if (*format == 'p')
		cnt = get_address(ap, cnt);
	else if (*format == 'd')
		cnt = print_decimal_integer(ap, cnt);
	else if (*format == 'i')
		cnt = print_decimal_integer(ap, cnt);
	else if (*format == 'u')
		cnt = print_unsigned_integer(ap, cnt);
	else if (*format == 'x')
		cnt = printf_lower_hex(ap, cnt);
	else if (*format == 'X')
		cnt = printf_upper_hex(ap, cnt);
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
		}
		format++;
		count++;
	}
	va_end(ap);
	return (count - 1);
}

int	main()
{
	int i;
	int j;


	// // 단일 문자 한개를 출력
	// i = ft_printf("%c\n", 'a');
	// j = printf("%c\n", 'a');
	// printf("ft_printf: %d\n", i);
	// printf("printf: %d\n", j);



	// // 문자열 출력
	// i = ft_printf("%s\n", "hi");
	// j = printf("%s\n", "hi");
	// printf("ft_printf: %d\n", i);
	// printf("printf: %d\n", j);




	// // void *형식의 포인터 인자를 16진수로 출력
	// i = ft_printf("%p\n", "hi");
	// j = printf("%p\n", "hi");
	// printf("ft_printf: %d\n", i);
	// printf("printf: %d\n", j);




	// // 10진수 숫자를 출력 (INT_MIN ~ INT_MAX)
	// i = ft_printf("%d\n", -214748364);
	// j = printf("%d\n", -214748364);
	// printf("ft_printf: %d\n", i);
	// printf("printf: %d\n", j);




	// 10진수 '정수'를 출력 (INT_MIN ~ INT_MAX)
	i = ft_printf("%i\n", 42);
	j = printf("%i\n", 42);
	printf("ft_printf: %d\n", i);
	printf("printf: %d\n", j);




	// // 10진수 부호없는 정수를 출력
	// i = ft_printf("%u\n", 0);
	// j = printf("%u\n", 0);
	// printf("ft_printf: %d\n", i);
	// printf("printf: %d\n", j);




	// // 소문자를 사용하여 숫자를 16진수로 출력
	// i = ft_printf("%x\n", 2147483647);
	// j = printf("%x\n", 2147483647);
	// printf("ft_printf: %d\n", i);
	// printf("printf: %d\n", j);




	// // 대문자를 사용하여 숫자를 16진수로 출력
	// i = ft_printf("%X\n", 2147483647);
	// j = printf("%X\n", 2147483647);
	// printf("ft_printf: %d\n", i);
	// printf("printf: %d\n", j);




	// // 퍼센트 기호를 출력
	// i = ft_printf("%%\n");
	// j = printf("%%\n");
	// printf("ft_printf: %d\n", i);
	// printf("printf: %d\n", j);
}
