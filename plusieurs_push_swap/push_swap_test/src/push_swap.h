/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qacjl <qacjl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 16:11:00 by qacjl             #+#    #+#             */
/*   Updated: 2025/01/16 16:32:58 by qacjl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_list
{
	long			num;
	long			index;
	struct s_list	*next;
}	t_list;

// lst_management
void	ft_add_num_to_list(t_list **stack_a, t_list *new);
t_list	*ft_lstnew(long num);
t_list	*ft_lstlast(t_list *stack_a);
int		ft_stackmin(t_list *stack_a);
int		ft_lstsize(t_list *stack);

// lst_management_2
int		ft_stackmax(t_list *stack_a);
int		ft_find_index(t_list *stack_a, int nbr);
int		ft_find_place_b(t_list *stack_b, int num_pushed);
int		ft_find_place_a(t_list *stack_a, int num_pushed);

// ft_atoi_split
int		ft_atoi_split(const char *str, char **tab, t_list **stack_a);
int		ft_error_atoi_split(char **tab, t_list **stack_a);

// ft_check_args
t_list	*ft_str_args(char **argv);
t_list	*ft_check_args(int argc, char **argv);

// check_args_helpers
int		ft_atoi(const char *str, t_list **stack_a);
void	ft_free_str_in_tab(char **tab);
void	ft_error(void);
int		ft_isdigit(int c);
int		ft_error_atoi(t_list **stack_a);

// ft_split
char	**ft_split(char const *s, char c);
char	*ft_strcpy(char const *s, int start, int end);
int		ft_count_word(char const *string, char c);

// ft_duplicate
int		ft_duplicate(t_list *stack_a);

// ft_free_list
void	ft_free_list(t_list **stack);

// ft_is_sorted
int		ft_is_sorted(t_list *stack_a);

// operations
void	ft_sa(t_list **stack_a, int j);
void	ft_sb(t_list **stack_b, int j);
void	ft_ss(t_list **stack_a, t_list **stack_b, int j);
void	ft_pa(t_list **stack_a, t_list **stack_b, int j);
void	ft_pb(t_list **stack_a, t_list **stack_b, int j);
void	ft_ra(t_list **stack_a, int j);
void	ft_rb(t_list **stack_b, int j);
void	ft_rr(t_list **stack_a, t_list **stack_b, int j);
void	ft_rra(t_list **stack_a, int j);
void	ft_rrb(t_list **stack_b, int j);
void	ft_rrr(t_list **stack_a, t_list **stack_b, int j);

// Sorting and movement
void	sort_stack(t_list **stack_a);
t_list	*ft_fill_stack_b(t_list **stack_a);
void	ft_fill_and_sort_b_to_3(t_list **stack_a, t_list **stack_b);
t_list	**ft_refill_a(t_list **stack_a, t_list **stack_b);
int		ft_rotation_a_to_b(t_list *stack_a, t_list *stack_b);
int		ft_rotation_b_to_a(t_list *stack_a, t_list *stack_b);
int		ft_test_rarb(t_list *stack_a, t_list *stack_b, int c, char s);
int		ft_test_rrarrb(t_list *stack_a, t_list *stack_b, int c, char s);
int		ft_test_rrarb(t_list *stack_a, t_list *stack_b, int c, char s);
int		ft_test_rarrb(t_list *stack_a, t_list *stack_b, int c, char s);
void	ft_sort_three(t_list **stack_a);

// Prototypes pour les fonctions ft_do_* (si absents)
int		ft_do_rarb(t_list **stack_a, t_list **stack_b, int c, char s);
int		ft_do_rrarrb(t_list **stack_a, t_list **stack_b, int c, char s);
int		ft_do_rarrb(t_list **stack_a, t_list **stack_b, int c, char s);
int		ft_do_rrarb(t_list **stack_a, t_list **stack_b, int c, char s);

// args_utils helpers
char	**split_string(const char *str, char delimiter);
int		parse_number_split(const char *str, char **split, t_list **stack);
int		parse_number(const char *str, t_list **stack);
void	add_to_list(t_list **stack, t_list *new_node);
t_list	*create_node(long num);
void	free_split(char **split);
void	print_error(void);
void	free_all(char **split, t_list **stack);
void	free_list(t_list **stack);

#endif
