/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 10:29:02 by wonyocho          #+#    #+#             */
/*   Updated: 2023/12/13 10:35:53 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *format, ...);
int	ft_putnbr(int n, int count);
int	ft_putnbr_u(unsigned int n, int count);
int	print_char(va_list ap, int count);
int	print_string(va_list ap, int count);
int	print_decimal_integer(va_list ap, int count);
int	print_unsigned_integer(va_list ap, int count);
int	get_address(va_list ap, int count);
int	print_address(unsigned long long address, int count);
int	printf_lower_hex(va_list ap, int count);
int	printf_upper_hex(va_list ap, int count);

#endif