/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiancol <jgiancol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 23:19:32 by jgiancol          #+#    #+#             */
/*   Updated: 2025/10/24 23:01:59 by jgiancol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_stack(t_stack_node **stack)
{
	t_stack_node	*current;
	t_stack_node	*next;

	if (!stack)
		return ;
	current = *stack;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*stack = NULL;
}

void	debug_stack(t_stack_node *stack, const char *name)
{
	ft_printf("%s: ", name);
	while (stack)
	{
		ft_printf("%d ", stack->value);
		stack = stack->next;
	}
	ft_printf("\n");
}

static void	sort_stack(t_stack_node **a, t_stack_node **b)
{
	if (stack_size(*a) == 2)
		sa(a, true);
	else if (stack_size(*a) == 3)
		sort_three(a);
	else if (stack_size(*a) <= 5)
		sort_small(a, b);
	else
		sort_large(a, b);
}

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	if (argc == 1)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	if (argc == 2)
	{
		if (handle_single_arg(&a, argv[1]))
			return (1);
	}
	else
	{
		if (handle_multiple_args(&a, argv))
			return (1);
	}
	check_duplicates(a);
	if (!is_sorted(a))
		sort_stack(&a, &b);
	free_stack(&a);
	return (0);
}
