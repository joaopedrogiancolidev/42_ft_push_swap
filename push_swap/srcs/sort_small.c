/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiancol <jgiancol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 14:40:31 by jgiancol          #+#    #+#             */
/*   Updated: 2025/09/25 17:37:31 by jgiancol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"


static void		move_min_to_top(t_stack_node **a)
{
	t_stack_node	*min;
	int				size;
	int				position;
	int				i;

	min = find_min_node(*a);
	position = find_node_position(*a, min);
	size = stack_size(*a);
	i = 0;
	if (position <= size / 2)
	{
		i = 0;
		while (i < position)
		{
			ra(a, true);
			i++;
		}
	}
	else
	{
		i = size - position;
		while (i > 0)
		{
			rra(a, true);
			i--;
		}
	}
}

void	sort_small(t_stack_node **a, t_stack_node **b)
{
	int		size;

	size = stack_size(*a);
	if (size == 2)
	{
		if ((*a)->value > (*a)->next->value)
			sa(a, true);
		return ;
	}
	
	while (stack_size(*a) > 3)
	{
		move_min_to_top(a);
		pb(a, b, true);
	}
	
	// ⚠️ CORREÇÃO: Só chamar sort_three se tiver exatamente 3 elementos
	if (stack_size(*a) == 3)
		sort_three(a);
	
	while (*b)
		pa(a, b, true);
}

void	sort_any_size(t_stack_node **a, t_stack_node **b)
{
	while (!is_sorted(*a))
	{
		if (stack_size(*a) == 2)
			sa(a, true);
		else if (stack_size(*a) == 3)
			sort_three(a);
		else
		{
			move_min_to_top(a);
			pb(a, b, true);
		}
	}
	while (*b)
		pa(a, b, true);
}

// move min to top
// t_stack_node	*min;
// int				size;
// int				position;
// int				i;

// min = find_min_node(*a);
// position = find_node_position(*a, min);
// size = stack_size(*a);
// i = 0;
// while(*a && (*a)->value != min->value)
// {
// 	*a = (*a)->next;
// 	position++;
// }
// if (position <= size / 2)
// {
// 	while ((*a)->value != min->value)
// 		rra(a, true);
// }