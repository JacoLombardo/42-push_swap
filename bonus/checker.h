/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 14:40:15 by jalombar          #+#    #+#             */
/*   Updated: 2024/07/25 15:33:05 by jalombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line/get_next_line.h"

typedef struct s_stack
{
	int				index;
	int				nbr;
	struct s_stack	*prev;
	struct s_stack	*next;
}					t_stack;

t_stack				*ft_create_stack_checker(char *str, t_stack **a,
						int *stack_len);
int					ft_handle_stack_checker(char *argv, t_stack **a);
void	ft_move_stack(char *line, t_stack **a, t_stack **b);
int	ft_strncmp(char *s1, char *s2, int n);

/* FUNCTIONS */
void				sa(t_stack **a, int print);
void				sb(t_stack **b, int print);
void				ss(t_stack **a, t_stack **b, int print);
void				pb(t_stack **b, t_stack **a, int print);
void				pa(t_stack **a, t_stack **b, int print);
void				ra(t_stack **a, int print);
void				rb(t_stack **b, int print);
void				rr(t_stack **a, t_stack **b, int print);
void				rra(t_stack **a, int print);
void				rrb(t_stack **b, int print);
void				rrr(t_stack **a, t_stack **b, int print);

/* push_swap */
t_stack				*ft_free_stack(t_stack *stack);
t_stack				*ft_lst_add_ps(t_stack **stack, int nbr);
int					ft_atoi_2(char **str, t_stack **a);
int	ft_check_order(t_stack *stack);
