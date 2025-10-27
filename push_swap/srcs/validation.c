/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiancol <jgiancol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 22:53:38 by jgiancol          #+#    #+#             */
/*   Updated: 2025/10/24 22:55:24 by jgiancol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_valid_number(char *str)
{
	int		i;
	int		has_digits;

	i = 0;
	has_digits = 0;
	if (!str || str[0] == '\0')
		return (0);
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '\0')
		return (0);
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (str[i] == '\0' || !ft_isdigit(str[i]))
		return (0);
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]))
			return (0);
		has_digits = 1;
		i++;
	}
	return (has_digits);
}

int	validate_arguments(char **argv)
{
	int		i;
	long	value;

	i = 0;
	while (argv[i])
	{
		if (!is_valid_number(argv[i]))
		{
			write(2, "Error\n", 6);
			return (0);
		}
		value = ft_atoi(argv[i]);
		if (value > INT_MAX || value < INT_MIN)
		{
			write(2, "Error\n", 6);
			return (0);
		}
		i++;
	}
	return (1);
}

int	has_duplicates(char **argv)
{
	int		i;
	int		j;
	long	value_i;
	long	value_j;

	i = 0;
	while (argv[i])
	{
		value_i = ft_atol(argv[i]);
		j = i + 1;
		while (argv[j])
		{
			value_j = ft_atol(argv[j]);
			if (value_i == value_j)
			{
				write(2, "Error\n", 6);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
