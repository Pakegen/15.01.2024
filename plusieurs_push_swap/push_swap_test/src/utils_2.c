/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qacjl <qacjl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 16:30:35 by qacjl             #+#    #+#             */
/*   Updated: 2025/01/16 16:34:15 by qacjl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**split_string(const char *str, char delimiter)
{
	int		i, j, start, count = 0;
	char	**result;

	// Compte le nombre de mots
	for (i = 0; str[i]; i++)
		if (str[i] != delimiter && (i == 0 || str[i - 1] == delimiter))
			count++;
	result = malloc((count + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	i = 0;
	start = -1;
	for (j = 0; str[j]; j++)
	{
		if (str[j] != delimiter && start == -1)
			start = j;
		else if ((str[j] == delimiter || str[j + 1] == '\0') && start != -1)
		{
			result[i++]
				= strndup(&str[start], j - start + (str[j + 1] == '\0'));
			start = -1;
		}
	}
	result[i] = NULL;
	return (result);
}

int	parse_number_split(const char *str, char **split, t_list **stack)
{
	long	num;
	int		sign;

	num = 0;
	sign = 1;
	if (*str == '-' || *str == '+')
		sign = (*str++ == '-') ? -1 : 1;
	while (*str)
	{
		if (*str < '0' || *str > '9')
			free_all(split, stack), print_error();
		num = num * 10 + (*str++ - '0');
		if ((num * sign) > INT_MAX || (num * sign) < INT_MIN)
			free_all(split, stack), print_error();
	}
	return (num * sign);
}

void	add_to_list(t_list **stack, t_list *new_node)
{
	if (!stack || !new_node)
		return ;
	if (!*stack)
		*stack = new_node;
	else
	{
		t_list *last = *stack;
		while (last->next)
			last = last->next;
		last->next = new_node;
	}
}

t_list	*create_node(long num)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		print_error();
	new_node->num = num;
	new_node->next = NULL;
	return (new_node);
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	if (!split)
		return ;
	while (split[i])
		free(split[i++]);
	free(split);
}
