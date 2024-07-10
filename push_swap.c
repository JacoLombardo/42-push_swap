/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 14:52:13 by jalombar          #+#    #+#             */
/*   Updated: 2024/07/10 17:45:00 by jalombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* int ft_create_stack(char *str, t_stack **a)
{
	int		i;
	int		j;
	char	*buffer;
	int		i;
	int		i;

	i = 0;
	buffer = (char *)malloc(12 * sizeof(char));
	while (str[i])
	{
		j = 0;
		ft_bzero(buffer, 12);
		if (i == 0 && str[i] != 43 && str[i] != 45 && !(str[i] >= 48
				&& str[i] <= 57))
			return (ft_freeall(buffer, *a));
		if (i != 0 && str[i] == 8)
			i++;
		else
			return (ft_free_buff(buffer, *a));
		if (str[i] == 43 || str[i] == 45)
		{
			buffer[j] = str[i];
			i++;
			j++;
		}
		if (str[i] >= 48 && str[i] <= 57)
		{
			while (str[i] >= 48 && str[i] <= 57)
			{
				buffer[j] = str[i];
				i++;
				j++;
			}
			ft_lst_add(a, ft_atoi(buffer));
		}
	}
	free(buffer);
	return (1);
} */
/* int	ft_create_stack(char *str, t_stack **a)
{
	i = 0;
	while (str[i])
	{
		ft_lst_add(a, ft_atoi(str));
		while (str[i] == 43 && str[i] == 45 && (str[i] >= 48 && str[i] <= 57))
			i++;
	}
	return (1);
} */
/* char	*push_swap(t_stack *a)
{
	return (NULL);
}

int	ft_check_int(char *nbr)
{
	return (1);
} */

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
	if ((*(*str) != ' ' && *(*str) != '\0') || result < INT_MIN || result > INT_MAX)
		return (0);
	ft_lst_add(a, (int)result);
	return (1);
}

int	ft_extract(char *str, t_stack **a, int *stack_len)
{
	while (*str)
	{
		if (!ft_atoi_2(&str, a))
			return (0);
		*stack_len += 1;
		if (*str == ' ')
			str++;
	}
	return (1);
}

int	ft_create_stack(char *str, t_stack **a)
{
	if (!ft_atoi_2(&str, a))
		return (0);
	if (*str != '\0')
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	int		stack_len;
	int		i;

    a = NULL;
	i = 1;
	stack_len = 0;
	if (argc > 1)
	{
		if (argc == 2)
		{
			if (!ft_extract(argv[1], &a, &stack_len))
				write(1, "Error\n", 6);
		}
		else
		{
			while (i < argc)
			{
				if (!ft_create_stack(argv[i], &a))
					write(1, "Error\n", 6);
				i++;
			}
			stack_len = argc - 1;
		}
		while (a)
		{
			printf("%i\n", a->nbr);
			a = a->next;
		}
	}
	return (0);
}
