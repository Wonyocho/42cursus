/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 14:29:52 by wonyocho          #+#    #+#             */
/*   Updated: 2023/10/11 16:50:46 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	int				i;
	unsigned char	*str;

	str = (unsigned char *)s;
	i = 0;
	while (n > 0)
	{
		if (str[i] == c)
			return (&str[i]);
		i++;
		n--;
	}
	return (0);
}
/*
#include <string.h>
#include <stdio.h>
int main ()
{
	char *pch;
	char str[] = "Example string";
	pch = (char*)memchr(str, 'p', -1);
	if (pch != NULL)
		printf("'p' found at position %ld.\n", pch - str + 1);
	else
		printf("'p' not found.\n");
}
*/
