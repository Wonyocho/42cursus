/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 17:53:28 by wonyocho          #+#    #+#             */
/*   Updated: 2024/07/22 00:47:42 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	sort_3(t_stack *a, t_stack *b)
{
	int	first;
	int	second;
	int	third;

	first = a->top->value;
	second = a->top->next->value;
	third = a->top->next->next->value;
	if (first > second && second > third && first > third)
	{
		do_op_1(a, b, "sa", 1);
		do_op_1(a, b, "rra", 1);
	}
	else if (first < second && second > third && first < third)
	{
		do_op_1(a, b, "rra", 1);
		do_op_1(a, b, "sa", 1);
	}
	else if (first > second && second < third && first < third)
		do_op_1(a, b, "sa", 1);
	else if (first < second && second > third && first > third)
		do_op_1(a, b, "rra", 1);
	else if (first > second && second < third && first > third)
		do_op_1(a, b, "ra", 1);
}

void	sort_2(t_stack *a, t_stack *b)
{
	if (a->top->value > a->top->next->value)
		do_op_1(a, b, "sa", 1);
}

void	sort(t_stack *a, t_stack *b)
{
	if (a->cnt == 3)
		sort_3(a, b);
	else if (a->cnt == 2)
		sort_2(a, b);
	else
		return ;
}