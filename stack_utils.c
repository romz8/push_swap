/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjobert <rjobert@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 18:42:38 by rjobert           #+#    #+#             */
/*   Updated: 2023/06/30 18:42:41 by rjobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int find_stack_max(t_list **stack)
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
int find_stack_min(t_list **stack)
{
    int min;
    t_list  *head;
    head = *stack;
    min = head->data;
    while (head)
    {
        if (head->data < min)
            min = head->data;
        head = head->next;
    }
    return (min);
}

/* Each node on stack_b should have a target on stack_a
1- the target is the smallest bigger number (i.e the target of 5
would be 6 among the set (4,6,8)
2- if the number in bigger than any number on stack_a, it should target 
the smallest as we are considering a circular dble linked list with ra and rra*/
int find_target(t_list **stack, int node_val)
{
    t_list *head;
    int flag;
    int target;
    
    head = *stack;
    flag = 0;
    while (head)
    {
        if (node_val < head->data && flag == 0)
        {
            target = head->data;
            flag++;
        }
        else if (node_val < head->data && head->data < target)
            target = head->data;
        head = head->next;
    }
    if (flag == 0)
        target = find_stack_min(stack);
    return (target);
}

/*For a given node on stack_b, we need to find the position of 
the target node (on stack_a) & if it's in upper or lower half of stack_a  
: we store the information in an array (by default passed as ref) where
arr[0] is the position and arr[1] is a bolean on upper_half or not
we iterate over the stack and return the data 
when it's match the value targetd */
void    find_target_rank(t_list **stack, int target, int *data)
{
    t_list *head;

    head = *stack;
    while (head)
    {
        if (head->data == target)
        {
            data[0] = head->rank;
            data[1] = head->upper_half;
        }
        head = head->next;
    }
}