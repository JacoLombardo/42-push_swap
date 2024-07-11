/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 15:40:39 by jalombar          #+#    #+#             */
/*   Updated: 2024/07/11 12:28:19 by jalombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	ft_atoi_2(char **str, t_stack **a)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	if (*(*str) == '+' || *(*str) == '-')
	{
		if (*(*str) == '-')
			sign = sign * -1;
		(*str)++;
	}
	if (*(*str) < '0' && *(*str) > '9')
		return (0);
	while (*(*str) >= '0' && *(*str) <= '9')
	{
		result = (result * 10) + (*(*str) - 48);
		(*str)++;
	}
	result = result * sign;
	if ((*(*str) != ' ' && *(*str) != '\0') || result < INT_MIN
		|| result > INT_MAX || ft_lst_check(*a, (int)result))
		return (0);
	ft_lst_add(a, (int)result);
	return (1);
}

int	ft_nbrlen(int nbr)
{
	int	i;

	i = 0;
	while (nbr)
	{
		i++;
		nbr /= 10;
	}
	return (i);
}

int	ft_lst_check(t_stack *stack, int nbr)
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

t_stack	*ft_lst_add(t_stack **stack, int nbr)
{
	t_stack	*temp;
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->nbr = nbr;
	new->next = NULL;
	temp = *stack;
	if (*stack)
	{
		while (temp->next)
			temp = temp->next;
		temp->next = new;
	}
	else
		*stack = new;
	return (new);
}
