/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qacjl <qacjl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 17:57:54 by qacjl             #+#    #+#             */
/*   Updated: 2024/12/23 18:32:48 by qacjl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "../utils/libft/libft.h"
#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>

#define INT_MIN -2147483648
#define INT_MAX 2147483647

typedef struct s_stack
{
	int	*data;
	int	top;
	int	capacity;
} t_stack;

t_stack	*init_stack(int capacity);

int		ft_parse_argument(t_stack *a, int ac, char **av);

int		ft_duplicate(t_stack *stack);

int		ft_number(char *str);

int		ft_find_pivot(t_stack *a, int start, int end);

int		pop(t_stack *stack);

void	free_stack(t_stack *stack);

void	ft_execute_sorting(t_stack *a, t_stack *b);

void	ft_sort_stack(t_stack *a, t_stack *b);

void	sa(t_stack *a);

void	sb(t_stack *b);

void	ss(t_stack *a, t_stack *b);

void	pa(t_stack *a, t_stack *b);

void	pb(t_stack *a, t_stack *b);

void	ra(t_stack *a);

void	rb(t_stack *b);

void	rr(t_stack *a, t_stack *b);

void	rra(t_stack *a);

void	rrb(t_stack *b);

void	rrr(t_stack *a, t_stack *b);

void	push(t_stack *stack, int value);

void	swap(t_stack *stack);

void	rotate(t_stack *stack);

void	reverse_rotate(t_stack *stack);

#endif
