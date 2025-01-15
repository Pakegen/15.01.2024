/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_argument_1.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qacjl <qacjl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 16:13:09 by qacjl             #+#    #+#             */
/*   Updated: 2024/12/24 04:05:08 by qacjl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *a)
{
	swap(a);
	ft_printf("sa\n");
}

void	sb(t_stack *b)
{
	swap(b);
	ft_printf("sb\n");
}

void	ss(t_stack *a, t_stack *b)
{
	swap(a);
	swap(b);
	printf("ss");
}

void	pa(t_stack *a, t_stack *b)
{
	int	value;

	if (b->top != -1)
	{
		value = pop(b);
		push(a, value);
		ft_printf("pa\n");
	}
}
void	pb(t_stack *a, t_stack *b)
{
	int	value;

	if (a->top != -1)
	{
		value = pop(a);
		push(b, value);
		printf("pb\n");
	}
}

