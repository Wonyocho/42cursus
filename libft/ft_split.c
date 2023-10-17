/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 14:13:58 by wonyocho          #+#    #+#             */
/*   Updated: 2023/10/17 10:23:06 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_sep(char str, char c)
{
	if (str == c)
		return (1);
	else if (str == '\0')
		return (1);
	return (0);
}

static int	word_count(char *str, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (check_sep(str[i + 1], c) == 1
			&& (check_sep(str[i], c) == 0))
			count++;
		i++;
	}
	return (count);
}

static void	word_write(char *dest, char *src, char c)
{
	int	i;

	i = 0;
	while (check_sep(src[i], c) == 0)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

static void	write_split(char **split, char *str, char c)
{
	int	i;
	int	j;
	int	word;

	word = 0;
	i = 0;
	while (str[i])
	{
		if (check_sep(str[i], c) == 1)
			i++;
		else
		{
			j = 0;
			while (check_sep (str[i + j], c) == 0)
				j++;
			split[word] = (char *)malloc(sizeof(char) * (j + 1));
			word_write(split[word], str + i, c);
			i = i + j;
			word++;
		}
	}
}

char	**ft_split(const char *s, char c)
{
	char	**array;
	int		word;
	char	*str;

	str = (char *)s;
	word = word_count(str, c);
	array = (char **)malloc(sizeof(char *) * (word + 1));
	if (!(array))
		return (0);
	array[word] = 0;
	write_split(array, str, c);
	return (array);
}
/*
#include <stdio.h>

int	main()
{
	char **a;

	a = ft_split("a1a2a3a4a5a6a", 'a');
	while (*a)
	{
		printf("%s\n", *a);
		a++;
	}
}
*/
