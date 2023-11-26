#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

int print_p(va_list ap, int count)
{
    void				*ptr;
    char				hex[16] = "0123456789abcdef";
    unsigned long long	address;
	int					i;
    int                 array[16];
	
	if (write(1, "0x", 2) < 0)
		return (-1);
	ptr = va_arg(ap, void *);
	if (ap == NULL)
	{
		if (write(1, "0", 1) < 0)
			return (-1);
		count++;
	}
	address = (unsigned long long)ptr;
	i = 1;
	while(address > 0)
	{	
		array[16 - i] = address % 16;
		write(1, &array[16 - i], 1);
		write(1, "|", 1);
		address = address / 16;
        i++;
	}
	i = 0;
	while(array[i])
	{
		if (write(1, &array[i], 1) == -1)
			return (-1);
		i++;
		count++;
	}
	return (count + 2);
}

int	change(va_list ap, const char *format, int cnt)
{
	int	tmp;

	tmp = cnt;
	// if (*format == 'c')
		// return (print_char(ap, cnt));
	// else if (*format == 's')
		// cnt = print_str(ap, cnt);
	if (*format == 'p')
		cnt = print_p(ap, cnt);
	// else if (*format == 'd')
		// cnt = print_dec(ap, cnt);
	// else if (*format == 'i')
	// 	cnt = print_dec(ap, cnt);
	// else if (*format == 'u')
	// 	cnt = print_unsigned(ap, cnt);
	// else if (*format == 'x')
	// 	cnt = print_hex_low(ap, cnt);
	// else if (*format == 'X')
	// 	cnt = print_hex_up(ap, cnt);
	// else if (*format == '%')
	// 	cnt = print_percent(cnt);
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
			format++;
		}
		else
		{
			if (write(1, format, 1) < 0)
				return (-1);
			format++;
		}
		count++;
	}
	va_end(ap);
	return (count);
}

int main()
{
    // printf %p 확인하기
    char *ptr = "hello world";
    int i;
    unsigned long long j = (unsigned long long)ptr;

    printf("%lld\n", j);
    printf("printf: %p\n", ptr);
    i = ft_printf("ft_printf: %p\n", ptr);
}