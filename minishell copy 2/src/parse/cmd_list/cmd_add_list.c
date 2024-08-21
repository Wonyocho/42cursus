/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_add_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 18:36:49 by wonyocho          #+#    #+#             */
/*   Updated: 2024/08/21 20:59:28 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd_list	*create_cmd_list(t_token *total_token_list)
{
	t_cmd_list	*cmd_list;
	t_cmd_list	*ptr;
	t_token		*start_token;
	t_token		*end_token;

	cmd_list = init_cmd_node(total_token_list);
	ptr = cmd_list;
	while (total_token_list)
	{
		if (ft_strcmp(total_token_list->str, "|") == 0 || total_token_list->next == NULL)
		{
			ptr->token_list = cut_token_list(cmd_list, end_token);
			while (ptr->token_list)
			{
				ptr->token_list = ptr->token_list->next;
			}
			ptr->argc = get_argc(cmd_list->token_list);
			ptr->argv = get_argv(cmd_list, cmd_list->token_list);
			start_token = total_token_list->next;
			cmd_list->next = init_cmd_node(start_token); // next에 하나 새로 만들고
			ptr = cmd_list->next;
		}
		end_token = total_token_list;
		total_token_list = total_token_list->next;
	}
	return (cmd_list);
}

t_cmd_list *init_cmd_node(t_token *cur_token_list)
{
	t_cmd_list *result;

	result = ft_calloc(1, sizeof(t_cmd_list));
	if (!result)
		return (NULL);
	result->token_list = cur_token_list;
	result->argc = 0;
	result->argv = NULL;
	result->input_fd = -1;

	return (result);
}

t_token *cut_token_list(t_cmd_list *cmd_list, t_token *end_token)
{
	t_token *result;
	t_token *end;

	result = cmd_list->token_list;
	while (ft_strcmp(result->str, end_token->str) != 0) // endtoken이랑 같지 않을떄까지
	{
		result = result->next;
	}
	end = ft_calloc(1, sizeof(t_token));
	end->str = NULL;
	end->type = 0;
	cmd_list->token_list->next = end; // 자르기
	return (result);
}

int	get_argc(t_token *token_list)
{
	t_token *ptr;
	int 	argc;

	ptr = token_list;
	argc = 0;
	while (ptr)
	{
		argc++;
		ptr = ptr->next;
	}
	return (argc);
}

char **get_argv(t_cmd_list *cmd_list, t_token *token_list)
{
	int 	i;
	int		argc;
	t_token	*ptr_token;


	// 만약에 리다이렉션이 있으면 argc -2 해야함
	argc = cmd_list->argc;
	i = 0;
	ptr_token = token_list;
	while (ptr_token)
	{
		if ((ft_strcmp(ptr_token->str, "<") == 0) || (ft_strcmp(ptr_token->str, ">") == 0))
			argc -= 2;
		ptr_token = ptr_token->next;
	}


	
	cmd_list->argv = ft_calloc((argc), sizeof(char *));
	if (!cmd_list->argv)
		return (NULL);


	i = 0;
	while (ptr_token && i < argc)
	{
		if (get_token_type(ptr_token->str) != 1)
		{
			ptr_token = ptr_token->next->next;
			continue;
		}
		cmd_list->argv[i] = ft_strdup(ptr_token->str);
		ptr_token = ptr_token->next;
		i++;
	}
	cmd_list->argv[i] = NULL;
	return (cmd_list->argv);
}
