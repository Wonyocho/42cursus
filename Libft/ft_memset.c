/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 16:26:30 by wonyocho          #+#    #+#             */
/*   Updated: 2023/10/06 17:20:37 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memset(void *b, int c, int len)
{
	int				i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *)b;
	if (c == '\0')
		return (0);
	while (len > 0)
	{
		str[i] = (unsigned char)c;
		i++;
		len--;
	}
	return (str);
}
/*
#include <stdio.h>
int	main()
{
	char str[] = "helloworldwonyocho";
	ft_memset(str, '\0', 5);
	printf("%s", str);
}
*/
