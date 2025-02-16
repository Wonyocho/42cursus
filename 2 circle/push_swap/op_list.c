/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 17:53:21 by wonyocho          #+#    #+#             */
/*   Updated: 2024/07/21 17:53:22 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	push(t_stack *a, t_stack *b)
{
	if (!b->cnt)
		return ;
	add_node(a, remove_node(b));
}

void	swap(t_stack *a)
{
	int		tmp;

	if (a->cnt <= 1)
		return ;
	tmp = a->top->value;
	a->top->value = a->top->next->value;
	a->top->next->value = tmp;
}

void	rotate(t_stack *a)
{
	t_node	*ptr;
	t_node	*tmp;

	if (a->cnt <= 1)
		return ;
	ptr = a->top;  // a: 1 2 3 4 5 이면 ptr: 1
	tmp = a->top->next; // tmp = 2;
	while (ptr->next)
		ptr = ptr->next; //ptr 맨뒤에서 한번 전으로 보내고
	ptr->next = a->top; // ptr->next(맨마지막이): 1
	ptr->next->next = NULL; // 그뒤는 null
	a->top = tmp; // a->top = 2; 즉, 2 3 4 5 1이 된다.
}

void	reverse_rotate(t_stack *a)
{
	t_node	*ptr;
	t_node	*tmp;

	if (a->cnt <= 1)
		return ;
	ptr = a->top; // a: 1 2 3 4 5, ptr: 1
	while (ptr->next)
	{
		if (ptr->next->next == NULL)
			tmp = ptr; // tmp: 4
		ptr = ptr->next;
	} // ptr은 5를 가리키고 있음
	tmp->next = NULL; // 4다음은 NULL로해버리고
	ptr->next = a->top; // null 이었던걸 ptr->next: 1
	a->top = ptr; // a->top = 5 즉, 5 1 2 3 4가 된다
}
