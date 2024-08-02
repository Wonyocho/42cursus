/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 19:14:59 by wonyocho          #+#    #+#             */
/*   Updated: 2024/08/02 17:50:32 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _MINISHELL_H_
# define _MINISHELL_H_

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <termios.h>

#include "libft.h"
#include "macro.h"

typedef struct s_cmd
{
	char	**cmd_line; // cmdline[0] = "echo", cmdline[1] = "hi", cmdline[2] = NULL
	int		flag; // flag 0: 세미콜론 또는 NULL, flag 1: 파이프
	int		single_quote; // 파싱과정에서 ' 또는 " 를 저장, 짝을 찾으면 0으로 초기화 됨.
	int		double_quote;
}t_cmd;

typedef struct s_data
{
	t_list	*lst;
	t_cmd 	*cmd_data; //위의 t_cmd 구조체를 t_data 안에 선언함으로써 t_data만으로 2개의 구조체 사용 가능
	char 	*buff;
}t_data;



// minishell.c
void	minishell();

// check_quotes.c
char	check_single_quotes(char *str);
char	check_double_quotes(char *str);

#endif













// void	exec_proc(t_list *head) // 인자는 연결리스트의 헤드포인터
// {
// 	t_list	*cur_proc;
// 	t_cmd	*cmd;

// 	cur_proc = head->next;
// 	while (cur_proc != NULL)
// 	{
// 		cmd = cur_proc->content; // 각 노드의 content는 data->cmd의 주소를 갖는다.
// 		if (cmd->cmdline[0]) // 명령어가 있으면 실행
// 		{
// 			if (cmd->flag == 1)
// 			 	exec_pipe(cur_proc, cmd);
//       else if (cmd->flag == 0)
// 				exec_cmd(cmd->cmdline); // 인자는 cur_proc->content->cmdline
// 		}
// 		cur_proc = cur_proc->next; // 다음 노드로 이동
// 	}
// 	ft_lstclear(&head, free_cmdline); // 연결리스트 비워줌
// }