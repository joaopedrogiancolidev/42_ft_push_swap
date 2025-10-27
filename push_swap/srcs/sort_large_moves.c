/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large_moves.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiancol <jgiancol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 23:17:32 by jgiancol          #+#    #+#             */
/*   Updated: 2025/10/25 00:00:56 by jgiancol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_range_to_b(t_stack_node **a, t_stack_node **b, t_range range)
{
	int	size;
	int	rotations;
	int	mid;

	size = stack_size(*a);
	rotations = 0;
	mid = range.max - (range.max - range.min) / 2;
	while (size > 3)
	{
		if ((*a)->index >= range.min && (*a)->index <= range.max)
		{
			pb(a, b, true);
			size--;
			if (*b && (*b)->next && (*b)->index < mid)
				rb(b, true);
		}
		else if (rotations < size)
		{
			ra(a, true);
			rotations++;
		}
		else
			break ;
	}
}

int	find_cheapest_move(t_stack_node *a, t_stack_node *b)
{
	int	b_size;
	int	cheapest_pos;
	int	min_cost;
	int	cost;
	int	i;

	b_size = stack_size(b);
	cheapest_pos = 0;
	min_cost = INT_MAX;
	i = 0;
	while (i < b_size)
	{
		cost = calculate_move_cost(a, b, i);
		if (cost < min_cost)
		{
			min_cost = cost;
			cheapest_pos = i;
		}
		i++;
	}
	return (cheapest_pos);
}

void	execute_cheapest_move(t_stack_node **a, t_stack_node **b, int b_pos)
{
	int				sizes[2];
	t_stack_node	*b_node;
	int				target_pos;
	int				i;

	sizes[0] = stack_size(*a);
	sizes[1] = stack_size(*b);
	b_node = *b;
	i = 0;
	while (i < b_pos)
	{
		b_node = b_node->next;
		i++;
	}
	target_pos = find_target_position(*a, b_node->index);
	rotate_b_to_top(b, b_pos, sizes[1]);
	rotate_a_to_target(a, target_pos, sizes[0]);
	pa(a, b, true);
}
