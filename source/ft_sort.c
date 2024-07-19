/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 14:57:00 by jalombar          #+#    #+#             */
/*   Updated: 2024/07/19 17:16:39 by jalombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_cost	**ft_sort_costs(t_cost **costs, int size)
{
	int		i;
	int		j;
	t_cost	*temp;

	i = 0;
	j = 0;
	temp = NULL;
	while (i < size - 1)
	{
		while (j < size - i - 1)
		{
			if (costs[j].value > costs[j + 1].value)
			{
				temp = costs[j];
				costs[j] = costs[j + 1];
				costs[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
    return (costs);
}

void	ft_check(t_stack *a, t_stack *b)
{
	t_stack		*temp;
	t_cost		**costs;
	t_minmax	*minmax;
	int			i;

	temp = a;
	i = 0;
	costs = malloc(ft_lstsize(a) * sizeof(t_cost *));
	minmax = ft_get_mm(b);
	while (temp)
	{
		costs[i] = malloc(1 * sizeof(t_cost));
		costs[i]->value = ft_calc_cost(a, b, temp, minmax);
		costs[i]->index = temp->index;
		i++;
		temp = temp->next;
	}
	costs = ft_sort_costs(costs, ft_lstsize(a));
}

t_moves	*ft_double_moves(t_moves *moves)
{
	moves->rr = 0;
	moves->rrr = 0;
	if (moves->ra && moves->rb)
	{
		while (moves->ra && moves->rb)
		{
			moves->ra--;
			moves->rb--;
			moves->rr++;
		}
	}
	if (moves->rra && moves->rrb)
	{
		while (moves->rra != 0 && moves->rrb != 0)
		{
			moves->rra--;
			moves->rrb--;
			moves->rrr++;
		}
	}
	return (moves);
}

t_moves	*ft_calc_a(t_stack *a, t_stack *temp, t_moves *moves)
{
	moves->pb = 1;
	if (temp->index > ((ft_lstsize(a) / 2) + 1))
		moves->rra = ft_lstsize(a) - temp->index + 1;
	else
		moves->ra = temp->index - 1;
	return (ft_double_moves(moves));
}

int	ft_calc_moves(t_moves *moves)
{
	int	count;

	count = moves->pb;
	if (moves->ra)
		count += moves->ra;
	if (moves->rb)
		count += moves->rb;
	if (moves->rr)
		count += moves->rr;
	if (moves->rra)
		count += moves->rra;
	if (moves->rrb)
		count += moves->rrb;
	if (moves->rrr)
		count += moves->rrr;
	return (count);
}

int	ft_find_spot(t_stack *stack, t_stack *temp)
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

int	ft_calc_cost(t_stack *a, t_stack *b, t_stack *temp, t_minmax *minmax)
{
	t_moves	*moves;
	int		index;

	moves = malloc(1 * sizeof(t_moves));
	index = 0;
	if (temp->nbr > minmax->max->value || temp->nbr < minmax->min->value)
	{
		if (minmax->max->index > ((ft_lstsize(b) / 2) + 1))
			moves->rrb = ft_lstsize(b) - minmax->max->index + 1;
		else
			moves->rb = minmax->max->index - 1;
	}
	else
	{
		index = ft_find_spot(b, temp);
		if (index > ((ft_lstsize(b) / 2) + 1))
			moves->rrb = ft_lstsize(b) - index + 1;
		else
			moves->rb = index - 1;
	}
	moves = ft_calc_a(a, temp, moves);
	return (ft_calc_moves(moves));
}
