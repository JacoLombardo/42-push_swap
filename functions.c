/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 12:44:33 by jalombar          #+#    #+#             */
/*   Updated: 2024/07/11 15:11:51 by jalombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **a)
{
	t_stack	*temp;

	temp = (*a)->next;
	if (ft_lstsize(*a) > 1)
	{
		(*a)->next = (*a)->next->next;
		temp->next = *a;
		*a = temp;
	}
}

void	sb(t_stack **b)
{
	t_stack	*temp;

	temp = (*b)->next;
	if (ft_lstsize(*b) > 1)
	{
		(*b)->next = (*b)->next->next;
		temp->next = *b;
		*b = temp;
	}
}
