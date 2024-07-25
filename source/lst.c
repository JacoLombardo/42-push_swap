/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2024/07/17 14:47:11 by jalombar          #+#    #+#             */
/*   Updated: 2024/07/17 14:47:11 by jalombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_check_order(t_stack *stack)
{
	int	temp;

	temp = stack->nbr;
	if (ft_lstsize(stack) > 1)
	{
		stack = stack->next;
		while (stack)
		{
			if (temp > stack->nbr)
				return (0);
			temp = stack->nbr;
			stack = stack->next;
		}
	}
	return (1);
}

int	ft_check_double(t_stack *stack, int nbr)
{
	if (stack)
	{
		while (stack)
		{
			if (stack->nbr == nbr)
				return (1);
			stack = stack->next;
		}
	}
	return (0);
}

void	ft_set_index(t_stack **stack)
{
	int		i;
	t_stack	*temp;

	i = 1;
	temp = *stack;
	while (temp)
	{
		temp->index = i;
		i++;
		temp = temp->next;
	}
}

t_stack	*ft_free_stack(t_stack *stack)
{
	t_stack	*temp;

	temp = stack;
	if (stack)
	{
		while (stack)
		{
			temp = stack->next;
			free(stack);
			stack = temp;
		}
		stack = NULL;
	}
	return (NULL);
}

t_stack	*ft_lst_add(t_stack **stack, int nbr)
{
	t_stack	*temp;
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->index = 1;
	new->nbr = nbr;
	new->next = NULL;
	temp = *stack;
	if (*stack)
	{
		while (temp->next)
			temp = temp->next;
		new->index = temp->index + 1;
		temp->next = new;
	}
	else
		*stack = new;
	return (new);
}
