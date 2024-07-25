/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 14:41:32 by jalombar          #+#    #+#             */
/*   Updated: 2024/07/17 14:41:32 by jalombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
		|| result > INT_MAX || ft_check_double(*a, (int)result))
		return (0);
	ft_lst_add(a, (int)result);
	return (1);
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
