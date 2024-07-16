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

#include "../push_swap.h"

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

void	ss(t_stack **a, t_stack **b)
{
	sa(a);
	sb(b);
}

void	pb(t_stack **b, t_stack **a)
{
	t_stack	*temp;

	temp = *b;
	if (ft_lstsize(*b) > 0)
	{
		*b = (*b)->next;
		temp->next = NULL;
		ft_lstadd_back(a, temp);
	}
}

void	pa(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	temp = *a;
	if (ft_lstsize(*a) > 0)
	{
		*a = (*a)->next;
		temp->next = NULL;
		ft_lstadd_back(b, temp);
	}
}

