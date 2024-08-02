/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 13:29:32 by wonyocho          #+#    #+#             */
/*   Updated: 2024/08/02 17:50:32 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	loop(t_data *data, t_cmd *cmd)
{
	char	*str;
	
	while (1)
	{
		str = readline("minishell $ ");
		if (!str)
		 	break;
		if (*str != '\0')
		{
			// cmd->flag 작업 해야함
			cmd->single_quote = check_single_quotes(str); // 매크로: 짝이 안맞음
			cmd->double_quote = check_double_quotes(str); // 매크로: 짝이 안맞음
			// split으로 줄때 ', " 지우고 명령어만 넘길지 물어보기. 아니면 일단 넘겨주고 채린 입맛대로 할건지 물어보기
			cmd->cmd_line = ft_split(str, ' ');
			data->cmd_data = cmd;

			printf("str:%s\nsq:%d dq:%d\n", str, cmd->single_quote, cmd->double_quote);
			int i = 0;
			while (cmd->cmd_line[i])
			{
				printf("%s\n", cmd->cmd_line[i]);
				i++;
			}

			add_history(str);
		}
		free(str);
	}
}


void	minishell()
{
	t_cmd	*cmd;
	t_data	*data;

	cmd = (t_cmd *)malloc(sizeof(t_cmd));
	if (!cmd)
		return ;
	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return ;
	loop(data, cmd);
}
