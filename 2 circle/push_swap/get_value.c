/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_value.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 17:53:09 by wonyocho          #+#    #+#             */
/*   Updated: 2024/07/22 00:31:02 by wonyocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	print_error(void)
{	
	write(2, "Error\n", 6);
	exit(1);
}

void	add_last(t_stack *stack, int elem)
{
	t_node	*ptr;

	if (!stack->top) // 스택이 null이면
		stack->top = get_node(NULL, elem); 
	else
	{
		ptr = stack->top;
		while (ptr->next) // 포인터를 맨마지막 까지 이동
			ptr = ptr->next;
		ptr->next = get_node(NULL, elem); // 추가하기
		if (!ptr->next) // 만약 null이면 에러처리
			print_error();
	}
	if (elem > stack->max[0]) // 만약 값이 max보다 크다ㅏ면
		stack->max[0] = elem;
	if (elem < stack->min)	// min보다 작으면
		stack->min = elem;
	stack->cnt++; // stack 개수 ++
}

char	*atoi_values(t_stack *a, const char *str, int sign)
{
	long long	num;
	t_node		*ptr;

	num = 0;
	if (*str < '0' || *str > '9') // 에러처리
		print_error();
	while ('0' <= *str && *str <= '9') // 숫자이면 atoi처럼
	{
		num = num * 10 + (*str++ - '0');
		if (sign * num < INT_MIN || sign * num > INT_MAX) // 부호를 곱한게 에러이면
			print_error();
	}
	ptr = a->top; // 스택으로 포인터 이동
	while (ptr != NULL) // 스택 전부 돌면서
	{
		if (ptr->value == sign * num) // 중복값이 있으면 에러
			print_error();
		ptr = ptr->next; // 계속 뒤로 이동
	}
	add_last(a, sign * num);
	return ((char *)str);
}

char	*get_values(t_stack *a, const char *str)
{
	int	sign;

	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32) // 공백이면 패스
		str++;
	if (*str == '-') // 음수이면
	{
		str++;
		sign = -1;
	}
	if (*str == '\0') // 문자 마지막이면(널이면)
		return ((char *)str); // 리턴
	return (atoi_values(a, str, sign));
}
