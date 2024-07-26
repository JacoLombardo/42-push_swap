/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 12:02:12 by jalombar          #+#    #+#             */
/*   Updated: 2024/07/12 12:10:46 by jalombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	rra(t_stack **a, int print)
{
	t_stack	*temp;
	t_stack	*temp2;

	temp = NULL;
	temp2 = NULL;
	if (ft_lstsize(*a) > 2)
	{
		temp = ft_lstlast(*a);
		temp2 = ft_lstbeforelast(*a);
		temp2->next = NULL;
		ft_lstadd_front(a, temp);
		ft_set_index(a);
		if (print)
			ft_printf("rra\n");
	}
}

void	rrb(t_stack **b, int print)
{
	t_stack	*temp;
	t_stack	*temp2;

	temp = NULL;
	temp2 = NULL;
	if (ft_lstsize(*b) > 2)
	{
		temp = ft_lstlast(*b);
		temp2 = ft_lstbeforelast(*b);
		temp2->next = NULL;
		ft_lstadd_front(b, temp);
		ft_set_index(b);
		if (print)
			ft_printf("rrb\n");
	}
}

void	rrr(t_stack **a, t_stack **b, int print)
{
	rra(a, 0);
	rrb(b, 0);
	if (print)
		ft_printf("rrr\n");
}
