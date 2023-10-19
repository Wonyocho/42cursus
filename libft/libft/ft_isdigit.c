/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:22:18 by wonyocho          #+#    #+#             */
/*   Updated: 2023/10/16 15:10:47 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	if ('0' <= c && c <= '9')
		return (4);
	else
		return (0);
}
/*
#include <stdio.h>
int main()
{
	int a = 'a';
	int b = '1';
	printf("%d\n", ft_isdigit(a));
	printf("%d\n", ft_isdigit(b));
}
*/
