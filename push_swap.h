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
# include <stdlib.h>
# include <unistd.h>

/* typedef struct s_stack
{
	int				index;
	int				nbr;
	struct s_stack	*next;
}					t_stack; */

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
	int					pb;
	int					ra;
	int					rb;
	int					rr;
	int					rra;
	int					rrb;
	int					rrr;
}					t_moves;

t_stack	*ft_free_stack(t_stack *stack);
t_stack	*ft_lst_add(t_stack **stack, int nbr);
int		ft_lst_check(t_stack *stack, int nbr);
int		ft_atoi_2(char **str, t_stack **a);
t_stack	*ft_create_stack(char *str, t_stack **a, int *stack_len);
int		ft_handle_stack(char **argv, int argc, t_stack **a);
void	ft_set_index(t_stack **stack);
void	ft_sort_three(t_stack **stack);
int		ft_check_order(t_stack *stack);
void	ft_printout(t_stack *a, t_stack *b);
t_minmax	*ft_get_mm(t_stack *stack);
void	ft_check(t_stack **a, t_stack **b);
t_moves	*ft_calc_cost(t_stack *a, t_stack *b, t_stack *temp, t_minmax *minmax);
int	ft_calc_moves(t_moves *moves);
t_minmax	*ft_get_mm(t_stack *stack);
void	ft_sorttt(t_stack **a, t_stack **b);

/* FUNCTIONS */

void	sa(t_stack **a, int single);
void	sb(t_stack **b, int single);
void	ss(t_stack **a, t_stack **b);
void	pb(t_stack **b, t_stack **a);
void	pa(t_stack **a, t_stack **b);
void	ra(t_stack **a, int single);
void	rb(t_stack **b, int single);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a, int single);
void	rrb(t_stack **b, int single);
void	rrr(t_stack **a, t_stack **b);

#endif