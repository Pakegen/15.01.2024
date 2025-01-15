/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quenalla <quenalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 18:54:56 by qacjl             #+#    #+#             */
/*   Updated: 2025/01/15 11:21:24 by quenalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	if (ac < 2)
		return (write(2, "PAS ASSEZ D'ARGUMENT\n", 22), 1);
	a = init_stack(ac - 1);
	b = init_stack(ac - 1);
	if (!ft_parse_argument(a, ac, av))
	{
		write(2, "ERROR\n", 7);
		free_stack(a);
		free_stack(b);
		return (1);
	}
	if (a->top > 0)
		ft_execute_sorting(a, b);
	free_stack(a);
	free_stack(b);
	return (0);
}
