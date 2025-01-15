/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qacjl <qacjl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 16:10:38 by qacjl             #+#    #+#             */
/*   Updated: 2024/12/23 18:25:18 by qacjl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_resize_stack(t_stack *stack)
{
	int	new_capacity;
	int	*new_data;
	int	i;

	new_capacity = stack->capacity * 2;
	new_data = malloc(sizeof(int) * new_capacity);
	if (!new_data)
	{
		write(2, "MEMORY ALLOCATION FAIL\n", 24);
		exit (EXIT_FAILURE);
	}
	i = 0;
	while (i <= stack->top)
	{
		new_data[i] = stack->data[i];
		i++;
	}
	free(stack->data);
	stack->data = new_data;
	stack->capacity = new_capacity;
}

void	push(t_stack *stack, int value)
{
	if (stack->top == stack->capacity - 1)
		ft_resize_stack(stack);
	stack->top++;
	stack->data[stack->top] = value;
}
