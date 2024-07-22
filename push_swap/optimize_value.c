/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize_value.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 17:53:26 by wonyocho          #+#    #+#             */
/*   Updated: 2024/07/22 01:46:39 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	count_op_a(t_node *node, t_stack *a, t_op_cnt *op_cnt)
{
	t_node	*ptr;

	if (a->cnt == 0)
		return ;
	ptr = a->top;
	op_cnt->ra = 0;
	while (ptr && (ptr != node))
	{
		ptr = ptr->next;
		op_cnt->ra++;
	}
	op_cnt->rra = a->cnt - op_cnt->ra;
}

static void	count_op_b(t_node *node, t_stack *b, t_op_cnt *op_cnt)
{
	t_node	*ptr;
	int		tmp;
	int		i;

	if (b->cnt == 0)
		return ;
	tmp = INT_MIN;
	i = 0;
	ptr = b->top;
	while (ptr && ++i)
	{
		if (b->min < node->value && ptr->value >= tmp && ptr->value < node->value)
		{
			tmp = ptr->value;
			op_cnt->rb = i - 1;
		}
		if (b->min > node->value && ptr->value >= tmp)
		{
			tmp = ptr->value;
			op_cnt->rb = i - 1;
		}
		ptr = ptr->next;
	}
	op_cnt->rrb = b->cnt - op_cnt->rb;
}

static void	select_min_op(t_node *node, t_stack *a, t_stack *b, t_op_cnt *op_cnt)
{
	int	ra_rb;
	int	rra_rrb;
	int	r_rr;

	//0 으로 일단 다 초기화 하고
	op_cnt->ra = 0;
	op_cnt->rb = 0;
	op_cnt->rra = 0;
	op_cnt->rrb = 0;
	op_cnt->node = node;
	// 이제 각각 카운트 세기
	count_op_a(node, a, op_cnt);
	count_op_b(node, b, op_cnt);
	ra_rb = ft_max(op_cnt->ra, op_cnt->rb); // ra, rb중에
	rra_rrb = ft_max(op_cnt->rra, op_cnt->rrb); // rra, rrb중에
	r_rr = ft_min(op_cnt->ra, op_cnt->rra) + ft_min(op_cnt->rb, op_cnt->rrb); //
	
	op_cnt->min_cnt = ft_min(ra_rb, rra_rrb);
	op_cnt->min_cnt = ft_min(op_cnt->min_cnt, r_rr);
	if (op_cnt->min_cnt == ra_rb)
		op_cnt->min_type = 1;
	else if (op_cnt->min_cnt == rra_rrb)
		op_cnt->min_type = 2;
	else
		op_cnt->min_type = 3;
}

static void	set_a_max(t_stack *a)
{
	t_node	*ptr;
	int		tmp;

	ptr = a->top; // a 맨위
	tmp = INT_MIN;
	while (ptr) // 마지막 까지
	{
		if (ptr->value < a->max[0] && ptr->value >= tmp) // max보다 작고 tmp보다 크면
			tmp = ptr->value;	//t tmp 를 최신화
		ptr = ptr->next; // 다음이동
	}
	a->max[1] = tmp; // max배열에 저장
	ptr = a->top;
	tmp = INT_MIN;
	while (ptr)
	{
		if (ptr->value < a->max[1] && ptr->value >= tmp)
			tmp = ptr->value;
		ptr = ptr->next;
	}
	a->max[2] = tmp; // 2번째까지 저장
}

void	get_optimized_value(t_stack *a, t_stack *b, t_op_cnt *op_cnt)
{
	t_node		*ptr;
	t_op_cnt	tmp;

	set_a_max(a); // 하고나면 a->max에 max값이 3개 저장되어 있는 상태
	ptr = a->top;
	// 1차 건너뛰기
	while (ptr->value == a->max[0] || ptr->value == a->max[1]
		|| ptr->value == a->max[2]) // 최대값은 따로 처리하려고
		ptr = ptr->next;
	select_min_op(ptr, a, b, op_cnt);
	ptr = a->top;
	while (ptr)
	{
		select_min_op(ptr, a, b, &tmp);
		if (tmp.min_cnt < op_cnt->min_cnt && ptr->value != a->max[0]
			&& ptr->value != a->max[1] && ptr->value != a->max[2])
			*op_cnt = tmp;
		ptr = ptr->next;
	}
}
