/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiancol <jgiancol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 23:19:26 by jgiancol          #+#    #+#             */
/*   Updated: 2025/10/25 00:01:06 by jgiancol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate_b_to_top(t_stack_node **b, int b_pos, int b_size)
{
	if (b_pos <= b_size / 2)
	{
		while (b_pos-- > 0)
			rb(b, true);
	}
	else
	{
		while (b_pos++ < b_size)
			rrb(b, true);
	}
}

void	rotate_a_to_target(t_stack_node **a, int target, int a_size)
{
	if (target <= a_size / 2)
	{
		while (target-- > 0)
			ra(a, true);
	}
	else
	{
		while (target++ < a_size)
			rra(a, true);
	}
}

void	final_rotation(t_stack_node **a)
{
	t_stack_node	*min_node;
	int				min_pos;
	int				size;

	min_node = find_min_node(*a);
	min_pos = find_node_position(*a, min_node);
	size = stack_size(*a);
	if (min_pos <= size / 2)
	{
		while (min_pos-- > 0)
			ra(a, true);
	}
	else
	{
		while (min_pos++ < size)
			rra(a, true);
	}
}
