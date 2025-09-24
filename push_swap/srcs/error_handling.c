/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiancol <jgiancol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 15:11:38 by jgiancol          #+#    #+#             */
/*   Updated: 2025/09/24 18:12:29 by jgiancol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// Função auxiliar: pular espaços
int	skip_spaces(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	return (i);
}

int    is_valid_number(char *str)
{
    int    i;
    int    digits;
    long  value;  // Para verificar overflow

    i = skip_spaces(str);
    digits = 0;
    
    // String vazia ou só espaços
    if (!str[i])
        return (0);
    
    // Sinal + ou -
    if (str[i] == '-' || str[i] == '+')
        i++;
    
    // Deve ter pelo menos um dígito após o sinal
    if (!str[i])
        return (0);
    
    // Verificar dígitos
    while (str[i])
    {
        if (!ft_isdigit(str[i]))
            return (0);
        digits++;
        i++;
    }
    
    // Pelo menos um dígito
    if (digits == 0)
        return (0);
    
    // Verificar overflow (opcional, mas bom ter)
    value = ft_atoi(str);
    if (value > INT_MAX || value < INT_MIN)
        return (0);
    
    return (1);
}

// Verificar duplicatas na stack
void	check_duplicates(t_stack_node *a)
{
	t_stack_node	*current;
	t_stack_node	*runner;

	current = a;
	while (current)
	{
		runner = current->next;
		while (runner)
		{
			if (current->value == runner->value)
			{
				write(2, "Error\n", 6);
				exit(1);
			}
			runner = runner->next;
		}
		current = current->next;
	}
}

// Validar sintaxe de todos os argumentos
void	validate_arguments(char **argv)
{
	int	i;

	i = 1; // Pular nome do programa
	while (argv[i])
	{
		if (!is_valid_number(argv[i]))
		{
			ft_printf("Error\n");
			exit(1);
		}
		i++;
	}
}

// Função de erro geral
void	error_exit(t_stack_node **a, t_stack_node **b)
{
	if (a)
		free_stack(a);
	if (b)
		free_stack(b);
	write(2, "Error\n", 6);
	exit(1);
}

// Adicione esta função no error_handling.c ou utils
void    free_split(char **split)
{
    int i;

    if (!split)
        return;
    
    i = 0;
    while (split[i])
    {
        free(split[i]);
        i++;
    }
    free(split);
}