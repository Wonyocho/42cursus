/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 17:21:51 by wonyocho          #+#    #+#             */
/*   Updated: 2023/10/06 17:33:50 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_bzero(void *s, int n)
{
	unsigned char	*str;
	int				i;

	i = 0;
	str = (unsigned char *)s;
	while (n > 0)
	{
		str[i] = 0;
		n--;
	}
}
/*
#include <strings.h>
#include <stdio.h>
int main()
{
	char str1[] = "helloworldwonyocho";
	char str2[] = "helloworldwonyocho";
	ft_bzero(str1, 0);
	bzero(str2, 0);
	printf("ft_bzero: %s\n", str1);
	printf("bzero: %s\n", str2);
}
*/
