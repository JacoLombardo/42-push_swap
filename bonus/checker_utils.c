/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 14:41:28 by jalombar          #+#    #+#             */
/*   Updated: 2024/07/25 15:32:34 by jalombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_strncmp(char *s1, char *s2, int n)
{
	int	i;

	i = 0;
	if (n > 0)
	{
		while (((unsigned char)s1[i] || (unsigned char)s2[i]) && i < n)
		{
			if ((unsigned char)s1[i] != (unsigned char)s2[i])
			{
				return ((unsigned char)s1[i] - (unsigned char)s2[i]);
			}
			i++;
		}
	}
	return (0);
}

t_stack	*ft_create_stack_checker(char *str, t_stack **a, int *stack_len)
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
	return (*a);
}

int	ft_handle_stack_checker(char *argv, t_stack **a)
{
	int		i;
	int		stack_len;

	i = 1;
	stack_len = 0;
	if (!ft_create_stack_checker(argv, a, &stack_len))
		return (0);
	return (1);
}
