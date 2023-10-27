/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 13:40:31 by wonyocho          #+#    #+#             */
/*   Updated: 2023/10/27 13:37:59 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(char *s1)
{
	char			*dst;
	size_t			len_src;
	unsigned int	i;

	i = 0;
	len_src = ft_strlen(s1);
	dst = (char *)malloc(len_src + 1);
	if (!(dst))
		return (0);
	else
	{
		while (s1[i])
		{
			dst[i] = s1[i];
			i++;
		}
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char			*arr;
	size_t			i;
	size_t			j;

	arr = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!(arr))
		return (0);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		arr[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		arr[i] = s2[j];
		i++;
		j++;
	}
	arr[i] = 0;
	return (arr);
}

char	*ft_strchr(char *str, int c)
{
	int		i;

	i = 0;
	if (!str)
		return (NULL);
	if ((char)c == 0)
	{
		while (str[i])
			i++;
		return (&str[i]);
	}
	while (str[i] != '\0')
	{
		if (str[i] == (char)c)
			return (&str[i]);
		i++;
	}
	return (0);
}
