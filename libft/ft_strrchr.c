/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 14:02:47 by wonyocho          #+#    #+#             */
/*   Updated: 2023/10/16 11:36:15 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*s;
	int		i;

	s = (char *)str;
	i = ft_strlen(s);
	while (i > 0)
	{
		if (s[i] == c)
			return (&s[i]);
		i--;
	}
	return (0);
}
/*
#include <string.h>
#include <stdio.h>

int main()
{
	char str[] = "helloworld";
	char *ptr = ft_strrchr(str, 'e');
	printf("%c, %s", *ptr, ptr);
}
*/
