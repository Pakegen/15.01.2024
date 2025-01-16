/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qacjl <qacjl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 16:26:59 by qacjl             #+#    #+#             */
/*   Updated: 2025/01/16 16:27:12 by qacjl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_do_rarb(t_list **stack_a, t_list **stack_b, int c, char s)
{
	if (s == 'a')
	{
		while ((*stack_a)->num != c && ft_find_place_b(*stack_b, c) > 0)
			ft_rr(stack_a, stack_b, 0);
		while ((*stack_a)->num != c)
			ft_ra(stack_a, 0);
		while (ft_find_place_b(*stack_b, c) > 0)
			ft_rb(stack_b, 0);
		ft_pb(stack_a, stack_b, 0);
	}
	else
	{
		while ((*stack_b)->num != c && ft_find_place_a(*stack_a, c) > 0)
			ft_rr(stack_a, stack_b, 0);
		while ((*stack_b)->num != c)
			ft_rb(stack_b, 0);
		while (ft_find_place_a(*stack_a, c) > 0)
			ft_ra(stack_a, 0);
		ft_pa(stack_a, stack_b, 0);
	}
	return (-1);
}

int	ft_do_rrarrb(t_list **stack_a, t_list **stack_b, int c, char s)
{
	if (s == 'a')
	{
		while ((*stack_a)->num != c && ft_find_place_b(*stack_b, c) > 0)
			ft_rrr(stack_a, stack_b, 0);
		while ((*stack_a)->num != c)
			ft_rra(stack_a, 0);
		while (ft_find_place_b(*stack_b, c) > 0)
			ft_rrb(stack_b, 0);
		ft_pb(stack_a, stack_b, 0);
	}
	else
	{
		while ((*stack_b)->num != c && ft_find_place_a(*stack_a, c) > 0)
			ft_rrr(stack_a, stack_b, 0);
		while ((*stack_b)->num != c)
			ft_rrb(stack_b, 0);
		while (ft_find_place_a(*stack_a, c) > 0)
			ft_rra(stack_a, 0);
		ft_pa(stack_a, stack_b, 0);
	}
	return (-1);
}

int	ft_do_rarrb(t_list **stack_a, t_list **stack_b, int c, char s)
{
	if (s == 'a')
	{
		while ((*stack_a)->num != c)
			ft_ra(stack_a, 0);
		while (ft_find_place_b(*stack_b, c) > 0)
			ft_rrb(stack_b, 0);
		ft_pb(stack_a, stack_b, 0);
	}
	else
	{
		while (ft_find_place_a(*stack_a, c) > 0)
			ft_ra(stack_a, 0);
		while ((*stack_b)->num != c)
			ft_rrb(stack_b, 0);
		ft_pa(stack_a, stack_b, 0);
	}
	return (-1);
}

int	ft_do_rrarb(t_list **stack_a, t_list **stack_b, int c, char s)
{
	if (s == 'a')
	{
		while ((*stack_a)->num != c)
			ft_rra(stack_a, 0);
		while (ft_find_place_b(*stack_b, c) > 0)
			ft_rb(stack_b, 0);
		ft_pb(stack_a, stack_b, 0);
	}
	else
	{
		while (ft_find_place_a(*stack_a, c) > 0)
			ft_rra(stack_a, 0);
		while ((*stack_b)->num != c)
			ft_rb(stack_b, 0);
		ft_pa(stack_a, stack_b, 0);
	}
	return (-1);
}
