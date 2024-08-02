/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_quotes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 17:24:56 by wonyocho          #+#    #+#             */
/*   Updated: 2024/08/02 17:49:15 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	check_single_quotes(char *str)
{
	int	result;
	int	cnt;

	cnt = 0;
	while (*str)
	{
		if (*str == '\'')
			cnt++;
		str++;
	}
	if (cnt % 2 == 1)
		result = T_SINGLE_QUOTE;
	else
		result = 0;
	return (result);
}

char	check_double_quotes(char *str)
{
	int result;
	int	cnt;

	cnt = 0;
	while (*str)
	{
		if (*str == '\"')
			cnt++;
		str++;
	}
	if (cnt % 2 == 1)
		result = T_DOUBLE_QUOTE;
	else
		result = 0;		
	return (result);
}
