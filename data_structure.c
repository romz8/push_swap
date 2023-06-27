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


/* how to push from stack b to a : 
if b is not empty, we create a node which content is
equal to content of front node of linked list a
2 - it will be front node on b  */
void    push(t_list **stack_a, t_list **stack_b)
{
    t_list *node;
    t_list *tmp;

    if (!*stack_b)
        return ;
    node = ft_stack_new((*stack_b)->data);
    if (!*stack_a)
        *stack_a = node;
    else    
        ft_stack_add_front(stack_a, node);
    tmp = ((*stack_b)->next);
    free(*stack_b);
    *stack_b = tmp;
    (*stack_b)->prev = NULL;

    return ;
}
void    pa(t_list **stack_a, t_list **stack_b)
{
    push(stack_a, stack_b);
    ft_printf("Exec pa\n");
}

void    pb(t_list **stack_a, t_list **stack_b)
{
    push(stack_b, stack_a);
    ft_printf("Exec pb\n");
}

/* how to swap 2 front nodes of list : if more than 2
nodes:
1 - we make the front node point to third node (or null)
2 - make second node point to first 
3 - make head of list the second node */
void    swap(t_list **stack)
{
    t_list *first;
    t_list *second;

    if (!*stack || !(*stack)->next)
        return;
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

void    sa(t_list **a)
{
    swap(a);
    ft_printf("Exec sa\n");
}

void    sb(t_list **b)
{
    swap(b);
    ft_printf("Exec sb\n");
}

void    ss(t_list **a, t_list **b)
{
    swap(a);
    swap(b);
    ft_printf("Exec ss : sa sb\n");
}

/*how to rotate : first node become last
1 - keep in the front node in temp
2 - save the second node for future head and make it prev point to null
3 - go to last node and make it point to former front
4 - make the new last node point to NULL */
void    rotate(t_list **stack)
{
    t_list *tmp;
    t_list *head;
    t_list *save;

    if (!*stack)
        return ;
    head = *stack;
    tmp = head;
    save = head->next;
    if (head->next)
        head->next->prev = NULL;
    while (head && head->next)
        head = head->next;
    head->next = tmp;
    tmp->prev = head;
    head->next->next = NULL;
    *stack = save;
}

void    ra(t_list **a)
{
    rotate(a);
    ft_printf("Exec ra\n");
}

void    rb(t_list **b)
{
    rotate(b);
    ft_printf("Exec rb\n");
}

void    rr(t_list **a, t_list **b)
{
    rotate(a);
    rotate(b);
    ft_printf("Exec rr : ra rb\n");
}

/* how to reverse rotate (last node become first)
1- we go to the almost last node
2 - we save in temp the last node
3 - we make the almost last node the lst (point null)
4 - we make temp point to head and head = temp */
void    reverse_rotate(t_list **stack)
{
    t_list  *head;
    t_list  *temp;
    t_list  *save;

    if (!*stack)
        return ;
    head = *stack;
    save = *stack;
    while (head->next->next)
        head = head->next;
    temp = head->next;
    temp->next = save;
    head->next = NULL;
    temp->prev = NULL;
    head = temp;
    *stack = head;
}

void    rra(t_list **a)
{
    reverse_rotate(a);
    ft_printf("Exec rra\n");
}

void    rrb(t_list **b)
{
    reverse_rotate(b);
    ft_printf("Exec rrb\n");
}

void    rrr(t_list **a, t_list **b)
{
    reverse_rotate(a);
    reverse_rotate(b);
    ft_printf("Exec rrr : rra rrb\n");
}

void print_stacks(t_list **a, t_list **b)
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
    while (head_a->next)
        head_a = head_a->next;
    while(head_b->next)
        head_b = head_b->next;
    while (head_a || head_b)
    {
        if (head_a)
        {
            ft_printf("%i   ", head_a->data); 
            head_a = head_a->prev;
        }
        if (head_b)
        {
            ft_printf("%i", head_b->data);
            head_b = head_b->prev;
        }
        ft_printf("\n");
    }
    ft_printf("-   -\n");
    ft_printf("a   b\n");
}