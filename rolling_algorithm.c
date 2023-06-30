/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rolling_algorithm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjobert <rjobert@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 18:54:46 by rjobert           #+#    #+#             */
/*   Updated: 2023/06/30 18:54:48 by rjobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

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