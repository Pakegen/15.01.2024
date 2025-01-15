/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qacjl <qacjl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 17:38:24 by qacjl             #+#    #+#             */
/*   Updated: 2024/12/23 17:57:25 by qacjl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pop(t_stack *stack)
{
	if (stack->top == -1)
		return (-1);
	return (stack->data[stack->top--]);
}

void	swap(t_stack *stack)
{
	int	temp;

	if (stack->top < 1)
		return;
	temp = stack->data[stack->top];
	stack->data[stack->top] = stack->data[stack->top -1];
	stack->data[stack->top - 1] = temp;
}

void	rotate(t_stack *stack)
{
	int	temp;
	int	i;

	if (stack->top < 1)
		return;
	temp = stack->data[stack->top];
	i = stack->top;
	while (i > 0)
	{
		stack->data[i] = stack->data[i -1];
		i--;
	}
	stack->data[0] = temp;
}

void	reverse_rotate(t_stack *stack)
{
	int	temp;
	int	i;

	if (stack->top < 1)
		return;
	temp = stack->data[0];
	i = 0;
	while (i < stack->top)
	{
		stack->data[i] =stack->data[i + 1];
		i++;
	}
	stack->data[stack->top] = temp;
}
