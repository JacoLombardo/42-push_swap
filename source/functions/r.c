/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 11:31:13 by jalombar          #+#    #+#             */
/*   Updated: 2024/07/12 12:10:44 by jalombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	ra(t_stack **a, int print)
{
	t_stack	*temp;

	temp = NULL;
	if (ft_lstsize(*a) > 1)
	{
		temp = *a;
		*a = (*a)->next;
		temp->next = NULL;
		ft_lstadd_back(a, temp);
		ft_set_index(a);
		if (print)
			ft_printf("ra\n");
	}
}

void	rb(t_stack **b, int print)
{
	t_stack	*temp;

	temp = NULL;
	if (ft_lstsize(*b) > 1)
	{
		temp = *b;
		*b = (*b)->next;
		temp->next = NULL;
		ft_lstadd_back(b, temp);
		ft_set_index(b);
		if (print)
			ft_printf("rb\n");
	}
}

void	rr(t_stack **a, t_stack **b, int print)
{
	ra(a, 0);
	rb(b, 0);
	if (print)
		ft_printf("rr\n");
}
