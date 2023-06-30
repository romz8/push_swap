/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_mapping.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjobert <rjobert@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 18:48:59 by rjobert           #+#    #+#             */
/*   Updated: 2023/06/30 18:49:01 by rjobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*We iterate until reach the end of stack and :
1 - give each node its position (starting on 0)
2 - indicates if it's in upper_half (1) (over middle position) or not (0)*/
void    rank_node_order(t_list **stack)
{
    t_list *head;
    int     rank;
    int     mid_point;

    if (!*stack)
        return;
    head = *stack;
    mid_point = stack_len(stack) / 2;
    rank = 0;
    while (head)
    {
        head->rank = rank;
        if (rank > mid_point)
            head->upper_half = 0;
        else
            head->upper_half = 1;
        rank++;
        head = head->next;
    }
}

/* This where we feed our node with all the relative information :
1 - rank_node :position of each node
2 - find_target : allocate to each node on b its target on stack_a
3 - move_distance : how many moves are needed*/
void    evaluate_node(t_list **stack_a, t_list **stack_b)
{
    t_list *head_b;

    if (!*stack_a || !*stack_b)
        return;
    head_b = *stack_b;
    rank_node_order(stack_a);
    rank_node_order(stack_b);
    while(head_b)
    {
        head_b->target = find_target(stack_a, head_b->data);
        head_b = head_b->next;
    }
    move_distance(stack_a, stack_b);
}

/*How far is a target node from the actual node on stack_b ?
1 - find the target node for the given node
2 - calculate how many moves are needed to reach it*/
void    move_distance(t_list **stack_a, t_list **stack_b)
{
    t_list  *head;
    int     data[2];
    int     move;

    if (!*stack_a || !*stack_b)
        return;
    head = *stack_b;
    while (head)
    {
        find_target_rank(stack_a, head->target, data);
        move = calculate_nb_move(head, stack_a, stack_b, data);
        head->move_count = move;
        head = head->next;
    }
}

/* Objective : calculate how many moves are needed to have the node 
on top of stack b and the target on top fo stack a :
1 - if a node is in the upper half, to bring on top is a matter of how 
many rotation you need to do until on top : it's position_rank is the distance
2 - if a node is in the lower half, the further away from the mid point, 
the less reverse_rotation you need to do : so the last node would need one RR 
to be on top, the second last node  2 RR, .. , GIVEN stack_len gives the nbr 
of nodes and that rank starts at 0, it is nb_RR = STACK_LEN - NODE_RANK 
HOW Caculate the total moves ?
1 - if both are in the lower_half, they both need reverse_rotation. if 
target needs 2 rra on stack a and node needs one rrb on stack_b, the total 
is 3 : the first rra + rrb is done in one with rrr and then you do rra 
so if (nb_rra) + (nb_rrb) is even : divide by 2 (as will only use rrr), if 
it's odd : it's 0.5 * ((nb_rra) + (nb_rrb)) + 1 as you need one more rr 
2 - same logic but with ra / rb if they are both inn upper halft
3 - if they are "in diagonal" -> add up, no move grouping for optimisation
*/
int    calculate_nb_move(t_list *head, t_list **stack_a, t_list **stack_b, int *data)
{

    int move;

    if (head->upper_half == 0 && data[1] == 0)
    {
        if ((stack_len(stack_b)- head->rank) + (stack_len(stack_a) - data[0]) % 2 == 0)
            move = ((stack_len(stack_b)- head->rank) + (stack_len(stack_a) - data[0])) / 2;
        else
            move = ((stack_len(stack_b)- head->rank) + (stack_len(stack_a) - data[0])) / 2 + 1;
    }
    else if (head->upper_half == 1 && data[1] == 1)
    {
        if ((head->rank + data[0]) % 2 == 0)
            move = (head->rank + data[0]) / 2;
        else 
            move = (head->rank + data[0]) / 2 + 1;
    }
    else if (head->upper_half == 1 && data[1] == 0)
        move = head->rank + (stack_len(stack_a) - data[0]);
    else
        move = (stack_len(stack_b) - head->rank) + data[0];
    return (move);
}

/*When using the rolling engine, we need to know what node will be moved to top 
of stack b and what not is being target on stack a (and needs to be on top)
this function allocate a pointer on this two nodes, the two nodes being passed as reference
from rolling engin as NULL intialized
1 - it looks for move_node on b : the one node with the less movement needed
2 - it looks for target_node on stack_b, using move_node->target */
void    key_nodes(t_list **stack_a, t_list **stack_b, t_list **move_node, t_list **target_node)
{
    t_list *head;

    head = *stack_b;
    *move_node = head;
    while (head)
    {   
        if (head->move_count < (*move_node)->move_count)
            *move_node = head;
        head = head->next;
    }
    head = *stack_a;
    while (head)
    {
        if (head->data == (*move_node)->target)
            *target_node = head;
        head = head->next;
    }
}