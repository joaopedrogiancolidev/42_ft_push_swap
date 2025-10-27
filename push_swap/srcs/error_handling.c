/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiancol <jgiancol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 15:11:38 by jgiancol          #+#    #+#             */
/*   Updated: 2025/10/24 22:55:03 by jgiancol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	check_duplicates(t_stack_node *a)
{
	t_stack_node	*current;
	t_stack_node	*runner;

	current = a;
	while (current)
	{
		runner = current->next;
		while (runner)
		{
			if (current->value == runner->value)
				error_exit(&a, NULL);
			runner = runner->next;
		}
		current = current->next;
	}
}

void	error_exit(t_stack_node **a, t_stack_node **b)
{
	if (a)
		free_stack(a);
	if (b)
		free_stack(b);
	write(2, "Error\n", 6);
	exit(1);
}

void	free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}
