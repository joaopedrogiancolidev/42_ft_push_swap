/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiancol <jgiancol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 22:09:59 by jgiancol          #+#    #+#             */
/*   Updated: 2025/10/07 17:43:09 by jgiancol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>
# include "../../libft/libft.h"
# include "../../ft_printf/includes/ft_printf.h"

typedef struct s_stack_node
{
	int						value;
	int						index;
	struct s_stack_node		*next;
	struct s_stack_node		*prev;
}	t_stack_node;

// Stack initialization
void			free_stack(t_stack_node **stack);
void			init_stack_a(t_stack_node **a, char **argv);
void			append_node(t_stack_node **stack, int n);
long			ft_atol(const char *str);

// Stack utils
int				stack_size(t_stack_node *stack);
bool			is_sorted(t_stack_node *stack);
t_stack_node	*find_last_node(t_stack_node *stack);
t_stack_node	*find_max_node(t_stack_node *stack);
t_stack_node	*find_min_node(t_stack_node *stack);
int				find_node_position(t_stack_node *stack, t_stack_node *target);

// Error handling
int				is_valid_number(char *str);
int				validate_arguments(char **argv);
int				has_duplicates(char **argv);
void			check_duplicates(t_stack_node *a);
void			error_exit(t_stack_node **a, t_stack_node **b);
void			free_split(char **split);

// Operations
void			sa(t_stack_node **a, bool print);
void			sb(t_stack_node **b, bool print);
void			ss(t_stack_node **a, t_stack_node **b, bool print);
void			pa(t_stack_node **a, t_stack_node **b, bool print);
void			pb(t_stack_node **a, t_stack_node **b, bool print);
void			ra(t_stack_node **a, bool print);
void			rb(t_stack_node **b, bool print);
void			rr(t_stack_node **a, t_stack_node **b, bool print);
void			rra(t_stack_node **a, bool print);
void			rrb(t_stack_node **b, bool print);
void			rrr(t_stack_node **a, t_stack_node **b, bool print);

// Sorting algorithms
void			sort_three(t_stack_node **a);
void			sort_small(t_stack_node **a, t_stack_node **b);
void			sort_large(t_stack_node **a, t_stack_node **b);

//Debug
void			debug_stack(t_stack_node *stack, const char *name);
#endif