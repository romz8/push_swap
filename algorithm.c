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
5 - re-do target part -> re-arrange everything so all is sorted */
void    sort_5max_ints(t_list **stack_a, t_list **stack_b)
{

    if (!*stack_a || stack_len(stack_a) != 5)
    if (!*stack_a || stack_len(stack_a) > 5)
        return ;
    while(stack_len(stack_a) != 3)
        pb(stack_a, stack_b);
    sort_3_ints(stack_a);
    while(*stack_b)
    {
        print_stacks(stack_a, stack_b); //CAREFULL !!!
        evaluate_node(stack_a, stack_b);
        print_target(stack_b); //CAREFULL !!!
        rolling_engine(stack_a, stack_b);
        pa(stack_a, stack_b);
    }
    rearrange_stack(stack_a);
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
    ft_printf("\n the stack_b is of length %i\n\n", stack_len(stack));
    while (head)
    {
        ft_printf("node_value : %i, node_target : %i, node_rank : %i, node_upper : %i, node_move_dist : %i \n", head->data, head->target, head->rank, head->upper_half, head->move_count);
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

/*move to top of stack_b the node with less move needed to reach its target
and move to top of stack_a this very target_node 
1 - idetnitfy those nodes with key_nodes function
2 - 4 cases :
2.a - if both nodes and target are in the lower half of their stack, we push 
them from the bottom : that's a reverse_rotate_loop -> see the function
2.b - if they are both the upper half, that's the opposite : we push them 
from the top : that's rotate_loop
2.c - if the node in the upper half and the target in the lower, the node is
brought up on stack_b by rotate, the target by reverse_rorate : that's a
diagonale rotation loop (conversally for the opposite diagonale) */
void    rolling_engine(t_list **stack_a, t_list **stack_b)
{
    t_list *move_node;
    t_list *target_node;

    if (!*stack_a || !*stack_b)
        return;
    move_node = NULL;
    target_node = NULL;
    key_nodes(stack_a, stack_b, &move_node, &target_node);
    if (!move_node || !target_node)
        return;
    if (move_node->upper_half == 0 && target_node->upper_half == 0)
        reverse_rotate_loop(stack_a, stack_b, &target_node, &move_node);
    else if (move_node->upper_half == 1 && target_node->upper_half == 1)
        rotate_loop(stack_a, stack_b, &target_node, &move_node);
    else if (move_node->upper_half == 1 && target_node->upper_half == 0)
        diagonale_rotate_up(stack_a, stack_b, &target_node, &move_node);
    else
        diagonale_rotate_down(stack_a, stack_b, &target_node, &move_node);
}

/* objective : bring both nodes on top when both are in the lower half
1 - until one of the node or target are on top of its respective stack, we reverse_rotate
(rrr) to both bring them closer to top in just one move (rrr is rra + rrb in one operation)
2 - if one of them is not on top after that, we continue the reverse_loop but on one stack*/
void    reverse_rotate_loop(t_list **stack_a, t_list **stack_b, t_list **target, t_list **move_node)
{
    if (!*stack_a || !*stack_b)
        return;
    while (*stack_a != *target && *stack_b != *move_node)
        rrr(stack_a, stack_b);
    while (*stack_a != *target)
        rra(stack_a);
    while (*stack_b != *move_node)
        rrb(stack_b);
}

/* objective : bring both nodes on top when both are in the upper half
1 - until one of the node or target are on top of its respective stack, we rotate (rr)
to both bring them closer to top in just one move (rrr is rra + rrb in one operation)
2 - if one of them is not on top after that, we continue the reverse_loop but on one stack*/
void    rotate_loop(t_list **stack_a, t_list **stack_b, t_list **target, t_list **move_node)
{
    if (!*stack_a || !*stack_b)
        return;
    while (*stack_a != *target && *stack_b != *move_node)
        rr(stack_a, stack_b);
    while (*stack_a != *target)
        ra(stack_a);
    while (*stack_b != *move_node)
        rb(stack_b);
}

/* objective : bring both nodes on top when node_b in the upper & target in lower half
1 - until node is on top of b: we  rotate (rb)
2 - until target is on top, we reverse_rotate (rra)*/
void    diagonale_rotate_up(t_list **stack_a, t_list **stack_b, t_list **target, t_list **move_node)
{
    if (!*stack_a || !*stack_b)
        return;
    while (*stack_a != *target)
        rra(stack_a);
    while (*stack_b != *move_node)
        rb(stack_b);
}

/*opposite case of diagonale down*/
void    diagonale_rotate_down(t_list **stack_a, t_list **stack_b, t_list **target, t_list **move_node)
{
    if (!*stack_a || !*stack_b)
        return;
    while (*stack_a != *target)
        ra(stack_a);
    while (*stack_b != *move_node)
        rrb(stack_b);
}

/* Obejctive : now that all nodes are on stack_a and the following node is its target, 
we re_arrange them so that the first node is the smallest : we need to decide what is the 
shortest route / with less operations : ra() (rotate, push from top to bottom) until the 
minimum appear, or the opposite using rra()s (reverese_rotate, push from bottom to top)
-> we map where is the minimum : if upper_half : ra(), else rra()
*/
void    rearrange_stack(t_list **stack)
{
    int min;
    t_list *min_node;
    t_list *head;

    if (!*stack)
        return;
    head = *stack;
    rank_node_order(stack);
    min = find_stack_min(stack);
    while (head)
    {
        if (head->data == min)
            min_node = head;
        head = head->next;
    }
    if (min_node->rank > stack_len(stack) /2 )
        reorder_down(stack, &min_node);
    else
        reorder_up(stack, &min_node);
}

void    reorder_down(t_list **stack, t_list **node)
{
    if (!stack || !node)
        return;
    while (*stack != *node)
        rra(stack);
}

void    reorder_up(t_list **stack, t_list **node)
{
    if (!stack || !node)
        return;
    while (*stack != *node)
        ra(stack);
}