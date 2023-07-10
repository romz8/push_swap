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
    if (!*stack || !((*stack)->next) || stack_len(stack) > 3)
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
5 - re-do target part -> re-arrange everything so all is sorted */
void    sort_5max_ints(t_list **stack_a, t_list **stack_b)
{

    if (!*stack_a || stack_len(stack_a) > 5)
        return ;
    while(stack_len(stack_a) > 3)
        pb(stack_a, stack_b);
    sort_3_ints(stack_a);
    while(*stack_b)
    {
        evaluate_node(stack_a, stack_b);
        rolling_engine(stack_a, stack_b);
        pa(stack_a, stack_b);
    }
    rearrange_stack(stack_a);
}

void    push_swap(t_list **stack_a, t_list **stack_b)
{
    if (!*stack_a)
        return;
    while (stack_len(stack_a) > 5)
        pb(stack_a, stack_b);
    sort_5max_ints(stack_a, stack_b);
    while(*stack_b)
    {
        evaluate_node(stack_a, stack_b);
        rolling_engine(stack_a, stack_b);
        pa(stack_a, stack_b);
    }
    rearrange_stack(stack_a);
}