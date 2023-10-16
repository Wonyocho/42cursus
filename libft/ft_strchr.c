/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 20:22:51 by wonyocho          #+#    #+#             */
/*   Updated: 2023/10/16 17:36:00 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *str, int c)
{
	int		i;
	char	*s;

	i = 0;
	s = (char *)str;
	while (s[i])
	{
		if (s[i] == c)
			return (&s[i]);
		i++;
	}
	return (0);
}

#include <string.h>
#include <stdio.h>
int main()
{
	char str[] = "helloworld";
	char *ptr1 = strchr(str, '\0');
	char *ptr2 = ft_strchr(str, '\0');
	//if(ptr != NULL)
	//	printf("%c, %s", *ptr, ptr);
}

