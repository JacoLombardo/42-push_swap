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

char	*push_swap(t_stack *a)
{
	t_stack	*b;

	b = NULL;
	pb(&a, &b);
	pb(&a, &b);
	pb(&a, &b);
	pb(&a, &b);
	ft_printf("%i    ", a->nbr);
	while (a)
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
