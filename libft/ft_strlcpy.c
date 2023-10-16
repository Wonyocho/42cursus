/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:18:23 by wonyocho          #+#    #+#             */
/*   Updated: 2023/10/16 16:59:56 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *restrict dst, const char *restrict src, size_t dstsize)
{
	size_t	i;

	i = 0;
	while (dstsize > 1 && src[i])
	{
		dst[i] = src[i];
		i++;
		dstsize--;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}
/*
#include <string.h>
#include <stdio.h>
int	main()
{
	char src[] = "aaaaaaaaaaa";
	char dst[] = "ccc";
	
	printf("%lu\n", strlcpy(dst, src, 4));
	printf("%zu\n", ft_strlcpy(dst, src, 4));
}
*/
