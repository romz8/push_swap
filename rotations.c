/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjobert <rjobert@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 19:00:28 by rjobert           #+#    #+#             */
/*   Updated: 2023/06/30 19:00:30 by rjobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*how to rotate : first node become last
1 - keep in the front node in temp
2 - save the second node for future head and make it prev point to null
3 - go to last node and make it point to former front
4 - make the new last node point to NULL */
void    rotate(t_list **stack)
{
    t_list *tmp;
    t_list *head;
    t_list *save;

    if (!*stack || !(*stack)->next)
        return ;
    head = *stack;
    tmp = head;
    save = head->next;
    if (head->next)
        head->next->prev = NULL;
    while (head && head->next)
        head = head->next;
    head->next = tmp;
    tmp->prev = head;
    head->next->next = NULL;
    *stack = save;
}

void    ra(t_list **a)
{
    rotate(a);
    ft_putstr("ra\n");
}

void    rb(t_list **b)
{
    rotate(b);
    ft_putstr("rb\n");
}

void    rr(t_list **a, t_list **b)
{
    rotate(a);
    rotate(b);
    ft_putstr("rr\n");
}