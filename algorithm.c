/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alogrithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjobert <rjobert@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 15:05:17 by rjobert           #+#    #+#             */
/*   Updated: 2023/07/12 17:47:58 by rjobert          ###   ########.fr       */
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
void	sort_3_ints(t_list **stack)
{
	if (!*stack || !((*stack)->next) || stack_len(stack) > 3)
		return ;
	if ((*stack)->data == find_stack_max(stack))
		ra(stack);
	else if ((*stack)->next->data == find_stack_max(stack))
		rra(stack);
	if ((*stack)->data > (*stack)->next->data)
		sa(stack);
}

/* the actual algorithm :
1- we use smart_push first : until halft the stack_a 
is pushed to b, we push the high nbr and roll the small ones 
to "pre-sort" roughly 
2 - then randomly the rest of the stack until only 3 nbrer on stack_a
3 - then everytime before we push back from b to a, we evaluate the
depth of each stack, which node on stack_b should target which node 
on stack_a, how many moves does that represent
4 - we then apply the rolling engine : based on the lowest nbr of 
move needed, we bring to top of stack-a and stack-b the node-target 
best fit
5 - we push the node from stack_b (now on top) to its target on 
stack_a (now on top)
6 - we repeat until no more node on stack_b and then re-arrange
*/
void	push_swap(t_list **stack_a, t_list **stack_b)
{
	int	stack_size;

	if (!*stack_a || check_sort(stack_a) == 0)
		return ;
	stack_size = stack_len(stack_a); 
	smart_pb(stack_a, stack_b, stack_size);
	while (stack_len(stack_a) > 3)
		pb(stack_a, stack_b);
	sort_3_ints(stack_a);
	while (*stack_b)
	{
		evaluate_node(stack_a, stack_b);
		rolling_engine(stack_a, stack_b);
		pa(stack_a, stack_b);
	}
	if (check_sort(stack_a) != 0)
		rearrange_stack(stack_a);
}

/* to check that the stack is sorted or not*/
int	check_sort(t_list **stack_head)
{
	t_list	*stack;

	stack = *stack_head;
	if (!stack)
		return (0);
	while (stack && stack->next)
	{
		if (stack->data > stack->next->data)
			return (1);
		stack = stack->next;
	}
	return (0);
}

/* the push_swap algorithm works fine without this 
function but it can be optimized :
before having only 3 numbers on stack_a, we will do 
smart push from a to b : 
1 - we index each node (from min (1) to max(stack length) so
for instance stack 3-2-7 would have index 2-1-3
2 - we traverse the stack and compare a node index to mid-value of
the stack_lenth : if is higher (index > mid_size) : we push it to 
stack_b, else we rotate. we keep doing until half the stack is pushed
now we have a roughly pre-sorted stack with higher nber on stack_b, 
smaller ones on stack_a */ 
void	smart_pb(t_list **stack_a, t_list **stack_b, int stack_size)
{
	int	push_count;
	int	i;

	if (!*stack_a || stack_size <= 3)
		return ;
	push_count = 0;
	indexing_stack(stack_a);
	i = 0;
	while (i < stack_size && push_count < stack_size / 2)
	{
		if ((*stack_a)->index > (stack_size / 2))
		{
			pb(stack_a, stack_b);
			push_count++;
		}
		else
			ra(stack_a);
		i++;
	}
}

/* to optimize the algorithm, we index the stack from 1 to n : 
smallest value node will have index 1 biggest node will have value n,
to avoid mixing up with rank, an example:

stack : 3   8   5   1   0 
rank  : 0   1   2   3   4
index : 3   5   4   2   1 

this will allow us to pre-roder the nodes and push to stack_b half of the 
higher value value node (when index > n / 2) and rotate the smaller values
(when index < n / 2) to have a roughly set on 2 stacks, and then allocate stack

unfortunately due to time constraint, we have to sort it fast in case of 500+
number so we can't copy all to array and go brutal on a slection sort, so 
instead of complexity O(n^2) we look to something closer to O(n*log(n)) : we use 
enter the stack as a Binary tree, index it recursively, and allocate back to
the stack the index by using a binary_search 

1 - we traverse the link list and turn to a binary_node with 
create_tree_node and insert_tree node
2 - we "sort" the binary tree meaning attributing an index 
3 - We traverse the stack and search for it's value in the binary_tree,
using a binary_search, we return the index*/
void	indexing_stack(t_list **stack)
{
	t_tree	*root;
	t_list	*head;
	t_tree	*binary_node;
	int		index;

	if (!*stack)
		return ;
	root = NULL;
	head = *stack;
	while (head)
	{
		binary_node = create_tree_node(head->data);
		root = insert_tree(root, binary_node);
		head = head->next;
	}
	index = 1;
	tree_sort_index(root, &index);
	head = *stack;
	while (head)
	{
		head->index = binary_search(root, head->data);
		head = head->next;
	}
	free_binary_tree(root);
}
