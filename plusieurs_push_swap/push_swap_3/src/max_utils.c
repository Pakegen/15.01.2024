/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qacjl <qacjl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 19:01:31 by qacjl             #+#    #+#             */
/*   Updated: 2025/01/16 19:15:41 by qacjl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_without_max(t_list **stack_a)
{
	if (!is_sorted(*stack_a)) // Si stack_a n'est pas triée
		sort_three(stack_a); // Trie les 3 éléments restants
}

void	place_max(t_list **stack_a)
{
	int		max_value;
	int		max_index;
	int		stack_size;

	max_value = find_max(*stack_a); // Trouve la valeur max
	max_index = find_index(*stack_a, max_value); // Trouve son index
	stack_size = list_size(*stack_a);

	// Si le maximum est dans la première moitié de la pile
	if (max_index < stack_size / 2)
	{
		while ((*stack_a)->num != max_value)
			rotate_a(stack_a, 0); // Rotation jusqu'à ce que le maximum soit à la fin
	}
	else
	{
		while ((*stack_a)->num != max_value)
			reverse_rotate_a(stack_a, 0); // Inverse rotation pour placer le maximum
	}
}

t_list *move_to_stack_b_for_max(t_list **stack_a)
{
    t_list *stack_b = NULL;

    while (*stack_a && (*stack_a)->num != find_max(*stack_a))
    {
        push_b(stack_a, &stack_b, 0);
    }

    return stack_b;
}
