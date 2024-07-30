/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 14:40:15 by jalombar          #+#    #+#             */
/*   Updated: 2024/07/30 14:51:27 by jalombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../libft/libft.h"
# include "get_next_line/get_next_line.h"

void	ft_move_stack(char *line, t_stack **a, t_stack **b);
char	*get_next_line(int fd);

/* FUNCTIONS */
void	sa(t_stack **a, int print);
void	sb(t_stack **b, int print);
void	ss(t_stack **a, t_stack **b, int print);
void	pb(t_stack **b, t_stack **a, int print);
void	pa(t_stack **a, t_stack **b, int print);
void	ra(t_stack **a, int print);
void	rb(t_stack **b, int print);
void	rr(t_stack **a, t_stack **b, int print);
void	rra(t_stack **a, int print);
void	rrb(t_stack **b, int print);
void	rrr(t_stack **a, t_stack **b, int print);

/* push_swap */
t_stack	*ft_free_stack(t_stack *stack);
t_stack	*ft_lst_add_ps(t_stack **stack, int nbr);
t_stack	*ft_create_stack(char *str, t_stack **a, int *stack_len);
int		ft_handle_stack(char **argv, int argc, t_stack **a);
int		ft_atoi_2(char **str, t_stack **a);
int		ft_check_order(t_stack *stack);

#endif