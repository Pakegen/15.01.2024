/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qacjl <qacjl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 16:51:24 by qacjl             #+#    #+#             */
/*   Updated: 2024/12/23 18:37:39 by qacjl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_find_pivot(t_stack *a, int start, int end)
{
	(void)a;
	return ((start + end)  / 2);
}

void	ft_sort_stack(t_stack *a, t_stack *b)
{
	(void)b;
	if (a->top == 2)
	{
		if (a->data[2] > a->data[1])
			sa(a);
		if (a->data[1] > a->data[0])
			rra(a);
		if (a->data[2] > a->data[1])
			sa(a);
	}
	else if (a->top == 1)
	{
		if (a->data[1] > a->data[0])
			sa(a);
	}
}

void	ft_try_push_swap(t_stack *a, t_stack *b, int start, int end)
{
	int pivot;
	int count;

	pivot = ft_find_pivot(a, start, end);
	count = end - start + 1;
	if (end - start <= 3)
	{
		ft_sort_stack(a, b);
		return;
	}
	while (count--)
	{
		if (a->data[a->top] <= pivot)
			pb(a, b);
		else
			ra(a);
	}
	ft_try_push_swap(a, b, start, pivot);
	ft_try_push_swap(b, a, pivot + 1, end);
	while (b->top != -1)
		pa(a, b);
}

void	ft_execute_sorting(t_stack *a, t_stack *b)
{
	ft_try_push_swap(a, b, 0, a->top); //Quicksort use
}
