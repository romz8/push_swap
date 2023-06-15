/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_structure.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjobert <rjobert@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 17:24:38 by rjobert           #+#    #+#             */
/*   Updated: 2023/06/15 17:25:06 by rjobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    create_stack(int argc, char *argv, t_list **stack)
{
    int i;
    int n;
    t_list *node;
    
    i = 1;
    while (i < argv)
    {
        n = ft_atoi(argv[i]);
        node = ft_lstnew((int *) n);
        if (!*stack)
            *stack = node;
        else    
            ft_lstadd_front(stack, node);
    }
    return ;
}

/* how to push from stack b to a : 
if b is not empty, we create a node which content is
equal to content of font of linked list a
the a is empty, will be first node, else add it on
front */
void    pa(t_list **stack_a, t_list **stack_b)
{
    t_list *node;

    if (!*stack_b)
        return ;
    node = ft_lstnew((int *) (*stack_b)->data);
    if (!*stack_a)
        *stack_a = node;
    else    
        ft_lastadd_front(stack_a, node);
    ft_printf("Exec pa");
    return ;
}

void    pb(t_list **stack_b, t_list **stack_a)
{
    pa(stack_b, stack_a);
    ft_printf("Exec pb");
}

/* how to swap 2 front nodes of list : if more than 2
nodes:
1 - we make the front node point to third node (or null)
2 - make second node point to first 
3 - make head of list the second node */
void    swap(t_list **stack)
{
    *t_list temp;
    *t_list head;

    if (!*stack || !(*stack)->next)
        return;
    head = *stack;
    temp = head->next;
    head->next = head->next->next;
    temp->next = head;
    *stack = temp;

    ft_printf("Exec swap");
    return ;
}

/*how to rotate : 
1 - keep in the front node in temp
2 - make the second node new head
3 - go to last node and make it point to former front */
void    rotate(**t_list stack)
{
    t_list *tmp;
    t_list *head;

    if (!*stack)
        return ;
    head = *stack;
    tmp = head;
    head = head->next;
    while ( head && head->next)
        head = head->next;
    head->next = tmp;
}

/* how to reverse rotate (last node become first)
1- we go to the almost last node
2 - we save in temp the last node
3 - we make the almost last node the lst (point null)
4 + we make temp point to head and head = temp */
void    reverse_rotate(t_list **stack)
{
    t_list  *head;
    t_list  *temp;

    if (!*stack)
        return ;
    head = *stack;
    while (head->next->next)
        head = head->next;
    temp = head->next;
    head->next = NULL;
    temp->next = head;
    head = temp;
}   


