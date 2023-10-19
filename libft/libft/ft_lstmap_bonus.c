/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 15:52:27 by wonyocho          #+#    #+#             */
/*   Updated: 2023/10/19 21:39:13 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;

	new_lst = 0;
	while (lst)
	{
		new_lst = ft_lstnew(f(lst->content));
		if (!(new_lst))
		{
			ft_lstclear(&new_lst, del);
			return (0);
		}
		new_lst = new_lst->next;
		lst = lst->next;
	}
}

//temp
//temp_content 에다가 넣어서 하할당?