/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_tree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjobert <rjobert@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 17:19:52 by rjobert           #+#    #+#             */
/*   Updated: 2023/07/12 17:19:54 by rjobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*create a copy from node on stack to a node for
the  binary tree */
t_tree *create_tree_node(int value)
{
    t_tree *new_node;

    new_node = malloc(sizeof(t_tree));
    if (!new_node)
        return (NULL);
    new_node->data = value;
    new_node->left = NULL;
    new_node->right = NULL;
    return (new_node);
}

/*insert a new node in the binary_tree using recursion:
1 - if there is no root, first node is root
2 - if value lower than root : left subtree
else right subtree. example :
stack : 4   8   5   2   1   3  
tree :
        8
      /
    5 
   /
4       2
  \   /
    3
     \ 1

*/
t_tree    *insert_tree(t_tree *root, t_tree *node)
{
    if (!root)
        return (node);
    if(node->data < root->data)
        root->left = insert_tree(root->left, node);
    else
        root->right = insert_tree(root->right, node);
    return (root);
}

/*Apply the divide and conquer approach of binary_search 
to our tree : look a first half, if lower, look at half 
of left etc..*/
int binary_search(t_tree *root, int value)
{
    if (!root || root->data == value)
        return (root->index);
    if (value < root->data)
        return (binary_search(root->left, value));
    return (binary_search(root->right, value));
}

/*we rusively traverse our tree too index starting fom 1
1- we go to the leftmost leaf of the leftmost subtree :
this the smallest value : recursion applied to root->left
until there  is no more node -> then go to previous call 
stack and the system will apply the index value to the node (1)
then to previous subtree -> 2,and so on until tree_sort_index
is recursively applied to right leaf*/
void tree_sort_index(t_tree *root, int *index)
{
    if (!root)
        return;
    tree_sort_index(root->left, index);
    root->index = *index;
    (*index)++;
    tree_sort_index(root->right, index);
}

void    free_binary_tree(t_tree *root)
{
    if (!root)
        return;
    free_binary_tree(root->left);
    free_binary_tree(root->right);
    free(root);
}