/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 13:28:54 by wonyocho          #+#    #+#             */
/*   Updated: 2023/10/12 14:58:24 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*arr;
	size_t	i;
	size_t	j;


	i = 0;
	if (!(s1))
		return (0);
	if (!(set))
		return (ft_strdup(s1));
	arr = ft_strdup(s1);
	while (arr[i++])
	{
		j = 0;
		while (arr[i] == set[j++])
			arr[i] == '\0';
	}
	i = 0;
	while (!(arr[i]))
		i++;
	return (&arr[i]);
}

#include <stdio.h>

int	main()
{
	char s1[] = "aaahelloworldaaa";
	char set[] = "a";

	printf("%s\n", ft_strtrim(s1, set));
}
