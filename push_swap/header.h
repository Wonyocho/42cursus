/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 17:53:07 by wonyocho          #+#    #+#             */
/*   Updated: 2024/07/22 13:06:28 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

enum {
	INT_MAX = 2147483647,
	INT_MIN = -2147483648
};

typedef struct s_node
{
	int				value;
	struct s_node	*next;
}				t_node;

typedef struct s_stack
{
	t_node	*top;	// 스택 맨위
	int		max[3];	// 최대
	int		min;	// 최소
	int		cnt;	// 스택 안에 개수
}				t_stack;

typedef struct s_op_cnt // operation count
{
	int		ra;
	int		rra;
	int		rb;
	int		rrb;
	char	min_type;
	int		min_cnt;
	t_node	*node;
}				t_op_cnt;

void	get_optimized_value(t_stack *a, t_stack *b, t_op_cnt *op_cnt);

/*
*** pb_and_set_b.c ***
*/
int		do_op(t_stack *a, t_stack *b, int n, const char *op);
void	op_push_b(t_stack *a, t_stack *b, t_op_cnt *op_cnt);
void	set_b_max_on_top(t_stack *a, t_stack *b);

/*
*** sort_3.c ***
*/
void	sort_3(t_stack *a, t_stack *b);
void	sort_2(t_stack *a, t_stack *b);
void	sort(t_stack *a, t_stack *b);

/*
*** get_values.c ***
*/
void	print_error(void);
void	add_last(t_stack *stack, int value);
char	*atoi_values(t_stack *a, const char *str, int sign);
char	*get_values(t_stack *a, const char *str);

/*
*** do_op.c ***
*/
int		is_sorted(t_stack *a);
void	do_op_3(t_stack *a, t_stack *b, const char *op, int print);
void	do_op_2(t_stack *a, t_stack *b, const char *op, int print);
void	do_op_1(t_stack *a, t_stack *b, const char *op, int print);

/*
*** op.c ***
*/
void	push(t_stack *a, t_stack *b);
void	swap(t_stack *a);
void	rotate(t_stack *a);
void	reverse_rotate(t_stack *a);

/*
*** utils.c ***
*/
t_node	*get_node(t_node *next, int value);
void	add_node(t_stack *stack, int value);
int		remove_node(t_stack *stack);

#endif