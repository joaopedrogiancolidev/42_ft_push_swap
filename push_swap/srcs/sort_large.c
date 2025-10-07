/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiancol <jgiancol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 14:54:13 by jgiancol          #+#    #+#             */
/*   Updated: 2025/10/07 17:31:33 by jgiancol         ###   ########.fr       */
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

static void	push_range_to_b(t_stack_node **a,
	t_stack_node **b, int min_index, int max_index)
{
	int	size;
	int	rotations;

	size = stack_size(*a);
	rotations = 0;
	while (size > 3)
	{
		if ((*a)->index >= min_index && (*a)->index <= max_index)
		{
			pb(a, b, true);
			size--;
			if (*b && (*b)->next
				&& (*b)->index < max_index - (max_index - min_index) / 2)
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

static void	assign_indices(t_stack_node *stack)
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

static int	find_target_position(t_stack_node *a, int b_index)
{
	t_stack_node	*current;
	t_stack_node	*min_node;
	int				position;
	int				target_pos;
	int				closest_bigger;
	int				closest_pos;

	current = a;
	position = 0;
	target_pos = 0;
	closest_bigger = INT_MAX;
	closest_pos = 0;
	while (current)
	{
		if (current->index > b_index && current->index < closest_bigger)
		{
			closest_bigger = current->index;
			closest_pos = position;
		}
		position++;
		current = current->next;
	}
	if (closest_bigger == INT_MAX)
	{
		min_node = find_min_node(a);
		target_pos = find_node_position(a, min_node);
	}
	else
	{
		target_pos = closest_pos;
	}
	return (target_pos);
}

static int	calculate_move_cost(t_stack_node *a, t_stack_node *b, int b_pos)
{
	int				a_size;
	int				b_size;
	t_stack_node	*b_node;
	int				i;
	int				target_pos;
	int				b_cost;
	int				a_cost;

	a_size = stack_size(a);
	b_size = stack_size(b);
	b_node = b;
	i = 0;
	while (i < b_pos)
	{
		b_node = b_node->next;
		i++;
	}
	target_pos = find_target_position(a, b_node->index);
	if (b_pos <= b_size / 2)
		b_cost = b_pos;
	else
		b_cost = b_size - b_pos;
	if (target_pos <= a_size / 2)
		a_cost = target_pos;
	else
		a_cost = a_size - target_pos;
	return (a_cost + b_cost);
}

static int	find_cheapest_move(t_stack_node *a, t_stack_node *b)
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

static void	execute_cheapest_move(t_stack_node **a, t_stack_node **b, int b_pos)
{
	int				a_size;
	int				b_size;
	t_stack_node	*b_node;
	int				i;
	int				target_pos;

	a_size = stack_size(*a);
	b_size = stack_size(*b);
	b_node = *b;
	i = 0;
	while (i < b_pos)
	{
		b_node = b_node->next;
		i++;
	}
	target_pos = find_target_position(*a, b_node->index);
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
	if (target_pos <= a_size / 2)
	{
		while (target_pos-- > 0)
			ra(a, true);
	}
	else
	{
		while (target_pos++ < a_size)
			rra(a, true);
	}
	pa(a, b, true);
}

static void	final_rotation(t_stack_node **a)
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

void	sort_large(t_stack_node **a, t_stack_node **b)
{
	int	size;
	int	i;
	int	chunk_size;
	int	min_index;
	int	max_index;
	int	cheapest_pos;

	size = stack_size(*a);
	assign_indices(*a);
	chunk_size = get_chunk_size(size);
	i = 0;
	if (!a || !*a || is_sorted(*a))
		return ;
	while (stack_size(*a) > 3)
	{
		min_index = i * chunk_size;
		max_index = (i + 1) * chunk_size - 1;
		if (max_index >= size - 3)
			max_index = size - 4;
		push_range_to_b(a, b, min_index, max_index);
		i++;
		if (stack_size(*a) <= 3)
			break ;
	}
	if (stack_size(*a) == 3)
		sort_three(a);
	else if (stack_size(*a) == 2 && (*a)->value > (*a)->next->value)
		sa(a, true);
	while (*b)
	{
		cheapest_pos = find_cheapest_move(*a, *b);
		execute_cheapest_move(a, b, cheapest_pos);
	}
	if (!is_sorted(*a))
		final_rotation(a);
}
