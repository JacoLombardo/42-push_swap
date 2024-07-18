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

t_stack	*ft_free_stack(t_stack *stack);
t_stack	*ft_lst_add(t_stack **stack, int nbr);
//int		ft_nbrlen(int nbr);
int		ft_lst_check(t_stack *stack, int nbr);
int		ft_atoi_2(char **str, t_stack **a);
t_stack *ft_create_stack(char *str, t_stack **a, int *stack_len);
int ft_handle_stack(char **argv, int argc, t_stack **a);
void	ft_set_index(t_stack **stack);

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