/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiancol <jgiancol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 22:54:12 by jgiancol          #+#    #+#             */
/*   Updated: 2025/10/25 00:01:54 by jgiancol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	append_node(t_stack_node **stack, int n)
{
	t_stack_node	*node;
	t_stack_node	*last_node;

	if (!stack)
		return ;
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

static int	skip_whitespace_and_sign(const char *str, int *sign)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	*sign = 1;
	if (str[i] == '-')
		*sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	return (i);
}

static long	check_overflow(long num, char digit, int sign)
{
	if (num > (LONG_MAX - (digit - '0')) / 10)
	{
		if (sign == 1)
			return (LONG_MAX);
		else
			return (LONG_MIN);
	}
	return (num * 10 + (digit - '0'));
}

long	ft_atol(const char *str)
{
	long	num;
	int		sign;
	int		i;

	i = skip_whitespace_and_sign(str, &sign);
	num = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = check_overflow(num, str[i], sign);
		if (num == LONG_MAX || num == LONG_MIN)
			return (num);
		i++;
	}
	return (num * sign);
}

void	init_stack_a(t_stack_node **a, char **argv)
{
	long	value;
	int		i;

	i = 0;
	while (argv[i])
	{
		value = ft_atol(argv[i]);
		if (value > INT_MAX || value < INT_MIN)
			error_exit(a, NULL);
		append_node(a, (int)value);
		i++;
	}
}
