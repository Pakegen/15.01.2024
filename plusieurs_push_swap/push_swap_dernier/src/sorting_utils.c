/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qacjl <qacjl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 14:41:16 by qacjl             #+#    #+#             */
/*   Updated: 2025/01/16 19:25:00 by qacjl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort(t_list **stack_a)
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

void	ft_sort_three(t_list **stack_a)
{
	if (ft_stackmin(*stack_a) == (*stack_a)->num)
	{
		ft_rra(stack_a, 0);
		ft_sa(stack_a, 0);
	}
	else if (ft_stackmax(*stack_a) == (*stack_a)->num)
	{
		ft_ra(stack_a, 0);
		if (!ft_is_sorted(*stack_a))
			ft_sa(stack_a, 0);
	}
	else
	{
		if (ft_find_index(*stack_a, ft_stackmax(*stack_a)) == 1)
			ft_rra(stack_a, 0);
		else
			ft_sa(stack_a, 0);
	}
}

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

int	find_index(t_list *stack, int value)
{
	int	index;

	index = 0;
	while (stack)
	{
		if (stack->num == value)
			return (index);
		stack = stack->next;
		index++;
	}
	return (-1);
}
