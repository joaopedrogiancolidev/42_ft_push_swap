/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiancol <jgiancol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 22:09:59 by jgiancol          #+#    #+#             */
/*   Updated: 2025/10/25 00:00:12 by jgiancol         ###   ########.fr       */
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

typedef struct s_range
{
	int	min;
	int	max;
}	t_range;

typedef struct s_closest
{
	int	value;
	int	pos;
}	t_closest;

// Stack initialization
void			free_stack(t_stack_node **stack);
void			init_stack_a(t_stack_node **a, char **argv);
void			append_node(t_stack_node **stack, int n);
int				handle_single_arg(t_stack_node **a, char *arg);
int				handle_multiple_args(t_stack_node **a, char **argv);
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

// Small Sorting algorithms
void			sort_three(t_stack_node **a);
void			sort_small(t_stack_node **a, t_stack_node **b);
void			sort_large(t_stack_node **a, t_stack_node **b);

// sort_large_utils.c
void			assign_indices(t_stack_node *stack);
int				find_target_position(t_stack_node *a, int b_index);
int				calculate_move_cost(t_stack_node *a, t_stack_node *b,
					int b_pos);

// sort_large_moves.c
void			push_range_to_b(t_stack_node **a, t_stack_node **b,
					t_range range);
int				find_cheapest_move(t_stack_node *a,
					t_stack_node *b);
void			execute_cheapest_move(t_stack_node **a, t_stack_node **b,
					int b_pos);
// sort_large_rotate.c
void			rotate_b_to_top(t_stack_node **b, int b_pos, int b_size);
void			rotate_a_to_target(t_stack_node **a, int target, int a_size);
void			final_rotation(t_stack_node **a);

//Debug
void			debug_stack(t_stack_node *stack, const char *name);

#endif