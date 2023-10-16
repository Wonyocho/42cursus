/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 15:43:24 by wonyocho          #+#    #+#             */
/*   Updated: 2023/10/16 11:53:50 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	i;
	size_t	j;
	char	*hst;
	char	*ndl;

	hst = (char *)haystack;
	ndl = (char *)needle;
	i = 0;
	j = 0;
	while (n > 0)
	{
		while (hst[j] == ndl[i] && ndl[i] && n > 0)
		{
			if (i + 1 == ft_strlen(ndl))
				return (&hst[j - ft_strlen(ndl) + 1]);
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
	char haystack[] = "Foo Bar Baz";
	char needle[] = "F";
	char *ptr1 = strnstr(haystack, needle, 1);
	char *ptr2 = ft_strnstr(haystack, needle, 1);
	
	printf("\n   strnstr: %s\nft_strnstr: %s\n\n", ptr1, ptr2);
}
*/
