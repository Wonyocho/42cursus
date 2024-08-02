/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 13:29:32 by wonyocho          #+#    #+#             */
/*   Updated: 2024/08/02 15:40:41 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	minishell()
{
	char	*str;
	t_cmd	cmd;
	
	while (1)
	{
		str = readline("minishell $ ");
		if (!str)
		 	break;
		if (*str != '\0')
		{
			printf("%s\n", str);

			// 1. split으로 str 자르기
			cmd.cmdline = ft_split(str, ' ');
			int i = 0;
			while (cmd.cmdline[i])
			{
				printf("%s\n", cmd.cmdline[i]);
				free(cmd.cmdline[i]);
				i++;
			}
			
			// 2. 자른거 중에서 파싱할 정보들 구조체에 저장
			// 3. 연결리스트에 담아서 실행부로 넘김
			
			add_history(str);
		}
		free(str);
	}
}
