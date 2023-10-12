/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 17:02:59 by wonyocho          #+#    #+#             */
/*   Updated: 2023/10/12 11:48:11 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s1)
{
	int	i;

	i = 0;
	while (s1[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*arr;
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;
	size_t			j;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	arr = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	i = 0;
	j = 0;
	while (str1[i])
	{
		arr[i] = str1[i];
		i++;
	}
	while (str2[j])
	{
		arr[i] = str2[j];
		i++;
		j++;
	}
	arr[i] = 0;
	return (arr);
}
/*
#include <stdio.h>

int	main()
{
	char s1[] = "";
	char s2[] = "world";

	printf("%s\n", ft_strjoin(s1, s2));
}
*/
