/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiancol <jgiancol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 23:16:39 by jgiancol          #+#    #+#             */
/*   Updated: 2025/10/24 23:40:53 by jgiancol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	assign_indices(t_stack_node *stack)
{
	t_stack_node	*current;
	t_stack_node	*compare;
	int				index;

	current = stack;
	while (current)
	{
		index = 0;
		compare = stack;
		while (compare)
		{
			if (compare->value < current->value)
				index++;
			compare = compare->next;
		}
		current->index = index;
		current = current->next;
	}
}

static int	find_closest_bigger(t_stack_node *a, int b_index, int *found)
{
	t_stack_node	*current;
	int				position;
	t_closest		closest;

	current = a;
	position = 0;
	closest.value = INT_MAX;
	closest.pos = 0;
	*found = 0;
	while (current)
	{
		if (current->index > b_index && current->index < closest.value)
		{
			closest.value = current->index;
			closest.pos = position;
			*found = 1;
		}
		position++;
		current = current->next;
	}
	return (closest.pos);
}

int	find_target_position(t_stack_node *a, int b_index)
{
	t_stack_node	*min_node;
	int				target_pos;
	int				found;

	target_pos = find_closest_bigger(a, b_index, &found);
	if (!found)
	{
		min_node = find_min_node(a);
		target_pos = find_node_position(a, min_node);
	}
	return (target_pos);
}

static t_stack_node	*get_b_node_at_pos(t_stack_node *b, int pos)
{
	int	i;

	i = 0;
	while (i < pos)
	{
		b = b->next;
		i++;
	}
	return (b);
}

int	calculate_move_cost(t_stack_node *a, t_stack_node *b, int b_pos)
{
	int				sizes[2];
	t_stack_node	*b_node;
	int				costs[2];
	int				target_pos;

	sizes[0] = stack_size(a);
	sizes[1] = stack_size(b);
	b_node = get_b_node_at_pos(b, b_pos);
	target_pos = find_target_position(a, b_node->index);
	if (b_pos <= sizes[1] / 2)
		costs[1] = b_pos;
	else
		costs[1] = sizes[1] - b_pos;
	if (target_pos <= sizes[0] / 2)
		costs[0] = target_pos;
	else
		costs[0] = sizes[0] - target_pos;
	return (costs[0] + costs[1]);
}
