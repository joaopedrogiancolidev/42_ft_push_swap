/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiancol <jgiancol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 14:54:13 by jgiancol          #+#    #+#             */
/*   Updated: 2025/09/24 18:20:35 by jgiancol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Implementação básica da mediana
#include "../includes/push_swap.h"

static int    find_median(t_stack_node *stack)
{
    int             size;
    int             *array;
    int             i;
    int             median;
    t_stack_node    *current;

    if (!stack)
        return (0);
    
    size = stack_size(stack);
    array = malloc(sizeof(int) * size);
    if (!array)
        return (0);
    
    current = stack;
    i = 0;
    while (current)
    {
        array[i++] = current->value;
        current = current->next;
    }
    
    for (i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
    
    median = array[size / 2];
    free(array);
    return (median);
}

static void    push_to_b_until_median(t_stack_node **a, t_stack_node **b, int median)
{
    int    size;
    int    i;
    int    pushed;

    if (!a || !*a)
        return;
    
    size = stack_size(*a);
    i = 0;
    pushed = 0;
    
    while (i < size && pushed < size / 2)
    {
        if ((*a)->value <= median)
        {
            pb(a, b, true);
            pushed++;
        }
        else
            ra(a, true);
        i++;
    }
}

// VERSÃO SIMPLES E FUNCIONAL - use chunks menores para 500 números
void    sort_large(t_stack_node **a, t_stack_node **b)
{
    int    median;
    int    size;

    if (!a || !*a || is_sorted(*a))
        return;
    
    size = stack_size(*a);
    
    // Estratégia: dividir em 2 partes para 100 números, 3 partes para 500
    int parts = (size <= 100) ? 2 : 3;
    
    for (int part = 0; part < parts && stack_size(*a) > 3; part++)
    {
        median = find_median(*a);
        push_to_b_until_median(a, b, median);
    }
    
    // Ordenar o que sobrou em A
    if (!is_sorted(*a))
        sort_small(a, b);
    
    // Trazer de volta de B de forma mais eficiente
    while (*b)
    {
        t_stack_node *max_b = find_max_node(*b);
        int pos = find_node_position(*b, max_b);
        int b_size = stack_size(*b);
        
        // Estratégia mais inteligente: escolher a direção com menos rotações
        if (pos <= b_size / 2)
        {
            for (int i = 0; i < pos; i++)
                rb(b, true);
        }
        else
        {
            for (int i = 0; i < b_size - pos; i++)
                rrb(b, true);
        }
        
        pa(a, b, true);
    }
    
    // Rotação final para deixar o menor no topo
    t_stack_node *min_a = find_min_node(*a);
    int pos = find_node_position(*a, min_a);
    int a_size = stack_size(*a);
    
    if (pos <= a_size / 2)
    {
        for (int i = 0; i < pos; i++)
            ra(a, true);
    }
    else
    {
        for (int i = 0; i < a_size - pos; i++)
            rra(a, true);
    }
}

// void	sort_large(t_stack_node **a, t_stack_node **b)
// {
// 	int median;

// 	median = find_median(*a);

// 	push_to_b_until_median(a, b , median);

// 	while (!is_sorted(*a))
// 		sort_small(a, b);
// 	while (!is_sorted(*b))
// 		sort_small(a, b);
// 	while (*b)
// 		pa(a, b , true);
// }