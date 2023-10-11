/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:13:57 by wonyocho          #+#    #+#             */
/*   Updated: 2023/10/11 16:47:35 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*arr;
	unsigned char	*str;
	unsigned int	i;

	str = (unsigned char *)s;
	arr = (char *)malloc(len);
	i = 0;
	if (!(arr))
		return (0);
	if (s == NULL)
		return (0);
	if (ft_strlen(s) < start)
		return (0);
	while (i < len)
	{
		arr[i] = str[start];
		i++;
		start++;
	}
	return (arr);
}
/*
#include <stdio.h>

int	main()
{
	char s[] = "helloworld";
	printf("ft_substr: %s\n", ft_substr(s, 5, 4));
}
*/
