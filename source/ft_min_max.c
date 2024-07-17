/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min_max.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 16:30:38 by jalombar          #+#    #+#             */
/*   Updated: 2024/07/17 16:36:01 by jalombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int ft_min(t_stack *stack)
{
    int i;
    int min;

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

int ft_max(t_stack *stack)
{
    int i;
    int max;

    i = 0;
    max = stack->nbr;
    while (i++ < ft_lstsize(stack))
    {
        if (stack->nbr > max)
            max = stack->nbr;
        stack = stack->next;
    }
    return (max);
}
