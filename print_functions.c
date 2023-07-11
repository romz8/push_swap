/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjobert <rjobert@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 18:58:38 by rjobert           #+#    #+#             */
/*   Updated: 2023/06/30 18:58:41 by rjobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_stacks(t_list **a, t_list **b)
{
    t_list *head_a;
    t_list *head_b;

    if (!a && !b)
        return;
    head_a = *a;
    head_b = *b;
    printf("\n\n STACK IS \n\n");
    while (head_a || head_b)
    {
        if (head_a)
        {
            ft_printf("%i", head_a->data); 
            head_a = head_a->next;
        }
        ft_printf("\t");
        if (head_b)
        {
            ft_printf("%i", head_b->data);
            head_b = head_b->next;
        }
        ft_printf("\n");
    }
    ft_printf("-\t-\n");
    ft_printf("a\tb\n");
    ft_printf("\n=======================================================\n");
}

void print_stacks_check_nodes(t_list **a, t_list **b)
{
    t_list *head_a;
    t_list *head_b;

    if (!a && !b)
        return;
    head_a = *a;
    head_b = *b;
    while (head_a || head_b)
    {
        if (head_a)
        {
            ft_printf("%p : %i   ", head_a, head_a->data); 
            if (head_a->prev)
                ft_printf("\n prev node a: %p :%i\t", head_a->prev, head_a->prev->data);
            head_a = head_a->next;
        }
        if (head_b)
        {
            ft_printf("%i", head_b->data);
            head_b = head_b->next;
        }
        ft_printf("\n");
    }
    ft_printf("-   -\n");
    ft_printf("a   b\n");
}

//to verify the prev pointer of reverse linked list 
//is good after all modifications
void print_reverse_stacks(t_list **a, t_list **b)
{
    t_list *head_a;
    t_list *head_b;

    if (!a && !b)
        return;
    ft_printf("check printing reverse \n");
    head_a = *a;
    head_b = *b;
    while (head_a)
    {
        if (head_a->next)
            head_a = head_a->next;
        else
            break ;
    }   
    while(head_b)
    {
        if (head_b->next)
            head_b = head_b->next;
        else
            break ;
    }
    while (head_a || head_b)
    {
        if (head_a)
        {
            
            ft_printf("%i   ", head_a->data); 
            if (head_a->prev)
                head_a = head_a->prev;
            else 
                break;
        }
        if (head_b)
        {
            ft_printf("%i", head_b->data);
            if (head_a->prev)
                head_b = head_b->prev;
            else 
                break;
        }
        ft_printf("\n");
    }
    ft_printf("-   -\n");
    ft_printf("a   b\n");
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

void print_stacks_intel(t_list **a)
{
    t_list *head_a;

    if (!a)
        return;
    head_a = *a;
    while (head_a)
    {
        if (head_a)
        {
            ft_printf("\n node value: %i, node rank : %i, node upper_half: %i, node target : %i, nb_count :%i\n", head_a->data, head_a->rank, head_a->upper_half, head_a->target, head_a->move_count);
            head_a = head_a->next;
        }
        ft_printf("\n");
    }
    ft_printf("-\n");
    ft_printf("\n=======================================================\n");
}