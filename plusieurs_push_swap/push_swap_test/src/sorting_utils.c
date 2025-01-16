/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qacjl <qacjl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 14:41:16 by qacjl             #+#    #+#             */
/*   Updated: 2025/01/16 16:28:25 by qacjl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include "push_swap.h"

// Tri principal
void	sort_stack(t_list **stack_a)
{
	t_list	*stack_b;
	int		i;

	stack_b = NULL;
	if (ft_lstsize(*stack_a) == 2)
		ft_sa(stack_a, 0);
	else if (ft_lstsize(*stack_a) == 3)
		ft_sort_three(stack_a);
	else
	{
		stack_b = ft_fill_stack_b(stack_a);
		stack_a = ft_refill_a(stack_a, &stack_b);
		i = ft_find_index(*stack_a, ft_stackmin(*stack_a));
		if (i < ft_lstsize(*stack_a) - i)
		{
			while ((*stack_a)->num != ft_stackmin(*stack_a))
				ft_ra(stack_a, 0);
		}
		else
		{
			while ((*stack_a)->num != ft_stackmin(*stack_a))
				ft_rra(stack_a, 0);
		}
	}
}

// Remplit stack_b avec les éléments inutiles
t_list	*ft_fill_stack_b(t_list **stack_a)
{
	t_list	*stack_b;

	stack_b = NULL;
	if (ft_lstsize(*stack_a) > 3 && !ft_is_sorted(*stack_a))
		ft_pb(stack_a, &stack_b, 0);
	if (ft_lstsize(*stack_a) > 3 && !ft_is_sorted(*stack_a))
		ft_pb(stack_a, &stack_b, 0);
	if (ft_lstsize(*stack_a) > 3 && !ft_is_sorted(*stack_a))
		ft_fill_and_sort_b_to_3(stack_a, &stack_b);
	if (!ft_is_sorted(*stack_a))
		ft_sort_three(stack_a);
	return (stack_b);
}

// Gère le tri et le déplacement des éléments de stack_a vers stack_b
void	ft_fill_and_sort_b_to_3(t_list **stack_a, t_list **stack_b)
{
	int		i;
	t_list	*tmp;

	while (ft_lstsize(*stack_a) > 3 && !ft_is_sorted(*stack_a))
	{
		tmp = *stack_a;
		i = ft_rotation_a_to_b(*stack_a, *stack_b);
		while (i >= 0)
		{
			if (i == ft_test_rarb(*stack_a, *stack_b, tmp->num, 'b'))
				i = ft_do_rarb(stack_a, stack_b, tmp->num, 'a');
			else if (i == ft_test_rrarrb(*stack_a, *stack_b, tmp->num, 'b'))
				i = ft_do_rrarrb(stack_a, stack_b, tmp->num, 'a');
			else if (i == ft_test_rarrb(*stack_a, *stack_b, tmp->num, 'b'))
				i = ft_do_rarrb(stack_a, stack_b, tmp->num, 'a');
			else if (i == ft_test_rrarb(*stack_a, *stack_b, tmp->num, 'b'))
				i = ft_do_rrarb(stack_a, stack_b, tmp->num, 'a');
			else
				tmp = tmp->next;
		}
	}
}

// Réinsère les éléments triés de stack_b dans stack_a
t_list	**ft_refill_a(t_list **stack_a, t_list **stack_b)
{
	int		i;
	t_list	*tmp;

	while (*stack_b)
	{
		tmp = *stack_b;
		i = ft_rotation_b_to_a(*stack_a, *stack_b);
		while (i >= 0)
		{
			if (i == ft_test_rarb(*stack_a, *stack_b, tmp->num, 'a'))
				i = ft_do_rarb(stack_a, stack_b, tmp->num, 'b');
			else if (i == ft_test_rarrb(*stack_a, *stack_b, tmp->num, 'a'))
				i = ft_do_rarrb(stack_a, stack_b, tmp->num, 'b');
			else if (i == ft_test_rrarrb(*stack_a, *stack_b, tmp->num, 'a'))
				i = ft_do_rrarrb(stack_a, stack_b, tmp->num, 'b');
			else if (i == ft_test_rrarb(*stack_a, *stack_b, tmp->num, 'a'))
				i = ft_do_rrarb(stack_a, stack_b, tmp->num, 'b');
			else
				tmp = tmp->next;
		}
	}
	return (stack_a);
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
