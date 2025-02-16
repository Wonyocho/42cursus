/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 11:44:17 by wonyocho          #+#    #+#             */
/*   Updated: 2023/11/23 13:06:35 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		size;
	char	*result;
	int		i;
	int		j;

	i = 0;
	size = ft_strlen(s1) + ft_strlen(s2);
	result = malloc(sizeof(char) * (size + 1));
	if (!result || !s1 || !s2)
		return (NULL);
	while (s1[i] != 0)
	{
		result[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != 0)
	{
		result[i + j] = s2[j];
		j++;
	}
	result[size] = 0;
	return (result);
}

char	*ft_strchr(const char *str, int c)
{
	char	*buf;

	buf = (char *)str;
	while (*buf != c && *buf != 0)
		buf++;
	if (*buf == c)
		return (buf);
	else
		return (NULL);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*result;
	size_t	i;

	i = 0;
	result = malloc(size * count);
	if (!result)
		return (NULL);
	while (i < count * size)
	{
		result[i] = '\0';
		i++;
	}
	return (result);
}

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
