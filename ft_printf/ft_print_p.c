#include "ft_printf.h"

int print_p(va_list ap, int count)
{
    void				*ptr;
    char				hex[16] = "0123456789abcdef";
    unsigned long long	address;
	int					i;
	
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
	i = 0;
	while(address != 0)
	{
		i = address % 16;
		address = address / 16;
		if (write(1, &hex[i], 1) == -1)
			return (-1);
		count++;
	}
	return (count + 2);
}
