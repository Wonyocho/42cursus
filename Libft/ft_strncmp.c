/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 14:16:18 by wonyocho          #+#    #+#             */
/*   Updated: 2023/10/11 16:50:21 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(char *s1, char *s2, size_t n)
{
	int	i;

	i = 0;
	while (n > 0 && (s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
		n--;
	}
	return (0);
}
/*
#include <string.h>
#include <stdio.h>
int	main()
{
	char s1[] = "helloworld";
	char s2[] = "helloworlD";
	int a = strncmp(s1, s2, 15);
	int	b = ft_strncmp(s1, s2, 15);
	printf("strncmp: %d, ft_strncmp: %d\n", a, b);

}
*/
