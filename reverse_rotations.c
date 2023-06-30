/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjobert <rjobert@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 18:59:47 by rjobert           #+#    #+#             */
/*   Updated: 2023/06/30 18:59:50 by rjobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* how to reverse rotate (last node become first)
1- we go to the almost last node
2 - we save in temp the last node
3 - we make the almost last node the lst (point null)
4 - we make temp point to head and head = temp */
void    reverse_rotate(t_list **stack)
{
    t_list  *head;
    t_list  *temp;
    t_list  *save;

    if (!*stack || !(*stack)->next)
        return ;
    head = *stack;
    save = *stack;
    while (head->next->next)
        head = head->next;
    temp = head->next;
    temp->next = save;
    save->prev = temp;
    head->next = NULL;
    temp->prev = NULL;
    head = temp;
    *stack = head;
}

void    rra(t_list **a)
{
    reverse_rotate(a);
    ft_printf("Exec rra\n");
}

void    rrb(t_list **b)
{
    reverse_rotate(b);
    ft_printf("Exec rrb\n");
}

void    rrr(t_list **a, t_list **b)
{
    reverse_rotate(a);
    reverse_rotate(b);
    ft_printf("Exec rrr : rra rrb\n");
}