/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiancol <jgiancol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 14:54:13 by jgiancol          #+#    #+#             */
/*   Updated: 2025/10/07 15:06:21 by jgiancol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// Helper function to get chunk size based on stack size
static int get_chunk_size(int size)
{
    if (size <= 100)
        return size / 5;  // 5 chunks for ≤100 elements
    else
        return size / 2; // 11 chunks for >100 elements
}

// Push elements in a range to stack B
static void push_range_to_b(t_stack_node **a, t_stack_node **b, int min_index, int max_index)
{
    int size = stack_size(*a);
    int rotations = 0;
    
    while (size > 3)
    {
        if ((*a)->index >= min_index && (*a)->index <= max_index)
        {
            pb(a, b, true);
            size--;
            rotations = 0;
            
            // Rotate stack B to optimize later retrieval
            if (*b && (*b)->next && (*b)->index < max_index - (max_index - min_index) / 2)
                rb(b, true);
        }
        else if (rotations < size)
        {
            ra(a, true);
            rotations++;
        }
        else
            break;
    }
}

// Assign indices to stack elements for easier sorting
static void assign_indices(t_stack_node *stack)
{
    t_stack_node *current = stack;
    t_stack_node *compare;
    int index;
    
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

// Find the best position in A to insert the top element of B
static int find_target_position(t_stack_node *a, int b_index)
{
    t_stack_node *current = a;
    int position = 0;
    int target_pos = 0;
    int closest_bigger = INT_MAX;
    int closest_pos = 0;
    
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
    
    // If no bigger element found, insert before the smallest
    if (closest_bigger == INT_MAX)
    {
        t_stack_node *min_node = find_min_node(a);
        target_pos = find_node_position(a, min_node);
    }
    else
    {
        target_pos = closest_pos;
    }
    
    return target_pos;
}

// Calculate cost of moving element from B to A
static int calculate_move_cost(t_stack_node *a, t_stack_node *b, int b_pos)
{
    int a_size = stack_size(a);
    int b_size = stack_size(b);
    t_stack_node *b_node = b;
    
    // Get the B element at position b_pos
    for (int i = 0; i < b_pos; i++)
        b_node = b_node->next;
    
    int target_pos = find_target_position(a, b_node->index);
    
    // Calculate cost for stack B
    int b_cost = (b_pos <= b_size / 2) ? b_pos : b_size - b_pos;
    
    // Calculate cost for stack A
    int a_cost = (target_pos <= a_size / 2) ? target_pos : a_size - target_pos;
    
    return a_cost + b_cost;
}

// Find the cheapest element to move from B to A
static int find_cheapest_move(t_stack_node *a, t_stack_node *b)
{
    int b_size = stack_size(b);
    int cheapest_pos = 0;
    int min_cost = INT_MAX;
    
    for (int i = 0; i < b_size; i++)
    {
        int cost = calculate_move_cost(a, b, i);
        if (cost < min_cost)
        {
            min_cost = cost;
            cheapest_pos = i;
        }
    }
    
    return cheapest_pos;
}

// Rotate stacks to optimal positions
static void execute_cheapest_move(t_stack_node **a, t_stack_node **b, int b_pos)
{
    int a_size = stack_size(*a);
    int b_size = stack_size(*b);
    t_stack_node *b_node = *b;
    
    // Get the B element at position b_pos
    for (int i = 0; i < b_pos; i++)
        b_node = b_node->next;
    
    int target_pos = find_target_position(*a, b_node->index);
    
    // Move element in B to top
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
    
    // Move target position in A to top
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
    
    // Push from B to A
    pa(a, b, true);
}

// Final rotation to put minimum element at the top
static void final_rotation(t_stack_node **a)
{
    t_stack_node *min_node = find_min_node(*a);
    int min_pos = find_node_position(*a, min_node);
    int size = stack_size(*a);
    
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

void sort_large(t_stack_node **a, t_stack_node **b)
{
    if (!a || !*a || is_sorted(*a))
        return;
    
    int size = stack_size(*a);
    int chunk_size = get_chunk_size(size);
    
    // Assign indices for easier comparison
    assign_indices(*a);
    
    // Push elements to B in chunks
    int i = 0;
    while (stack_size(*a) > 3)
    {
        int min_index = i * chunk_size;
        int max_index = (i + 1) * chunk_size - 1;
        
        if (max_index >= size - 3)
            max_index = size - 4; // Leave at least 3 elements in A
        
        push_range_to_b(a, b, min_index, max_index);
        i++;
        
        if (stack_size(*a) <= 3)
            break;
    }
    
    // Sort remaining 3 elements in A
    if (stack_size(*a) == 3)
        sort_three(a);
    else if (stack_size(*a) == 2 && (*a)->value > (*a)->next->value)
        sa(a, true);
    
    // Move elements back from B to A in optimal order
    while (*b)
    {
        int cheapest_pos = find_cheapest_move(*a, *b);
        execute_cheapest_move(a, b, cheapest_pos);
    }
    
    // Final rotation to ensure minimum is at the top
    if (!is_sorted(*a))
        final_rotation(a);
}
