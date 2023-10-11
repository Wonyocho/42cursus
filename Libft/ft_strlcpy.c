/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:18:23 by wonyocho          #+#    #+#             */
/*   Updated: 2023/10/11 17:02:38 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *src)
{
	int	i;

	i = 0;
	while (src[i])
		i++;
	return (i);
}

size_t	ft_strlcpy(char *restrict dst, const char *restrict src, size_t dstsize)
{
	unsigned int	i;
	size_t			n;

	i = 0;
	n = ft_strlen(src);
	while (dstsize > 1 && src[i])
	{
		dst[i] = src[i];
		i++;
		dstsize--;
	}
	dst[i] = '\0';
	return (n);
}
/*
#include <string.h>
#include <stdio.h>
int	main()
{
	char src[] = "aaaaaaaaaaa";
	char dst[] = "ccc";
	//int n = 
	printf("%lu\n", strlcpy(dst, src, 4));
	printf("%s\n", dst);
	printf("%zu\n", ft_strlcpy(dst, src, 4));
}
*/
