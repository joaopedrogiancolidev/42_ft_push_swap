/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_structs.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiancol <jgiancol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 22:22:48 by jgiancol          #+#    #+#             */
/*   Updated: 2025/10/25 00:02:02 by jgiancol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack_node	*find_last_node(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

t_stack_node	*find_max_node(t_stack_node *stack)
{
	t_stack_node	*max;
	int				max_value;

	if (!stack)
		return (NULL);
	max = stack;
	max_value = stack->value;
	while (stack)
	{
		if (stack->value > max_value)
		{
			max_value = stack->value;
			max = stack;
		}
		stack = stack->next;
	}
	return (max);
}

t_stack_node	*find_min_node(t_stack_node *stack)
{
	t_stack_node	*min;
	int				min_value;

	if (!stack)
		return (NULL);
	min = stack;
	min_value = stack->value;
	while (stack)
	{
		if (stack->value < min_value)
		{
			min_value = stack->value;
			min = stack;
		}
		stack = stack->next;
	}
	return (min);
}
