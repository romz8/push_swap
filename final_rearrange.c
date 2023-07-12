/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_rearrange.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjobert <rjobert@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 18:57:02 by rjobert           #+#    #+#             */
/*   Updated: 2023/07/12 17:56:21 by rjobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Obejctive : now that all nodes are on stack_a and the following node is 
 * its target, we re_arrange them so that the first node is the smallest : 
 * we need to decide what is the shortest route / with less operations : 
 * ra() (rotate, push from top to bottom) until the minimum appear, or the 
 * opposite using rra()s (reverese_rotate, push from bottom to top) -> 
 * we map where is the minimum : if upper_half : ra(), else rra()
*/
void	rearrange_stack(t_list **stack)
{
	int		min;
	t_list	*min_node;
	t_list	*head;

	if (!*stack)
		return ;
	head = *stack;
	rank_node_order(stack);
	min = find_stack_min(stack);
	while (head)
	{
		if (head->data == min)
			min_node = head;
		head = head->next;
	}
	if (min_node->rank > stack_len(stack) / 2)
		reorder_down(stack, &min_node);
	else
		reorder_up(stack, &min_node);
}

void	reorder_down(t_list **stack, t_list **node)
{
	if (!stack || !node)
		return ;
	while (*stack != *node)
		rra(stack);
}

void	reorder_up(t_list **stack, t_list **node)
{
	if (!stack || !node)
		return ;
	while (*stack != *node)
		ra(stack);
}
