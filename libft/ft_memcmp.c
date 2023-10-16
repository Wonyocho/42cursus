/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 15:15:43 by wonyocho          #+#    #+#             */
/*   Updated: 2023/10/11 16:49:12 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	int				i;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	while (n > 0 && (str1[i] || str2[i]))
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
		n--;
	}
	return (0);
}
/*
#include <string.h>
#include <stdio.h>
int	main()
{
	char s1[] = "";
	char s2[] = "";
	int n = 3;
	int a = ft_memcmp(s1, s2, n);
	int b = memcmp(s1, s2, n);
	printf("ft_memcmp: %d, memcmp: %d\n", a, b);
}
*/
