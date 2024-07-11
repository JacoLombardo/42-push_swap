/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 14:52:53 by jalombar          #+#    #+#             */
/*   Updated: 2024/07/11 15:03:14 by jalombar         ###   ########.fr       */
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

t_stack				*ft_free_stack(t_stack *stack);
t_stack				*ft_lst_add(t_stack **stack, int nbr);
int					ft_nbrlen(int nbr);
int					ft_lst_check(t_stack *stack, int nbr);
int					ft_atoi_2(char **str, t_stack **a);

/* FUNCTIONS */

void				sa(t_stack **a);

#endif