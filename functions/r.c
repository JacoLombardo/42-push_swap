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

#include "../push_swap.h"

void	ra(t_stack **a, int single)
{
	t_stack	*temp;

	temp = NULL;
	if (ft_lstsize(*a) > 2)
	{
		temp = *a;
		*a = (*a)->next;
		temp->next = NULL;
		ft_lstadd_back(a, temp);
	}
	if (single)
		ft_printf("ra\n");
}

void	rb(t_stack **b, int single)
{
	t_stack	*temp;

	temp = NULL;
	if (ft_lstsize(*b) > 2)
	{
		temp = *b;
		*b = (*b)->next;
		temp->next = NULL;
		ft_lstadd_back(b, temp);
	}
	if (single)
		ft_printf("rb\n");
}

void	rr(t_stack **a, t_stack **b)
{
	ra(a, 0);
	rb(b, 0);
	ft_printf("rr\n");
}

