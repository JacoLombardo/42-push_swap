/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 14:40:01 by jalombar          #+#    #+#             */
/*   Updated: 2024/07/26 12:35:12 by jalombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_move_stack(char *line, t_stack **a, t_stack **b)
{
	if (!ft_strcmp(line, "pa\n"))
		pa(b, a, 0);
	else if (!ft_strcmp(line, "pb\n"))
		pb(a, b, 0);
	else if (!ft_strcmp(line, "sa\n"))
		sa(a, 0);
	else if (!ft_strcmp(line, "sb\n"))
		sb(b, 0);
	else if (!ft_strcmp(line, "ss\n"))
		ss(a, b, 0);
	else if (!ft_strcmp(line, "ra\n"))
		ra(a, 0);
	else if (!ft_strcmp(line, "rb\n"))
		rb(b, 0);
	else if (!ft_strcmp(line, "rr\n"))
		rr(a, b, 0);
	else if (!ft_strcmp(line, "rra\n"))
		rra(a, 0);
	else if (!ft_strcmp(line, "rrb\n"))
		rrb(b, 0);
	else if (!ft_strcmp(line, "rrr\n"))
		rrr(a, b, 0);
}

void	checker(t_stack *a)
{
	t_stack	*b;
	char	*line;

	b = NULL;
	line = get_next_line(STDIN_FILENO);
	while (line)
	{
		ft_move_stack(line, &a, &b);
		line = get_next_line(STDIN_FILENO);
	}
	if (ft_check_order(a))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

int	main(int argc, char **argv)
{
	t_stack	*a;

	a = NULL;
	if (argc > 1)
	{
		if (!ft_handle_stack_checker(argv[1], &a))
			ft_printf("Error\n");
		else
			checker(a);
	}
	return (0);
}
