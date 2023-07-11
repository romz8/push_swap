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
    if (!*stack_a || check_sort(stack_a) == 0)
        return;
    while (stack_len(stack_a) > 3)
        pb(stack_a, stack_b);
    sort_3_ints(stack_a);
    while(*stack_b)
    {
        evaluate_node(stack_a, stack_b);
        //print_stacks_intel(stack_b);
        rolling_engine(stack_a, stack_b);
        pa(stack_a, stack_b);
        //print_stacks(stack_a, stack_b);
    }
    //printf("\n\nRE_ARRANGE PHASE \n\n");
    if (check_sort(stack_a) != 0)
        rearrange_stack(stack_a);
}

int check_sort(t_list **stack_head)
{
    t_list *stack;
    stack = *stack_head;
    if (!stack)
        return (0);
    while(stack && stack->next)
    {
        if (stack->data > stack->next->data)
            return (1);
        stack = stack->next;
    }
    return (0);
}

/* the push_swap algorithm works fine without this 
function but can be optimized :
before to have only 3 numbers on stack_a, we will do 
smart push from a to b : 
1 - if there is less than 2 nodeson b, no need to 
rank, evaluate and push given a target node on stack_b for 
a node on stack_a
2 - if there is more than 2 nodes, we push from stack a to 
stack b given the smallest number of move to optimize*/
void    smart_pb(t_list **stack_a, t_list **stack_b)
{
    int push_count;
    int stack_size;
    int i;
    
    if (!*stack_a)
        return ;
    push_count = 0;
    indexing_stack(stack_a);
    print_stacks_intel(stack_a);
    stack_size = stack_len(stack_a);
    i = 0;
    //printf("stack size is %i and stack_mid point is %i \n\n" , stack_size, stack_size / 2);
    while (i < stack_size && push_count < (stack_size / 2))
    {
        //printf("stack %i component are : value %i, index %i\n\n", i, (*stack_a)->data, (*stack_a)->index);
        if ((*stack_a)->index < (stack_size / 2))
        {
            pb(stack_a, stack_b);
            push_count++;
        }
        else 
            ra(stack_a);
        i++;
    }
    while (stack_size - push_count > 3)
    {
        pb(stack_a, stack_b);
        push_count++;
    }
    //printf("\n\n PRE_OPTIMIZATION FINISHED\n\n");
    //print_stacks(stack_a, stack_b);
}

void   indexing_stack(t_list **stack)
{
    t_list *head;
    int *stack_array;
    int size;
    int i;

    if (!*stack)
        return ;
    size = stack_len(stack);
    stack_array = malloc(size * sizeof(int));
    if (!stack_array)
        return ;
    head = *stack;
    i = 0;
    while(head)
    {
        stack_array[i] = head->data;
        i++;
        head = head->next;
    }
    sort_array(stack_array, size);
    assign_index(stack, stack_array, size);
    free(stack_array);
}

/* a disgusting selection sort to know order node->data 
in ascending order and index them in the stack data structure */
void sort_array(int *arr, int size)
{
    int i;
    int j;
    int temp;
    
    i = 0;
    while (i < size)
    {
        j = 0;
        while (j < i)
        {
            if (arr[j] > arr[i])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                i = 0;
                j = 0;
            }
            j++;
        }
        i++;
    }
}

/* we traverse the array starting and look in the stack 
for the correspinding, we allocate to the node->index the 
array position*/
void assign_index(t_list **stack, int *arr, int size)
{
    int i;
    t_list *head;
    
    if (!*stack || !arr)
        return;
    i = 0;
    while (i < size)
    {
        head = *stack;
        while (head->data != arr[i])
            head = head->next;
        head->index = i;
        i++;
    }
}