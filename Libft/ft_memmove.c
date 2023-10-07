/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 18:35:02 by wonyocho          #+#    #+#             */
/*   Updated: 2023/10/06 19:17:54 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memmove(void *dst, const void *src, int n)
{
	unsigned char	*str_dst;
	unsigned char	*buf;
	int				i;

	i = 0;
	buf = (unsigned char *)src;
	str_dst = (unsigned char *)dst;
	while (i < n)
	{
		str_dst[i] = buf[i];
		i++;
	}
	return (dst);
}
/*
#include <string.h>
#include <stdio.h>
int	main()
{
	char src[] = "cccccccccccccc";
	char dst[] = "aaaaaaaaaaaaaa";

	//memmove(dst, src, 5);
	ft_memmove(dst, src, 5);
	printf("%s", dst);
}
*/
