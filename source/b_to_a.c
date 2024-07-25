/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_to_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 10:29:10 by jalombar          #+#    #+#             */
/*   Updated: 2024/07/25 13:19:28 by jalombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_find_index_toa(t_stack *stack, t_stack *temp)
{
	t_stack	*prev;

	prev = stack;
	while (stack)
	{
		if (temp->nbr > prev->nbr && temp->nbr < stack->nbr)
			return (stack->index);
		prev = stack;
		stack = stack->next;
	}
	return (0);
}

t_moves	*ft_calc_b_toa(t_stack *b, t_stack *temp, t_moves *moves)
{
	moves->pa = 1;
	if (temp->index > ((ft_lstsize(b) / 2) + 1))
		moves->rrb = ft_lstsize(b) - temp->index + 1;
	else
		moves->rb = temp->index - 1;
	return (ft_double_moves(moves));
}

t_moves	*ft_calc_a_toa(t_stack *a, t_stack *b, t_stack *temp, t_minmax *minmax)
{
	t_moves	*moves;
	int		index;

	moves = malloc(1 * sizeof(t_moves));
	ft_moves_null(&moves);
	index = 0;
	if (temp->nbr > minmax->max->value || temp->nbr < minmax->min->value)
	{
		if (minmax->min->index > ((ft_lstsize(a) / 2) + 1))
			moves->rra = ft_lstsize(a) - minmax->min->index + 1;
		else
			moves->ra = minmax->min->index - 1;
	}
	else
	{
		index = ft_find_index_toa(a, temp);
		if (index > ((ft_lstsize(a) / 2) + 1))
			moves->rra = ft_lstsize(a) - index + 1;
		else
		{
			if (index)
				moves->ra = index - 1;
		}
	}
	return (ft_calc_b_toa(b, temp, moves));
}

void	ft_check_costs_toa(t_stack **b, t_stack **a)
{
	t_stack		*temp;
	t_cost		**costs;
	t_minmax	*minmax;
	int			i;

	temp = *b;
	i = 0;
	costs = malloc(ft_lstsize(*b) * sizeof(t_cost *));
	minmax = ft_get_mm(*a);
	while (temp)
	{
		costs[i] = malloc(1 * sizeof(t_cost));
		costs[i]->moves = ft_calc_a_toa(*a, *b, temp, minmax);
		costs[i]->value = ft_count_moves(costs[i]->moves);
		costs[i]->index = temp->index;
		i++;
		temp = temp->next;
	}
	costs = ft_sort_costs(costs, ft_lstsize(*b));
	ft_exec_moves(costs[0]->moves, a, b);
	ft_free_costs(costs, ft_lstsize(*b), minmax);
}
