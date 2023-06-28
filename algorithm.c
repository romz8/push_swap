/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alogrithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjobert <rjobert@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 15:05:17 by rjobert           #+#    #+#             */
/*   Updated: 2023/06/28 15:05:20 by rjobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* sorting (ascending) 3 consecutive nodes in dble linked list
1 - find the max among the 3 nodes and put it at the end :
    1.a : if the max is the first node, use rotate to push it to last node
    1.b : else if the max is second node, it needs to become last (so we 
    can reverse_rotate the actual last so that second node (max) is now last)
    1.c : if nothing is exectued : last node is already max
2 - now that we are sure that last node is max, compare top and middle :
if top node is bigger than mid node : swap */
void    sort_3_ints(t_list **stack)
{
    if (!*stack || !(*stack)->next->next || stack_len(stack) != 3)
        return ;
    if((*stack)->data == find_stack_max(stack))
        ra(stack);
    else if ((*stack)->next->data == find_stack_max(stack))
        rra(stack);
    if ((*stack)->data > (*stack)->next->data)
        sa(stack);
}

//measuring the length of stack
int     stack_len(t_list **stack)
{
    int count;
    t_list  *head;

    count = 0;
    head = *stack;
    while (head)
    {
        count++;
        head = head->next;
    }
    return (count);
}

int     find_stack_max(t_list **stack)
{
    int max;
    t_list  *head;

    head = *stack;
    max = head->data;
    while (head)
    {
        if (head->data > max)
            max = head->data;
        head = head->next;
    }
    return (max);
}