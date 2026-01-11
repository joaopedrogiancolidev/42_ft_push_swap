/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiancol <jgiancol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 14:40:31 by jgiancol          #+#    #+#             */
/*   Updated: 2025/10/31 19:47:36 by jgiancol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	rotate_min_forward(t_stack_node **a, int position)
{
	int	i;

	i = 0;
	while (i < position)
	{
		ra(a, true);
		i++;
	}
}

static void	rotate_min_backward(t_stack_node **a, int size, int position)
{
	int	i;

	i = size - position;
	while (i > 0)
	{
		rra(a, true);
		i--;
	}
}

static void	move_min_to_top(t_stack_node **a)
{
	t_stack_node	*min;
	int				size;
	int				position;

	min = find_min_node(*a);
	position = find_node_position(*a, min);
	size = stack_size(*a);
	if (position <= size / 2)
		rotate_min_forward(a, position);
	else
		rotate_min_backward(a, size, position);
}

void	sort_small(t_stack_node **a, t_stack_node **b)
{
	int	size;

	size = stack_size(*a);
	if (size == 2)
	{
		if ((*a)->value > (*a)->next->value)
			sa(a, true);
		return ;
	}
	if (size == 3)
	{
		sort_three(a);
		return ;
	}
	while (stack_size(*a) > 3)
	{
		move_min_to_top(a);
		pb(a, b, true);
	}
	sort_three(a);
	while (*b)
		pa(a, b, true);
}
