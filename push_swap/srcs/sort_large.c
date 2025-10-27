/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiancol <jgiancol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 14:54:13 by jgiancol          #+#    #+#             */
/*   Updated: 2025/10/24 23:30:39 by jgiancol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	get_chunk_size(int size)
{
	if (size <= 100)
		return (size / 5);
	else
		return (size / 2);
}

static void	push_chunks(t_stack_node **a, t_stack_node **b, int size)
{
	int		i;
	int		chunk_size;
	t_range	range;

	chunk_size = get_chunk_size(size);
	i = 0;
	while (stack_size(*a) > 3)
	{
		range.min = i * chunk_size;
		range.max = (i + 1) * chunk_size - 1;
		if (range.max >= size - 3)
			range.max = size - 4;
		push_range_to_b(a, b, range);
		i++;
		if (stack_size(*a) <= 3)
			break ;
	}
}

static void	sort_remaining(t_stack_node **a)
{
	if (stack_size(*a) == 3)
		sort_three(a);
	else if (stack_size(*a) == 2 && (*a)->value > (*a)->next->value)
		sa(a, true);
}

void	sort_large(t_stack_node **a, t_stack_node **b)
{
	int	size;
	int	cheapest_pos;

	if (!a || !*a || is_sorted(*a))
		return ;
	size = stack_size(*a);
	assign_indices(*a);
	push_chunks(a, b, size);
	sort_remaining(a);
	while (*b)
	{
		cheapest_pos = find_cheapest_move(*a, *b);
		execute_cheapest_move(a, b, cheapest_pos);
	}
	if (!is_sorted(*a))
		final_rotation(a);
}
