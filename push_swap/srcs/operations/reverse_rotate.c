/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiancol <jgiancol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 16:15:04 by jgiancol          #+#    #+#             */
/*   Updated: 2025/09/24 16:23:25 by jgiancol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void     reverse_rotate(t_stack_node **stack)
{
    t_stack_node    *last;
    
    if (!*stack || !(*stack)->next)
        return;
        
    last = find_last_node(*stack);
    
    last->prev->next = NULL;
    last->next = *stack;
    last->prev = NULL;
    (*stack)->prev = last;
    *stack = last;
}

void    rra(t_stack_node **a, bool print)
{
    reverse_rotate(a);
    if (print)
        ft_printf("rra\n");
}

void    rrb(t_stack_node **b, bool print)
{
    reverse_rotate(b);
    if (print)
        ft_printf("rrb\n");
}

void    rrr(t_stack_node **a, t_stack_node **b, bool print)
{
    reverse_rotate(a);
    reverse_rotate(b);
    if (print)
        ft_printf("rrr\n");
}