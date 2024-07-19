/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 11:38:16 by jalombar          #+#    #+#             */
/*   Updated: 2024/07/19 12:02:19 by jalombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_sort_three(t_stack **stack)
{
	int	nbr1;
	int	nbr2;
	int	nbr3;

	while (!ft_check_order(*stack))
	{
		nbr1 = (*stack)->nbr;
		nbr2 = (*stack)->next->nbr;
		nbr3 = (*stack)->next->next->nbr;
		if ((nbr1 > nbr2 && nbr1 < nbr3 && nbr2 < nbr3) || 
			(nbr1 > nbr2 && nbr1 > nbr3 && nbr2 > nbr3) || 
			(nbr1 < nbr2 && nbr1 < nbr3 && nbr2 > nbr3))
			sa(stack, 1);
		else if (nbr1 > nbr2 && nbr1 > nbr3 && nbr2 < nbr3)
			ra(stack, 1);
		else if (nbr1 < nbr2 && nbr1 > nbr3 && nbr2 > nbr3)
			rra(stack, 1);
	}
}
