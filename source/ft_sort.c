/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 14:57:00 by jalombar          #+#    #+#             */
/*   Updated: 2024/07/24 15:44:06 by jalombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_free_costs(t_cost **costs, int size, t_minmax *minmax)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(costs[i]->moves);
		free(costs[i]);
		i++;
	}
	free(costs);
	free(minmax->min);
	free(minmax->max);
	free(minmax);
}

void	ft_exec_moves(t_moves *moves, t_stack **a, t_stack **b)
{
	if (moves->ra)
	{
		while (moves->ra--)
			ra(a, 1);
	}
	if (moves->rra)
	{
		while (moves->rra--)
			rra(a, 1);
	}
	if (moves->rb)
	{
		while (moves->rb--)
			rb(b, 1);
	}
	if (moves->rrb)
	{
		while (moves->rrb--)
			rrb(b, 1);
	}
	if (moves->rr)
	{
		while (moves->rr--)
			rr(a, b);
	}
	if (moves->rrr)
	{
		while (moves->rrr--)
			rrr(a, b);
	}
	pb(a, b);
}

t_cost	**ft_sort_costs(t_cost **costs, int size)
{
	int		i;
	int		j;
	t_cost	*temp;

	i = 0;
	temp = NULL;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (costs[j]->value > costs[j + 1]->value)
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

void	ft_check(t_stack **a, t_stack **b)
{
	t_stack		*temp;
	t_cost		**costs;
	t_minmax	*minmax;
	int			i;

	temp = *a;
	i = 0;
	costs = malloc(ft_lstsize(*a) * sizeof(t_cost *));
	minmax = ft_get_mm(*b);
	while (temp)
	{
		costs[i] = malloc(1 * sizeof(t_cost));
		costs[i]->moves = ft_calc_cost(*a, *b, temp, minmax);
		//ft_printf("A: %i - %i\n", temp->index, temp->nbr);
		costs[i]->value = ft_calc_moves(costs[i]->moves);
		costs[i]->index = temp->index;
		i++;
		temp = temp->next;
	}
	costs = ft_sort_costs(costs, ft_lstsize(*a));
	/* i = 0;
	while (i < ft_lstsize(*a))
	{
		ft_printf("Value: %i, ", costs[i]->value);
		ft_printf("index: %i\n", costs[i]->index);
		i++;
	} */
	ft_exec_moves(costs[0]->moves, a, b);
	ft_free_costs(costs, ft_lstsize(*a), minmax);
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
	{
		moves->rra = ft_lstsize(a) - temp->index + 1;
		//ft_printf("rra: %i", moves->rra);
	}
	else
	{
		moves->ra = temp->index - 1;
		//ft_printf("ra: %i", moves->ra);
	}
	//ft_printf("\n");
	return (ft_double_moves(moves));
}

int	ft_calc_moves(t_moves *moves)
{
	int	count;

	count = moves->pb;
	if (moves->ra)
	{
		//ft_printf("ra: %i\n", moves->ra);
		count += moves->ra;
	}
	if (moves->rb)
	{
		//ft_printf("rb: %i\n", moves->rb);
		count += moves->rb;
	}
	if (moves->rr)
	{
		//ft_printf("rr: %i\n", moves->rr);
		count += moves->rr;
	}
	if (moves->rra)
	{
		//ft_printf("rra: %i\n", moves->rra);
		count += moves->rra;
	}
	if (moves->rrb)
	{
		//ft_printf("rrb: %i\n", moves->rrb);
		count += moves->rrb;
	}
	if (moves->rrr)
	{
		//ft_printf("rrr: %i\n", moves->rrr);
		count += moves->rrr;
	}
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

void	ft_setnull(t_moves **moves)
{
	(*moves)->pb = 0;
	(*moves)->ra = 0;
	(*moves)->rb = 0;
	(*moves)->rr = 0;
	(*moves)->rra = 0;
	(*moves)->rrb = 0;
	(*moves)->rrr = 0;
}

t_moves	*ft_calc_cost(t_stack *a, t_stack *b, t_stack *temp, t_minmax *minmax)
{
	t_moves	*moves;
	int		index;

	//ft_printf("%i - %i: ", temp->index, temp->nbr);
	moves = malloc(1 * sizeof(t_moves));
	ft_setnull(&moves);
	index = 0;
	if (temp->nbr > minmax->max->value || temp->nbr < minmax->min->value)
	{
		if (minmax->max->index > ((ft_lstsize(b) / 2) + 1))
		{
			moves->rrb = ft_lstsize(b) - minmax->max->index + 1;
			//ft_printf("rrb: %i, ", moves->rrb);
		}
		else
		{
			moves->rb = minmax->max->index - 1;
			//ft_printf("rb: %i, ", moves->rb);
		}
	}
	else
	{
		//ft_printf("inside else\n");
		index = ft_find_spot(b, temp);
		if (index > ((ft_lstsize(b) / 2) + 1))
		{
			moves->rrb = ft_lstsize(b) - index + 1;
			//ft_printf("rrb: %i, ", moves->rrb);
		}
		else
		{
			if (index)
				moves->rb = index - 1;
			//ft_printf("rb: %i, ", moves->rb);
		}
		//ft_printf("index - %i: %i\n", temp->nbr, index);
	}
	moves = ft_calc_a(a, temp, moves);
	return (moves);
}
void	ft_sorttt(t_stack **a, t_stack **b)
{
	int i;

	i = 0;
	/* ft_check(a, b, 0);
	ft_printout(*a, *b);
	ft_printf("BEGINNING OF SECOND\n\n");
	ft_check(a, b, 0); */
	/* ft_check(a, b);
	ft_printout(*a, *b);
	ft_check(a, b);
	ft_printout(*a, *b); */
	while (ft_lstsize(*a) > 0)
	{
		//ft_printf("AAAA -> %i <-\n", i);
		ft_check(a, b);
		//ft_printout(*a, *b);
		//i++;
	}
	/* while (ft_lstsize(*b) > 0)
		pa(b, a); */
}
