/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjobert <rjobert@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 19:01:19 by rjobert           #+#    #+#             */
/*   Updated: 2023/07/11 20:54:09 by rjobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* how to swap 2 front nodes of list : if more than 2
nodes:
1 - we make the front node point to third node (or null)
2 - make second node point to first 
3 - make head of list the second node */
void	swap(t_list **stack)
{
	t_list	*first;
	t_list	*second;

	if (!*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	first->prev = second;
	second->next = first;
	second->prev = NULL;
	*stack = second;
}

void	sa(t_list **a, int n)
{
	swap(a);
	if (n != 0)
		ft_putstr("sa\n");
}

void	sb(t_list **b, int n)
{
	swap(b);
	if (n != 0)
		ft_putstr("sb\n");
}

void	ss(t_list **a, t_list **b, int n)
{
	swap(a);
	swap(b);
	if (n != 0)
		ft_putstr("ss\n");
}
