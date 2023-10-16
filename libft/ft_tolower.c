/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 20:18:20 by wonyocho          #+#    #+#             */
/*   Updated: 2023/10/06 20:21:13 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int c)
{
	if ('A' <= c && c <= 'Z')
		c = c - 'A' + 'a';
	return (c);
}
/*
#include <ctype.h>
#include <stdio.h>
int	main ()
{
	int c = 'A';
	//printf("%d", tolower(c));
	printf("%d", ft_tolower(c));
}
*/
