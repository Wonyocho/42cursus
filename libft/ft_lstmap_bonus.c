/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 15:52:27 by wonyocho          #+#    #+#             */
/*   Updated: 2023/10/21 13:06:52 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*node_new;
	t_list	*node_result;
	void	*temp;

	if (!lst || !f || !del)
		return (0);
	node_result = NULL;
	while (lst)
	{
		temp = f(lst->content);
		if (!temp)
			return (node_result);
		node_new = ft_lstnew(temp);
		if (!node_new)
		{
			free(temp);
			ft_lstclear(&node_result, del);
			return (0);
		}
		ft_lstadd_back(&node_result, node_new);
		lst = lst->next;
	}
	node_new = NULL;
	return (node_result);
}
