/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 17:34:19 by wonyocho          #+#    #+#             */
/*   Updated: 2023/10/11 16:52:31 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	unsigned char	*str_src;
	unsigned char	*str_dst;
	unsigned int	i;

	i = 0;
	str_src = (unsigned char *)src;
	str_dst = (unsigned char *)dst;
	while (i < n)
	{
		str_dst[i] = str_src[i];
		i++;
	}
	return (dst);
}
/*
#include <string.h>
#include <stdio.h>
int	main()
{
	char src[] = "ccccccccccccccc";
	char dst[] = "aaaaaaaaaaaaaaa";

	//memcpy(dst, src, 5);
	ft_memcpy(dst, src, 5);
	printf("%s", dst);
}
*/
