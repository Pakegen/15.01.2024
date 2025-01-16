/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qacjl <qacjl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 14:41:16 by qacjl             #+#    #+#             */
/*   Updated: 2025/01/16 19:11:43 by qacjl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack(t_list **stack_a)
{
	t_list	*stack_b;

	// Étape 1 : Déplacer les éléments vers stack_b sauf le maximum
	stack_b = move_to_stack_b_for_max(stack_a);

	// Étape 2 : Trier stack_a sans inclure le maximum
	if (!is_sorted(*stack_a))
		sort_without_max(stack_a);

	// Étape 3 : Renvoyer les éléments dans stack_a
	stack_a = move_back_to_stack_a(stack_a, &stack_b);

	// Étape 4 : Placer le maximum à la fin
	place_max(stack_a);
}




void	sort_three(t_list **stack)
{
	int	first;
	int	second;
	int	third;

	if (!stack || list_size(*stack) != 3)
		return ;
	first = (*stack)->num;
	second = (*stack)->next->num;
	third = (*stack)->next->next->num;
	if (first > second && second < third && first < third)
		swap_a(stack, 0);
	else if (first > second && second > third)
	{
		swap_a(stack, 0);
		reverse_rotate_a(stack, 0);
	}
	else if (first > second && second < third)
		rotate_a(stack, 0);
	else if (first < second && second > third && first < third)
	{
		swap_a(stack, 0);
		rotate_a(stack, 0);
	}
	else if (first < second && second > third)
		reverse_rotate_a(stack, 0);
}
t_list	*move_to_stack_b(t_list **stack_a)
{
	t_list	*stack_b = NULL;
	int		min_value;

	// Trouver la valeur minimale pour référence
	min_value = find_min(*stack_a);

	while (list_size(*stack_a) > 3)
	{
		// Si l'élément courant est le plus petit, évite de le pousser
		if ((*stack_a)->num == min_value)
		{
			rotate_a(stack_a, 0); // Rotation pour le laisser en bas
		}
		else
		{
			push_b(stack_a, &stack_b, 0); // Sinon, pousse dans stack_b
		}
	}

	return stack_b;
}


t_list	**move_back_to_stack_a(t_list **stack_a, t_list **stack_b)
{
	int	min_value;
	int	index_min;

	while (*stack_b)
	{
		push_a(stack_a, stack_b, 0); // Pousser chaque élément de stack_b vers stack_a
	}

	// Une fois que tout est dans stack_a, s'assurer que le plus petit est en haut
	min_value = find_min(*stack_a);
	index_min = find_index(*stack_a, min_value);

	// Décider si on doit utiliser rotate ou reverse_rotate pour optimiser les mouvements
	if (index_min <= list_size(*stack_a) / 2)
	{
		while ((*stack_a)->num != min_value)
			rotate_a(stack_a, 0);
	}
	else
	{
		while ((*stack_a)->num != min_value)
			reverse_rotate_a(stack_a, 0);
	}

	return stack_a;
}
int find_index(t_list *stack, int value)
{
    int index = 0;

    while (stack)
    {
        if (stack->num == value)
            return index;
        stack = stack->next;
        index++;
    }
    return -1; // Si l'élément n'est pas trouvé
}

