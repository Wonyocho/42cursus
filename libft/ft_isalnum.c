/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:35:49 by wonyocho          #+#    #+#             */
/*   Updated: 2023/10/16 15:11:36 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(int c)
{
	if ('a' <= c && c <= 'z')
		return (1);
	else if ('A' <= c && c <= 'Z')
		return (1);
	else if ('0' <= c && c <= '9')
		return (1);
	else
		return (0);
}
/*
#include <stdio.h>
int main ()
{
	int c = '^';
	printf("%d", ft_isalnum(c));
}
*/
