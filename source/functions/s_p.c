/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_p.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 12:44:33 by jalombar          #+#    #+#             */
/*   Updated: 2024/07/12 12:10:36 by jalombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	sa(t_stack **a, int single)
{
	t_stack	*temp;

	temp = (*a)->next;
	if (ft_lstsize(*a) > 1)
	{
		(*a)->next = (*a)->next->next;
		(*a)->index = 2;
		temp->index = 1;
		temp->next = *a;
		*a = temp;
		if (single)
			ft_printf("sa\n");
	}
}

void	sb(t_stack **b, int single)
{
	t_stack	*temp;

	temp = (*b)->next;
	if (ft_lstsize(*b) > 1)
	{
		(*b)->next = (*b)->next->next;
		(*b)->index = 2;
		temp->index = 1;
		temp->next = *b;
		*b = temp;
		if (single)
			ft_printf("sb\n");
	}
}

void	ss(t_stack **a, t_stack **b)
{
	sa(a, 0);
	sb(b, 0);
	ft_printf("ss\n");
}

void	pa(t_stack **b, t_stack **a)
{
	t_stack	*temp;

	temp = *b;
	if (ft_lstsize(*b) > 0)
	{
		*b = (*b)->next;
		ft_set_index(b);
		ft_lstadd_front(a, temp);
		ft_set_index(a);
		ft_printf("pa\n");
	}
}

void	pb(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	temp = *a;
	if (ft_lstsize(*a) > 0)
	{
		*a = (*a)->next;
		ft_set_index(a);
		ft_lstadd_front(b, temp);
		ft_set_index(b);
		ft_printf("pb\n");
	}
}
