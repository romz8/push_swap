/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjobert <rjobert@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 19:02:12 by rjobert           #+#    #+#             */
/*   Updated: 2023/06/30 19:02:14 by rjobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* how to push from stack b to a : 
if b is not empty, we create a node which content is
equal to content of front node of linked list a
2 - it will be front node on b  */
void    push(t_list **target, t_list **source)
{
    t_list *node;
    t_list *tmp;

    if (!*source)
        return ;
    node = ft_stack_new((*source)->data);
    if (!*target)
        *target = node;
    else    
        ft_stack_add_front(target, node);
    if ((*source)->next)
    {   
        tmp = ((*source)->next);
        free(*source);
        *source = tmp;
        (*source)->prev = NULL;
    }
    else
    {
        free(*source);
        *source = NULL;
    }
    return ;
}
void    pa(t_list **stack_a, t_list **stack_b)
{
    push(stack_a, stack_b);
    ft_printf("Exec pa\n");
}

void    pb(t_list **stack_a, t_list **stack_b)
{
    push(stack_b, stack_a);
    ft_printf("Exec pb\n");
}