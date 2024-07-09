/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 15:40:39 by jalombar          #+#    #+#             */
/*   Updated: 2024/06/20 15:40:39 by jalombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_free_buff(char *buff, t_stack *stack)
{
    t_stack *temp;

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
    free(buff);
    return (0);
}

int	ft_nbrlen(int nbr)
{
	int i;

	i = 0;
	while (nbr)
	{
		i++;
		nbr /= 10;
	}
	return (i);
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