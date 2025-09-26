/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiancol <jgiancol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 23:19:32 by jgiancol          #+#    #+#             */
/*   Updated: 2025/09/25 21:13:10 by jgiancol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/push_swap.h"

void    free_stack(t_stack_node **stack)
{
    t_stack_node    *current;
    t_stack_node    *next;

    if (!stack)
        return;
        
    current = *stack;
    while (current)
    {
        next = current->next;
        free(current);
        current = next;
    }
    *stack = NULL;
}

void debug_stack(t_stack_node *stack, const char *name)
{
    ft_printf("%s: ", name);
    while (stack)
    {
        ft_printf("%d ", stack->value);
        stack = stack->next;
    }
    ft_printf("\n");
}

int     main(int argc, char **argv)
{
    t_stack_node    *a;
    t_stack_node    *b;
    char            **args;

    a = NULL;
    b = NULL;
    
    //debug_stack(a, "Antes da ordenação");
    if (argc == 1)
    {
        write(2, "Error\n", 6);
        return (0);
    }
    if (argc == 2)
    {
        args = ft_split(argv[1], ' ');
        if (!args || !args[0])
        {
            write(2, "Error\n", 6);
            if (args) free_split(args);
            return (1);
        }

                int valid_count = 0;
        for (int i = 0; args[i]; i++)
        {
            if (is_valid_number(args[i]))
                valid_count++;
        }
        
        // if (valid_count == 0)
        // {
        //     write(2, "Error\n", 6);
        //     free_split(args);
        //     return (1);
        // }
        
        if (!validate_arguments(args) || has_duplicates(args))
        {
            free_split(args);
            return (1);
        }
        init_stack_a(&a, args);
        free_split(args);
    }
    else
    {
        if (!validate_arguments(argv + 1) || has_duplicates(argv + 1))
            return (1);
        init_stack_a(&a, argv + 1);
    }
    
    check_duplicates(a);
    
    if (!is_sorted(a))
    {
        if (stack_size(a) == 2)
            sa(&a, true);
        else if (stack_size(a) == 3)
            sort_three(&a);
        else if (stack_size(a) <= 5)
            sort_small(&a, &b);
        else
            sort_large(&a, &b);
    }
    //debug_stack(a, "Depois da ordenação");
    free_stack(&a);
    return (0);
}

// int		main(int argc, char **argv)
// {
// 	t_stack_node	*a;
// 	t_stack_node	*b;

// 	a = NULL;
// 	b = NULL;
// 	if (argc == 1)
// 		return (0);
// 	init_stack_a(&a, argv + 1);
// 	if (!is_sorted(a))
// 	{
// 		if(stack_size(a) <= 3)
// 			sort_small(&a, &b);
// 		else if (stack_size(a) <= 5)
// 			sort_small(&a, &b);
// 		else
// 			sort_large(&a, &b);
// 	}
// 	free_stack(&a);
// 	return (0);
// }
