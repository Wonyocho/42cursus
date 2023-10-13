/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 15:03:17 by wonyocho          #+#    #+#             */
/*   Updated: 2023/10/13 17:56:28 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t			len;
	unsigned int	i;

	len = ft_strlen(s);
	i = 0;
	while (i < len)
	{
		f(i, &s[i]);
		i++;
	}
}
/*
void	ft_sunghoch(unsigned int n, char *s)
{
	printf("%d", n);
	printf("%s\n", s);
}

int	main()
{
	char *s = "he";

	ft_striteri(s, ft_sunghoch);
	printf("%s\n", s);
}
*/
