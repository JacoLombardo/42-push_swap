/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 14:52:13 by jalombar          #+#    #+#             */
/*   Updated: 2024/06/20 14:52:13 by jalombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* int ft_create_stack(char *str, t_stack **a)
{
    int i;
    int j;
    char *buffer;

    i = 0;
    buffer = (char *)malloc(12 * sizeof(char));
    while (str[i])
    {
        j = 0;
        ft_bzero(buffer, 12);
        if (i == 0 && str[i] != 43 && str[i] != 45 && !(str[i] >= 48 && str[i] <= 57))
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

int ft_create_stack(char *str, t_stack **a)
{
    int i;

    i = 0;
    while (str[i])
    {
        ft_lst_add(a, ft_atoi(str));
        while (str[i] == 43 && str[i] == 45 && (str[i] >= 48 && str[i] <= 57))
            i++;
    }
    return (1);
}

char    *push_swap(t_stack *a)
{
    return (NULL);
}

int main(int argc, char **argv)
{
    t_stack *a;
    int i;

    a = NULL;
    i = 0;
    if (argc > 1)
    {
        while (i < argc)
        {
            if(!ft_create_stack(argv[i], &a))
                write(1, "Error\n", 6);
            i++;
        }
        while (a)
        {
            printf("%i\n", a->nbr);
            a = a->next;
        }
    }
    return (0);
}