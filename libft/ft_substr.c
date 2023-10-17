/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:13:57 by wonyocho          #+#    #+#             */
/*   Updated: 2023/10/17 16:41:12 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*arr;
	size_t	i;
	size_t	j;

	if (len > 4294967295)
		arr = (char *)malloc(ft_strlen(s) + 1);
	else
		arr = (char *)malloc(len + 1);
	if (!s || !(arr))
		return (0);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (i >= start && j < len)
		{
			arr[j] = s[i];
			j++;
		}
		i++;
	}
	arr[j] = '\0';
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
