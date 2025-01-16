/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qacjl <qacjl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 14:43:12 by qacjl             #+#    #+#             */
/*   Updated: 2025/01/16 19:17:06 by qacjl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	long			num;
	struct s_list	*next;
}	t_list;

// args_utils.c
t_list	*parse_args(char **argv);
t_list	*check_args(int argc, char **argv);

// errors_utils.c
void	print_error(void);
void	free_list(t_list **stack);
void	free_split(char **split);
void	free_all(char **split, t_list **stack);

// list_utils.c
t_list	*create_node(long number);
void	add_to_list(t_list **stack, t_list *new_node);
int		find_min(t_list *stack);
int		find_max(t_list *stack);
int		list_size(t_list *stack);

// operations_basic.c
void	swap_a(t_list **stack_a, int silent);
void	swap_b(t_list **stack_b, int silent);
void	swap_both(t_list **stack_a, t_list **stack_b, int silent);
void	push_a(t_list **stack_a, t_list **stack_b, int silent);
void	push_b(t_list **stack_a, t_list **stack_b, int silent);

// operations_rotations.c
void	rotate_a(t_list **stack_a, int silent);
void	reverse_rotate_a(t_list **stack_a, int silent);

// sorting_utils.c
void	sort_stack(t_list **stack_a);
// utils.c
char	**split_string(const char *str, char delimiter);

// args_utils.c
int		parse_number_split(const char *str, char **split, t_list **stack);
int		parse_number(const char *str, t_list **stack);
t_list	*ft_lstlast(t_list *stack);

// sorting_utils.c
void	sort_three(t_list **stack);
t_list	*move_to_stack_b(t_list **stack_a);
t_list	**move_back_to_stack_a(t_list **stack_a, t_list **stack_b);
int		find_index(t_list *stack, int value);
char	*ft_strndup(const char *src, size_t n);
// list_utils.c
int		check_duplicates(t_list *stack);
int		is_sorted(t_list *stack);
void	ft_rotate_to_insert(t_list **stack_a, int num_to_insert);
void	ft_handle_special_cases(t_list **stack_a);
void	app_rot(t_list **stack_a, t_list **stack_b, int elemt_a, int elmt_b);
void	sort_without_max(t_list **stack_a);
t_list *move_to_stack_b_for_max(t_list **stack_a);
void	place_max(t_list **stack_a);
// operations_helpers.c
int ft_find_place_a(t_list *stack, int num);
int ft_lstsize(t_list *stack);
void ft_ra(t_list **stack_a, int silent);
void ft_rra(t_list **stack_a, int silent);
int ft_stackmin(t_list *stack);
void ft_rr(t_list **stack_a, t_list **stack_b, int silent);
void ft_rb(t_list **stack_b, int silent);

#endif
