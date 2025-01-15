/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qacjl <qacjl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 17:39:02 by qacjl             #+#    #+#             */
/*   Updated: 2024/12/23 19:24:08 by qacjl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*init_stack(int capacity)
{
	t_stack *stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return NULL;
	stack->data = malloc(sizeof(int) * capacity);
	if (!stack->data)
		return (free(stack), NULL);
	stack->top = -1;
	stack->capacity = capacity;
	return stack;
}
