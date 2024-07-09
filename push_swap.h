/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 14:52:53 by jalombar          #+#    #+#             */
/*   Updated: 2024/06/20 14:52:53 by jalombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "./libft/libft.h"

typedef struct s_stack
{
	int             index;
	int             nbr;
	struct s_stack  *next;
} t_stack;

int ft_free_buff(char *buff, t_stack *stack);
t_stack *ft_lst_add(t_stack **stack, int nbr);
int ft_nblen(int nb);

#endif