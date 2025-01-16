/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qacjl <qacjl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 15:10:07 by qacjl             #+#    #+#             */
/*   Updated: 2025/01/16 15:14:28 by qacjl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	align_stack(t_list **stack_a)
{
	int	min_index;
	int	size;

	min_index = find_index(*stack_a, find_min(*stack_a));
	size = list_size(*stack_a);
	while ((*stack_a)->num != find_min(*stack_a))
	{
		if (min_index < size / 2)
			rotate_a(stack_a, 0);
		else
			reverse_rotate_a(stack_a, 0);
	}
}

void	place_max_on_top(t_list **stack_b)
{
	int	max_index;
	int	size;

	max_index = find_index(*stack_b, find_max(*stack_b));
	size = list_size(*stack_b);
	while ((*stack_b)->num != find_max(*stack_b))
	{
		if (max_index < size / 2)
			rotate_b(stack_b, 0);
		else
			reverse_rotate_b(stack_b, 0);
	}
}
