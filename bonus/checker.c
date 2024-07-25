/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 14:40:01 by jalombar          #+#    #+#             */
/*   Updated: 2024/07/25 15:33:55 by jalombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_move_stack(char *line, t_stack **a, t_stack **b)
{
	if (!ft_strncmp(line, "pa\n"))
		pa(b, a, 0);
	else if (line == "pb\n")
		pb(a, b, 0);
	else if (line == "sa\n")
		sa(a, 0);
	else if (line == "sb\n")
		sb(b, 0);
	else if (line == "ss\n")
		ss(a, b, 0);
	else if (line == "ra\n")
		ra(a, 0);
	else if (line == "rb\n")
		rb(b, 0);
	else if (line == "rr\n")
		rr(a, b, 0);
	else if (line == "rra\n")
		rra(a, 0);
	else if (line == "rrb\n")
		rrb(b, 0);
	else if (line == "rrr\n")
		rrr(a, b, 0);
}

void	checker(t_stack *a)
{
	t_stack	*b;
	char	*line;

	line = get_next_line(STDOUT_FILENO);
	while (line)
	{
		ft_move_stack(line, &a, &b);
		line = get_next_line(STDOUT_FILENO);
	}
	if (ft_check_order(a))
		write(STDOUT_FILENO, "OK\n", 3);
	else
		write(STDOUT_FILENO, "KO\n", 3);
}

int	main(int argc, char **argv)
{
	t_stack	*a;

	a = NULL;
	if (argc > 1)
	{
		if (!ft_handle_stack_checker(argv[1], &a))
			write(1, "Error\n", 6);
		else
			checker(a);
	}
	return (0);
}
