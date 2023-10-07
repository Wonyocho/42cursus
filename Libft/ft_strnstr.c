/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 15:43:24 by wonyocho          #+#    #+#             */
/*   Updated: 2023/10/07 16:11:55 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	int		i;
	int		len_ndl;
	char	*hst;
	char	*ndl;

	hst = (char *)haystack;
	ndl = (char *)needle;
	len_ndl = ft_strlen(ndl);
	i = 0;
	while (n > 0)
	{
		while (hst[i] == ndl[i] && ndl[i])
		{
			if (i + 1 == len_ndl)
				return (&hst[i]);
			i++;
			n--;
		}
		n--;
	}
	return (NULL);
}


#include <string.h>
#include <stdio.h>

int main()
{
	char haystack[] = "Foo Bar Baz";
	char needle[] = "Bar";
	char *ptr1 = strnstr(haystack, needle, 10);
	char *ptr2 = ft_strnstr(haystack, needle, 10);
	
	printf("strnstr: %s, ft_strnstr: %s\n", ptr1, ptr2);
}
