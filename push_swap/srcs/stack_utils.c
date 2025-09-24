/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiancol <jgiancol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 22:22:48 by jgiancol          #+#    #+#             */
/*   Updated: 2025/09/24 16:58:23 by jgiancol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int     stack_size(t_stack_node *stack)
{
    int size;

    size = 0;
    while (stack)
    {
        size++;
        stack = stack->next;
    }
    return (size);
}

bool    is_sorted(t_stack_node *stack)
{
    if (!stack)
        return (true);
    while (stack->next)
    {
        if (stack->value > stack->next->value)
            return (false);
        stack = stack->next;
    }
    return (true);
}

// CORREÇÃO DA FUNÇÃO find_last_node
t_stack_node    *find_last_node(t_stack_node *stack)
{
    if (!stack)
        return (NULL);
    while (stack->next)
        stack = stack->next;
    return (stack);
}

t_stack_node    *find_max_node(t_stack_node *stack)
{
    t_stack_node    *max;
    int             max_value;

    if (!stack)
        return (NULL);
    max = stack;
    max_value = stack->value;
    while (stack)
    {
        if (stack->value > max_value)
        {
            max_value = stack->value;
            max = stack;
        }
        stack = stack->next;
    }
    return (max);
}

t_stack_node    *find_min_node(t_stack_node *stack)
{
    t_stack_node    *min;
    int             min_value;

    if (!stack)
        return (NULL);
    min = stack;
    min_value = stack->value;
    while (stack)
    {
        if (stack->value < min_value)
        {
            min_value = stack->value;
            min = stack;
        }
        stack = stack->next;
    }
    return (min);
}

int    find_node_position(t_stack_node *stack, t_stack_node *target)
{
    int    position;

    if (!stack || !target)
        return (-1);
    
    position = 0;
    while (stack)
    {
        if (stack == target)
            return (position);
        position++;
        stack = stack->next;
    }
    return (-1);
}
