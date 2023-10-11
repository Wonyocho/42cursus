/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 17:21:51 by wonyocho          #+#    #+#             */
/*   Updated: 2023/10/11 16:48:30 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*str;
	int				i;

	i = 0;
	str = (unsigned char *)s;
	while (n > 0)
	{
		str[i] = 0;
		n--;
	}
}
/*
#include <strings.h>
#include <stdio.h>
int main()
{
	char str1[] = "helloworldwonyocho";
	char str2[] = "helloworldwonyocho";
	ft_bzero(str1, 0);
	bzero(str2, 0);
	printf("ft_bzero: %s\n", str1);
	printf("bzero: %s\n", str2);
}
*/
