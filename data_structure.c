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

int create_stack(int len, int *input, t_list **stack)
{
    int i;
    t_list *node;
    
    i = 0;
    while (i < len)
    {
        node = ft_stack_new(input[i]);
        if (!node)
            return (-1);
        if (!*stack)
            *stack = node;
        else    
        {
            node->next = *stack;
            (*stack)->prev = node;  
            *stack = node;
        }
        i++;
    }
    return (1);
}

t_list	*ft_stack_new(int n)
{
	t_list*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->data = n;
	node->next = NULL;
    node->prev = NULL;
	return (node);
}

void	ft_stack_add_front(t_list **stack, t_list *new)
{
    if (!stack)
        return;
    new->next = *stack;
    (*stack)->prev = new;
    *stack = new;
}

void    free_stack(t_list **stack)
{
    t_list  *temp;

    if (!*stack)
        return;
    while (*stack)
    {
        temp = (*stack)->next;
        free(*stack);
        *stack = temp;
    }
}