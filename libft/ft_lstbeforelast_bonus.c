/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstbeforelast_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 11:52:22 by jalombar          #+#    #+#             */
/*   Updated: 2024/07/12 11:53:04 by jalombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_stack	*ft_lstbeforelast(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next->next)
		lst = lst->next;
	return (lst);
}
