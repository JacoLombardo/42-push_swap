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

void	ft_printout(t_stack *a, t_stack *b)
{
	while (a || b)
	{
		if (a)
		{
			ft_printf("A-%i: ", a->index);
			ft_printf("%i    ", a->nbr);
			a = a->next;
		}

		if (b)
		{
			ft_printf("B-%i: ", b->index);
			ft_printf("%i", b->nbr);
			b = b->next;
		}
		ft_printf("\n");
	}
}

char	*push_swap(t_stack *a)
{
	t_stack	*b;

	b = NULL;
	if (ft_check_order(a))
		return (NULL);
	ft_printout(a, b);
	if (ft_lstsize(a) == 2)
		sa(&a, 1);
	else if (ft_lstsize(a) == 3)
		ft_sort_three(&a);
	ft_printout(a, b);
	/* pb(&a, &b);
	pb(&a, &b);
	pb(&a, &b);
	pb(&a, &b);
	ft_printout(a, b);
	rrb(&b, 1);
	ft_printout(a, b);
	rra(&a, 1);
	ft_printout(a, b);
	rrr(&a, &b);
	ft_printout(a, b); */
	return (NULL);
}

int	main(int argc, char **argv)
{
	t_stack	*a;

	a = NULL;
	if (argc > 1)
	{
		if (!ft_handle_stack(argv, argc, &a))
		{
			write(1, "Error\n", 6);
			return (0);
		}
		push_swap(a);
	}
	return (0);
}
