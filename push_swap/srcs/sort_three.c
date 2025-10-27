/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiancol <jgiancol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 15:12:14 by jgiancol          #+#    #+#             */
/*   Updated: 2025/10/25 00:01:47 by jgiancol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_three(t_stack_node **a)
{
	t_stack_node	*biggest;

	if (!a || !*a || stack_size(*a) != 3)
		return ;
	biggest = find_max_node(*a);
	if (biggest == *a)
		ra(a, true);
	else if ((*a)->next == biggest)
		rra(a, true);
	if ((*a)->value > (*a)->next->value)
		sa(a, true);
}
