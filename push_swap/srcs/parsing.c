/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiancol <jgiancol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 22:59:23 by jgiancol          #+#    #+#             */
/*   Updated: 2025/10/24 23:02:10 by jgiancol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	handle_single_arg(t_stack_node **a, char *arg)
{
	char	**args;

	args = ft_split(arg, ' ');
	if (!args || !args[0])
	{
		write(2, "Error\n", 6);
		if (args)
			free_split(args);
		return (1);
	}
	if (!validate_arguments(args) || has_duplicates(args))
	{
		free_split(args);
		return (1);
	}
	init_stack_a(a, args);
	free_split(args);
	return (0);
}

int	handle_multiple_args(t_stack_node **a, char **argv)
{
	if (!validate_arguments(argv + 1) || has_duplicates(argv + 1))
		return (1);
	init_stack_a(a, argv + 1);
	return (0);
}
