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
	ft_printf("%i\n", a->nbr);
	return (NULL);
}

t_stack	*ft_create_stack(char *str, t_stack **a, int *stack_len)
{
	if (stack_len)
	{
		while (*str)
		{
			if (*str == ' ')
				return (ft_free_stack(*a));
			if (!ft_atoi_2(&str, a))
				return (ft_free_stack(*a));
			*stack_len += 1;
			if (*str == ' ')
				str++;
		}
	}
	else
	{
		if (!ft_atoi_2(&str, a))
			return (ft_free_stack(*a));
		if (*str != '\0')
			return (ft_free_stack(*a));
	}
	return (*a);
}

int	ft_handle_stack(char **argv, int argc, t_stack **a)
{
	int		i;
	int		stack_len;

	i = 1;
	stack_len = 0;
	if (argc > 1)
	{
		if (argc == 2)
		{
			if (!ft_create_stack(argv[1], a, &stack_len))
				return (0);
		}
		else
		{
			while (i < argc)
			{
				if (!ft_create_stack(argv[i], a, NULL))
					return (0);
				i++;
			}
			stack_len = argc - 1;
		}
	}
	return (1);
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
		/* while (a)
		{
			printf("%i\n", a->nbr);
			a = a->next;
		} */
		push_swap(a);
	}
	return (0);
}
