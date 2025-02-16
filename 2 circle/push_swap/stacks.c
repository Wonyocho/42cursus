/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 17:53:34 by wonyocho          #+#    #+#             */
/*   Updated: 2024/07/22 12:57:58 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	is_sorted(t_stack *a) // 정렬되어 있으면 1 반환
{
	t_node	*ptr;

	if (!a->top) // 맨처음이 null이면
		return (0);
	ptr = a->top;
	while (ptr->next)
	{
		if (ptr->value > ptr->next->value) // 오름차순 안되어 있으면 return 0
			return (0);
		ptr = ptr->next;
	}
	return (1);
}

t_node	*get_node(t_node *next, int value)
{
	t_node	*ptr;

	ptr = (t_node *)malloc(sizeof(t_node));
	ptr->value = value;
	ptr->next = next;
	return (ptr);
}

void	add_node(t_stack *stack, int value)
{
	t_node	*ptr;

	ptr = get_node(stack->top, value);
	if (!ptr)
		print_error();
	ptr->next = stack->top;
	stack->top = ptr;
	if (value > stack->max[0])
		stack->max[0] = value;
	if (value < stack->min)
		stack->min = value;
	stack->cnt++;
}

int	remove_node(t_stack *stack)
{
	int		value;
	t_node	*ptr;

	ptr = stack->top;
	value = ptr->value;
	stack->top = stack->top->next;
	free(ptr);
	stack->cnt--;
	return (value);
}