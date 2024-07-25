/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 14:57:00 by jalombar          #+#    #+#             */
/*   Updated: 2024/07/25 13:58:06 by jalombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_exec_moves(t_moves *moves, t_stack **a, t_stack **b)
{
	while (moves->ra--)
		ra(a, 1);
	while (moves->rra--)
		rra(a, 1);
	while (moves->rb--)
		rb(b, 1);
	while (moves->rrb--)
		rrb(b, 1);
	while (moves->rr--)
		rr(a, b);
	while (moves->rrr--)
		rrr(a, b);
	if (moves->pb)
		pb(a, b);
	else if (moves->pa)
		pa(b, a);
}

int	ft_find_index(t_stack *stack, t_stack *temp)
{
	t_stack	*prev;

	prev = stack;
	while (stack)
	{
		if (temp->nbr < prev->nbr && temp->nbr > stack->nbr)
			return (stack->index);
		prev = stack;
		stack = stack->next;
	}
	return (0);
}

void	ft_sort_big(t_stack **a, t_stack **b)
{
	t_min	*min;
	int		moves;

	while (ft_lstsize(*a) > 3)
		ft_check_costs(a, b);
	ft_sort_three(a);
	while (ft_lstsize(*b) > 0)
		ft_check_costs_toa(b, a);
	min = ft_min(*a);
	if (min->index > ((ft_lstsize(*a) / 2) + 1))
	{
		moves = ft_lstsize(*a) - min->index + 1;
		while (moves--)
			rra(a, 1);
	}
	else
	{
		moves = min->index - 1;
		while (moves--)
			ra(a, 1);
	}
}
