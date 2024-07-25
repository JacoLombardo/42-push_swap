/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_costs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 10:04:17 by jalombar          #+#    #+#             */
/*   Updated: 2024/07/25 14:25:21 by jalombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_free_costs(t_cost **costs, int size, t_minmax *minmax)
{
	int	i;

	i = 0;
	while (i <= size)
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

void	ft_check_costs(t_stack **a, t_stack **b)
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
		costs[i]->moves = ft_calc_b(*a, *b, temp, minmax);
		costs[i]->value = ft_count_moves(costs[i]->moves);
		costs[i]->index = temp->index;
		i++;
		temp = temp->next;
	}
	costs = ft_sort_costs(costs, ft_lstsize(*a));
	ft_exec_moves(costs[0]->moves, a, b);
	ft_free_costs(costs, ft_lstsize(*a), minmax);
}
