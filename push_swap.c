/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 14:52:13 by jalombar          #+#    #+#             */
/*   Updated: 2024/07/16 14:01:55 by jalombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_stack *a)
{
	t_stack	*b;

	b = NULL;
	if (ft_check_order(a))
		return ;
	else if (ft_lstsize(a) == 2)
		sa(&a, 1);
	else if (ft_lstsize(a) == 3)
		ft_sort_three(&a);
	else
	{
		pb(&a, &b, 1);
		pb(&a, &b, 1);
		ft_sort_big(&a, &b);
	}
	ft_free_stack(a);
}

int	main(int argc, char **argv)
{
	t_stack	*a;

	a = NULL;
	if (argc > 1)
	{
		if (!ft_handle_stack(argv, argc, &a))
			write(1, "Error\n", 6);
		else
			push_swap(a);
	}
	return (0);
}
