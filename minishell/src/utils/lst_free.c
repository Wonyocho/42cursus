/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaoh <chaoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 15:15:32 by wonyocho          #+#    #+#             */
/*   Updated: 2024/08/09 18:59:37 by chaoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

void	lst_free(t_list *lst)
{
	t_list	*tmp;
	t_env	*env;

	while (lst != NULL)
	{
		tmp = lst;
		env = (t_env *)lst->content; // content를 변환해줘서 free해줄것임미다
		if (env)
		{
			free(env->data);
			free(env->key);
			free(env->value);
			free(env);
		}
		lst = lst->content;
		free(tmp);
	}
}