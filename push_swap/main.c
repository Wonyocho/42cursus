/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 17:53:04 by wonyocho          #+#    #+#             */
/*   Updated: 2024/07/25 04:02:39 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	push_swap(t_stack *a, t_stack *b)
{
	t_op_cnt	op_cnt;

	if (is_sorted(a) == 1)
		return ;
	if (a->cnt < 4)
	{
		sort(a, b);
		return ;
	}
	while (a->cnt > 3)
	{
		get_optimized_value(a, b, &op_cnt);
		op_push_b(a, b, &op_cnt);
	}
	set_b_max_on_top(a, b);
	sort_3(a, b);
	while (b->top)
		do_op_1(a, b, "pa", 1);
}

static void	parsing(int limit, char **str, t_stack *a)
{
	int	i;

	i = 1;
	while (i < limit)
	{
		if (*str[i] == '\0')
			print_error();
		while (*str[i])
			str[i] = get_values(a, str[i]);
		i++;
	}
}


static void	init_stack(t_stack *stack)
{
	stack->top = NULL;
	stack->max[0] = INT_MIN;
	stack->min = INT_MAX;
	stack->cnt = 0; // 스택 카운트 0
}
 
static void	free_stack(t_stack *stack)
{
	t_node	*ptr;
	t_node	*tmp;

	ptr = stack->top;
	if (!ptr)
		return ;
	while (ptr)
	{
		tmp = ptr->next;
		free(ptr);
		ptr = tmp;
	}
	free(ptr);
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	init_stack(&a); // 스택 a 초기화
	init_stack(&b);	// 스택 b 초기화
	parsing(argc, argv, &a); // parsing
	push_swap(&a, &b); // push swap 시작
	free_stack(&a);
	free_stack(&b);
	return (0);
}
