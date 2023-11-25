/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 10:06:26 by wonyocho          #+#    #+#             */
/*   Updated: 2023/11/25 15:36:49 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int	ft_putnbr_ap(int n, int count);

int	print_char(va_list ap, int count);
int	print_string(va_list ap, int count);
int	print_decimal_integer(va_list ap, int count);



#endif