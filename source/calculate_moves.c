/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_moves.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 10:07:07 by jalombar          #+#    #+#             */
/*   Updated: 2024/07/25 14:29:58 by jalombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_moves_null(t_moves **moves)
{
	(*moves)->pa = 0;
	(*moves)->pb = 0;
	(*moves)->ra = 0;
	(*moves)->rb = 0;
	(*moves)->rr = 0;
	(*moves)->rra = 0;
	(*moves)->rrb = 0;
	(*moves)->rrr = 0;
}

int	ft_count_moves(t_moves *moves)
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

t_moves	*ft_double_moves(t_moves *moves)
{
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

t_moves	*ft_calc_b(t_stack *a, t_stack *b, t_stack *temp, t_minmax *minmax)
{
	t_moves	*moves;
	int		index;

	moves = malloc(1 * sizeof(t_moves));
	ft_moves_null(&moves);
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
		index = ft_find_index(b, temp);
		if (index > ((ft_lstsize(b) / 2) + 1))
			moves->rrb = ft_lstsize(b) - index + 1;
		else
		{
			if (index)
				moves->rb = index - 1;
		}
	}
	return (ft_calc_a(a, temp, moves));
}
