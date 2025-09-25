/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiancol <jgiancol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 22:54:12 by jgiancol          #+#    #+#             */
/*   Updated: 2025/09/25 16:15:28 by jgiancol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void     append_node(t_stack_node **stack, int n)
{
    t_stack_node    *node;
    t_stack_node    *last_node;

    if (!stack)
        return;
        
    node = malloc(sizeof(t_stack_node));
    if (!node)
        error_exit(stack, NULL);
        
    node->value = n;
    node->next = NULL;
    
    if (!(*stack))
    {
        node->prev = NULL;
        *stack = node;
    }
    else
    {
        last_node = find_last_node(*stack);
        last_node->next = node;
        node->prev = last_node;
    }
}

// int     ft_atoi(const char *str)
// {
//     long    num;
//     int     sign;
//     int     i;

//     num = 0;
//     sign = 1;
//     i = 0;
    
//     while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
//         i++;
        
//     if (str[i] == '-')
//         sign = -1;
        
//     if (str[i] == '-' || str[i] == '+')
//         i++;
        
//     while (str[i] >= '0' && str[i] <= '9')
//     {
//         num = num * 10 + (str[i] - '0');
//         i++;
//         if (num > INT_MAX || (sign == -1 && num > (long)INT_MAX + 1))
//             return (2147483648);
//     }
    
//     return (num * sign);
// }

void    init_stack_a(t_stack_node **a, char **argv)
{
    long    value;
    int     i;

    i = 0;
    while (argv[i])
    {
        value = ft_atoi(argv[i]);
        if (value > INT_MAX || value < INT_MIN)
            error_exit(a, NULL);
            
        append_node(a, (int)value);
        i++;
    }
}