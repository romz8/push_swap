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

void    create_stack(int argc, char **argv, t_list **stack)
{
    int i;
    int n;
    t_list *node;
    
    i = argc - 1;
    while (i > 0)
    {
        n = ft_atoi(argv[i]);
        node = ft_stack_new(n);
        if (!node)
            return ;
        if (!*stack)
            *stack = node;
        else    
        {
            node->next = *stack;
            (*stack)->prev = node;  
            *stack = node;
        }
        i--;
    }
    return ;
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