/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qacjl <qacjl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 14:40:57 by qacjl             #+#    #+#             */
/*   Updated: 2025/01/16 19:11:31 by qacjl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_list **stack_a, int silent)
{
	t_list	*tmp;
	t_list	*last;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	tmp = *stack_a;
	*stack_a = (*stack_a)->next;
	tmp->next = NULL;
	last = ft_lstlast(*stack_a);
	last->next = tmp;
	if (!silent)
		write(1, "ra\n", 3);
}

void	reverse_rotate_a(t_list **stack_a, int silent)
{
	t_list	*tmp;
	t_list	*before_last;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	before_last = *stack_a;
	while (before_last->next->next)
		before_last = before_last->next;
	tmp = before_last->next;
	before_last->next = NULL;
	tmp->next = *stack_a;
	*stack_a = tmp;
	if (!silent)
		write(1, "rra\n", 4);
}

void ft_rotate_to_insert(t_list **stack_a, int num_to_insert) {
    int index = ft_find_place_a(*stack_a, num_to_insert);
    int size = ft_lstsize(*stack_a);

    if (index < size - index) {
        while (index-- > 0)
            ft_ra(stack_a, 0);
    } else {
        while (index++ < size)
            ft_rra(stack_a, 0);
    }
}

void ft_handle_special_cases(t_list **stack_a) {
    int min = ft_stackmin(*stack_a);
    int min_index = find_index(*stack_a, min);

    if (min_index == ft_lstsize(*stack_a) - 1) {
        // Le plus petit élément est en bas, remontez-le en tête.
        ft_ra(stack_a, 0);
    } else if ((*stack_a)->num != min) {
        // Alignez le minimum en tête.
        ft_rotate_to_insert(stack_a, min);
    }
}

void	app_rot(t_list **stack_a, t_list **stack_b, int elmt_a, int elmt_b) {
    int cost_a = find_index(*stack_a, elmt_a);
    int cost_b = find_index(*stack_b, elmt_b);

    while (cost_a > 0 && cost_b > 0) {
        ft_rr(stack_a, stack_b, 0);
        cost_a--;
        cost_b--;
    }

    while (cost_a-- > 0)
        ft_ra(stack_a, 0);

    while (cost_b-- > 0)
        ft_rb(stack_b, 0);
}
