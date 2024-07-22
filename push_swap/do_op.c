/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 17:53:15 by wonyocho          #+#    #+#             */
/*   Updated: 2024/07/22 12:58:13 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	print_op(const char *op, int print)
{
	if (print)
	{
		write(1, op, ft_strlen(op)); // op 출력하기
		write(1, "\n", 1);
	}
}

void	do_op_3(t_stack *a, t_stack *b, const char *op, int print)
{
	if (ft_strcmp(op, "ss") == 0)
	{
		swap(a);
		swap(b);
		print_op(op, print);
	}
	else if (ft_strcmp(op, "rr") == 0)
	{
		rotate(a);
		rotate(b);
		print_op(op, print);
	}
	else if (ft_strcmp(op, "rrr") == 0)
	{
		reverse_rotate(a);
		reverse_rotate(b);
		print_op(op, print);
	}
	else
		print_error();
}

void	do_op_2(t_stack *a, t_stack *b, const char *op, int print)
{
	if (ft_strcmp(op, "ra") == 0) // op가 ra면 rotate a
	{
		rotate(a);
		print_op(op, print);
	}
	else if (ft_strcmp(op, "rb") == 0)
	{
		rotate(b);
		print_op(op, print);
	}
	else if (ft_strcmp(op, "rra") == 0)
	{
		reverse_rotate(a);
		print_op(op, print);
	}
	else if (ft_strcmp(op, "rrb") == 0)
	{
		reverse_rotate(b);
		print_op(op, print);
	}
	else
		do_op_3(a, b, op, print);
}

void	do_op_1(t_stack *a, t_stack *b, const char *op, int print)
{
	if (ft_strcmp(op, "pa") == 0)
	{
		push(a, b);
		print_op(op, print);
	}
	else if (ft_strcmp(op, "pb") == 0)
	{
		push(b, a);
		print_op(op, print);
	}
	else if (ft_strcmp(op, "sa") == 0)
	{
		swap(a);
		print_op(op, print);
	}
	else if (ft_strcmp(op, "sb") == 0)
	{
		swap(b);
		print_op(op, print);
	}
	else
		do_op_2(a, b, op, print);
}

int	do_op(t_stack *a, t_stack *b, int n, const char *op)
{
	int	i;

	i = 0;
	while (i < n)
	{
		do_op_1(a, b, op, 1);
		i++;
	}
	return (i);
}
