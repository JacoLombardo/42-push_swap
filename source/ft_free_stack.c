/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 14:46:14 by jalombar          #+#    #+#             */
/*   Updated: 2024/07/17 14:46:14 by jalombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
