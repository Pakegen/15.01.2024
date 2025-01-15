/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qacjl <qacjl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 17:37:50 by qacjl             #+#    #+#             */
/*   Updated: 2024/12/23 19:34:14 by qacjl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_number(char *str)
{
	if (!str || *str == '\0')
		return (0);
	if (*str == '-' || *str == '+')
		str++;
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
}

int	ft_duplicate(t_stack *stack)
{
	int	i;
	int	k;

	i = 0;
	while (i <= stack->top)
	{
		k = i + 1;
		while (k <= stack->top)
		{
			if (stack->data[i] == stack->data[k])
				return (1);
			k++;
		}
		i++;
	}
	return (0);
}

int	ft_parse_argument(t_stack *a, int ac, char **av)
{
	long	value;
	int		i;

	i = 1;
	while (i < ac)
	{
		if (!ft_number(av[i]))
			return (0);
		value = ft_atol(av[i]);
		if (value < INT_MIN || value > INT_MAX)
			return (0);
		push(a, (int)value);
		i++;
	}
	if (ft_duplicate(a))
		return (0);
	return (1);
}
