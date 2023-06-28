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

/* 
1 - we push node to stack_b until we have 3 nodes on stack_a
2 - we then sort the 3 nodes on stack_a using sort_3
3 - we allocate a target node on stack_a for all node stack_b
4 - we look at the cheapest move in term of ops for nodes of stack_a
to be on top of its target -> execute that move
5 - re-do target part -> re-arrange everything so all is sorted 
MISSING CALCULATING COST : IDEA : LOOK AT THE DEPTH to compute distance as operations*/
void    sort_5_ints(t_list **stack_a, t_list **stack_b)
{
    t_list *head_b;

    if (!*stack_a || stack_len(stack_a) != 5)
        return ;
    while(stack_len(stack_a) != 3)
        pb(stack_a, stack_b);
    sort_3_ints(stack_a);
    head_b = *stack_b;
    while(head_b)
    {
        head_b->target = find_target(stack_a, head_b->data);
        head_b = head_b->next;
    }
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

void    print_target(t_list **stack)
{
    t_list *head;
    if (!*stack)
        return;
    head = *stack;
    while (head)
    {
        ft_printf("node_value : %i, node_target : %i\n", head->data, head->target);
        head = head->next;
    }
}