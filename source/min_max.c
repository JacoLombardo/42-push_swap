/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_max.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 16:30:38 by jalombar          #+#    #+#             */
/*   Updated: 2024/07/25 10:03:17 by jalombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_min	*ft_min(t_stack *stack)
{
	t_min	*min;

	min = malloc(1 * sizeof(t_min));
	min->value = stack->nbr;
	min->index = stack->index;
	while (stack)
	{
		if (stack->nbr < min->value)
		{
			min->value = stack->nbr;
			min->index = stack->index;
		}
		stack = stack->next;
	}
	return (min);
}

t_max	*ft_max(t_stack *stack)
{
	t_max	*max;

	max = malloc(1 * sizeof(t_max));
	max->value = stack->nbr;
	max->index = stack->index;
	while (stack)
	{
		if (stack->nbr > max->value)
		{
			max->value = stack->nbr;
			max->index = stack->index;
		}
		stack = stack->next;
	}
	return (max);
}

t_minmax	*ft_get_mm(t_stack *stack)
{
	t_minmax	*minmax;

	minmax = malloc(1 * sizeof(t_minmax));
	minmax->min = ft_min(stack);
	minmax->max = ft_max(stack);
	return (minmax);
}

/* int	ft_min(t_stack *stack)
{
	int	i;
	int	min;

	i = 0;
	min = stack->nbr;
	while (i++ < ft_lstsize(stack))
	{
		if (stack->nbr < min)
			min = stack->nbr;
		stack = stack->next;
	}
	return (min);
}

int	ft_max(t_stack *stack)
{
	int	i;
	int	max;

	i = 0;
	max = stack->nbr;
	while (i++ < ft_lstsize(stack))
	{
		if (stack->nbr > max)
			max = stack->nbr;
		stack = stack->next;
	}
	return (max);
} */