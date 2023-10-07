/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:18:23 by wonyocho          #+#    #+#             */
/*   Updated: 2023/10/06 19:56:23 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(const char *src)
{
	int	i;

	i = 0;
	while (src[i])
		i++;
	return (i);
}

unsigned int	ft_strlcpy(char *dest, const char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	n;

	i = 0;
	n = ft_strlen(src);
	while (size > 1 && src[i])
	{
		dest[i] = src[i];
		i++;
		size--;
	}
	dest[i] = '\0';
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
	strlcpy(dst, src, 4);
	printf("%s", dst);
	//printf("%d", ft_strlcpy(dst, src, 5));
}
*/
