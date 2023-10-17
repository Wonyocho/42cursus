/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 15:43:24 by wonyocho          #+#    #+#             */
/*   Updated: 2023/10/17 16:26:32 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	i;
	size_t	j;

	j = 0;
	if (*needle == '\0')
		return ((char *)haystack);
	if (ft_strlen(haystack) < ft_strlen(needle))
		return (NULL);
	while (n > 0 && haystack[j])
	{
		i = 0;
		while (haystack[j] == needle[i] && needle[i] && n > 0)
		{
			if (i + 1 == ft_strlen(needle))
				return (&((char *)haystack)[j - ft_strlen(needle) + 1]);
			i++;
			j++;
			n--;
		}
		if (n == 0)
			return (NULL);
		j++;
		n--;
	}
	return (NULL);
}
/*
#include <string.h>
#include <stdio.h>

int main()
{
	char haystack[] = "abc abcdef";
	char needle[] = "abcdef";
	char *ptr1 = strnstr(haystack, needle, 15);
	char *ptr2 = ft_strnstr(haystack, needle, 15);
	
	printf("\n   strnstr: %s\nft_strnstr: %s\n\n", ptr1, ptr2);
	//printf("%s\n",ptr1);
}
*/