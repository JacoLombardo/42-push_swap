/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 14:52:53 by jalombar          #+#    #+#             */
/*   Updated: 2024/07/12 12:04:49 by jalombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"

typedef struct s_minmax
{
	struct s_min		*min;
	struct s_max		*max;
}					t_minmax;

typedef struct s_min
{
	int		value;
	int		index;
}					t_min;

typedef struct s_max
{
	int		value;
	int		index;
}					t_max;

typedef struct s_cost
{
	struct s_moves	*moves;
	int				value;
	int				index;
}					t_cost;

typedef struct s_moves
{
	int					pa;
	int					pb;
	int					ra;
	int					rb;
	int					rr;
	int					rra;
	int					rrb;
	int					rrr;
}					t_moves;

/* FUNCTIONS */
void		sa(t_stack **a, int print);
void		sb(t_stack **b, int print);
void		ss(t_stack **a, t_stack **b, int print);
void		pb(t_stack **b, t_stack **a, int print);
void		pa(t_stack **a, t_stack **b, int print);
void		ra(t_stack **a, int print);
void		rb(t_stack **b, int print);
void		rr(t_stack **a, t_stack **b, int print);
void		rra(t_stack **a, int print);
void		rrb(t_stack **b, int print);
void		rrr(t_stack **a, t_stack **b, int print);

/* b_to_a */

int			ft_find_index_toa(t_stack *stack, t_stack *temp);
void		ft_check_costs_toa(t_stack **b, t_stack **a);
t_moves		*ft_calc_b_toa(t_stack *b, t_stack *temp, t_moves *moves);
t_moves		*ft_calc_a_toa(t_stack *a, t_stack *b, t_stack *temp, 
				t_minmax *minmax);

/* create_stack */
int			ft_atoi_2(char **str, t_stack **a);
t_stack		*ft_create_stack(char *str, t_stack **a, int *stack_len);
int			ft_handle_stack(char **argv, int argc, t_stack **a);

/* lst */
int			ft_check_order(t_stack *stack);
int			ft_check_double(t_stack *stack, int nbr);
void		ft_set_index(t_stack **stack);
t_stack		*ft_free_stack(t_stack *stack);
t_stack		*ft_lst_add_ps(t_stack **stack, int nbr);

/* min_max */
t_min		*ft_min(t_stack *stack);
t_max		*ft_max(t_stack *stack);
t_minmax	*ft_get_mm(t_stack *stack);

/* calculate_costs */
void		ft_free_costs(t_cost **costs, int size, t_minmax *minmax);
t_cost		**ft_sort_costs(t_cost **costs, int size);
void		ft_check_costs(t_stack **a, t_stack **b);

/* calculate_moves */
void		ft_moves_null(t_moves **moves);
int			ft_count_moves(t_moves *moves);
t_moves		*ft_double_moves(t_moves *moves);
t_moves		*ft_calc_a(t_stack *a, t_stack *temp, t_moves *moves);
t_moves		*ft_calc_b(t_stack *a, t_stack *b, t_stack *temp, t_minmax *minmax);

/* sort_big */
void		ft_exec_moves(t_moves *moves, t_stack **a, t_stack **b);
int			ft_find_index(t_stack *stack, t_stack *temp);
void		ft_sort_big(t_stack **a, t_stack **b);

void		ft_sort_three(t_stack **stack);

#endif