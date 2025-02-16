/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb_set_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 17:53:31 by wonyocho          #+#    #+#             */
/*   Updated: 2024/07/22 13:06:17 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	set_b_max_on_top(t_stack *a, t_stack *b)
{
	int		i;
	int		idx;
	int		tmp;
	t_node	*ptr;

	i = 0;
	tmp = INT_MIN;
	ptr = b->top;
	while (ptr)
	{
		if (ptr->value >= tmp)
		{
			tmp = ptr->value;
			idx = i;
		}
		i++;
		ptr = ptr->next;
	}
	if (idx < (b->cnt - idx) % b->cnt)
		do_op(a, b, idx, "rb");
	else
		do_op(a, b, (b->cnt - idx) % b->cnt, "rrb");
}

static void	op_push_b_2(t_stack *a, t_stack *b, t_op_cnt *op_cnt)
{
	if (op_cnt->ra < op_cnt->rra) // ra한 횟수가 rra 횟수 보다 작으면 ra
		do_op(a, b, op_cnt->ra, "ra");
	else
		do_op(a, b, op_cnt->rra, "rra");
	if (op_cnt->rb < op_cnt->rrb)
		do_op(a, b, op_cnt->rb, "rb");
	else
		do_op(a, b, op_cnt->rrb, "rrb");
}

void	op_push_b(t_stack *a, t_stack *b, t_op_cnt *op_cnt)
{
	int	i;

	if (op_cnt->min_type == 1)
	{
		i = do_op(a, b, ft_min(op_cnt->ra, op_cnt->rb), "rr");
		if (op_cnt->ra > op_cnt->rb)
			do_op(a, b, op_cnt->ra - i, "ra");
		else
			do_op(a, b, op_cnt->rb - i, "rb");
	}
	else if (op_cnt->min_type == 2)
	{
		i = do_op(a, b, ft_min(op_cnt->rra, op_cnt->rrb), "rrr");
		if (op_cnt->rra > op_cnt->rrb)
			do_op(a, b, op_cnt->rra - i, "rra");
		else
			do_op(a, b, op_cnt->rrb - i, "rrb");
	}
	else
		op_push_b_2(a, b, op_cnt);
	do_op_1(a, b, "pb", 1);
}