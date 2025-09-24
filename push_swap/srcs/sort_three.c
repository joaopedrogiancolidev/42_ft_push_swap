/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiancol <jgiancol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 15:12:14 by jgiancol          #+#    #+#             */
/*   Updated: 2025/09/24 16:39:44 by jgiancol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_three(t_stack_node **a)
{
	t_stack_node	*biggest;

	if (!a || !*a)
		return;
		
	biggest = find_max_node(*a);
	
	// Se o maior está no topo, rotaciona
	if (biggest == *a)
		ra(a, true);
	// Se o maior está no meio, reverse rotate
	else if ((*a)->next == biggest)
		rra(a, true);
	
	// Se os dois primeiros estão fora de ordem, swap
	if ((*a)->value > (*a)->next->value)
		sa(a, true);
}
