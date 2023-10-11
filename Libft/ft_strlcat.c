/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:57:57 by wonyocho          #+#    #+#             */
/*   Updated: 2023/10/11 16:58:51 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

size_t	ft_strlcat(char *restrict dest, const char *restrict src,
		size_t dstsize)
{
	unsigned int	i;
	size_t			dest_len;
	size_t			src_len;
	unsigned char	*str;
	unsigned char	*dst;

	i = 0;
	str = (unsigned char *)src;
	dst = (unsigned char *)dest;
	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	if (dstsize <= dest_len)
		return (src_len + dstsize);
	while (str[i] && (i + dest_len + 1) < dstsize)
	{
		dst[dest_len + i] = str[i];
		i++;
	}
	dst[dest_len + i] = '\0';
	return (src_len + dest_len);
}
/*
#include <stdio.h>
#include <string.h>
int main()
{
	char src[] = "hello";
	char dst[] = "world";

	printf("%zu\n", strlcat(dst, src, 4));
	printf("%zu\n", ft_strlcat(dst, src, 4));
}
*/
