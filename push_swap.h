/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjobert <rjobert@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 17:32:50 by rjobert           #+#    #+#             */
/*   Updated: 2023/06/15 17:32:52 by rjobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <limits.h>
# include "./libft_printf/ft_printf.h"
# include "./libft_printf/libft/libft.h"
typedef struct s_stack {
    int     data;
    int     target;
    int     rank;
    int     move_count;
    int     upper_half;
    struct s_stack *next;
    struct s_stack *prev; 
}   t_list;

/* struct explanation
1 - data will be the number stored
2 - target will be th enode on stack_a target by node on stack_b
3 - rank is the position of the node in the stack (ascending) 
4 - move_distance is how many moves a node needds to match its target
5 - upper_half is to divide the sack in two part (to evaluate if 
move_distance needs swap & rotate OR reverse rotate)
6 - pointers to other nodes on the double linked list
*/


int     create_stack(int argc, int *argv, t_list **stack);
int     char_to_nb_array(char **input, int **nb_input);
int     parse_input(int argc, char *argv[], int **clean_input);
int     check_duplicates(int **clean_input);
int     ft_atoi_custom(const char *str, int *flag);
void	ft_stack_add_front(t_list **stack, t_list *new);
t_list	*ft_stack_new(int content);
void    free_stack(t_list **stack);
void    push(t_list **stack_a, t_list **stack_b);
void    pa(t_list **stack_a, t_list **stack_b);
void    pb(t_list **stack_b, t_list **stack_a);
void    swap(t_list **stack);
void    rotate(t_list **stack);
void    print_stacks(t_list **a, t_list **b);
void    print_stacks_check_nodes(t_list **a, t_list **b);
void    print_reverse_stacks(t_list **a, t_list **b);
void    ra(t_list **a);
void    rb(t_list **b);
void    rr(t_list **a, t_list **b);
void    sa(t_list **a);
void    sb(t_list **b);
void    ss(t_list **a, t_list **b);
void    rra(t_list **a);
void    rrb(t_list **b);
void    rrr(t_list **a, t_list **b);
void    sort_3_ints(t_list **stack);
void    sort_5max_ints(t_list **stack_a, t_list **stack_b);
int     stack_len(t_list **stack);
int     find_stack_max(t_list **stack);
int     find_stack_min(t_list **stack);
int     find_target (t_list **stack, int node_val);
void    move_distance(t_list **stack_a, t_list **stack_b);
void    find_target_rank(t_list **stack, int target, int *data);
void    rank_node_order(t_list **stack);
void    evaluate_node(t_list **stack_a, t_list **stack_b);
int     calculate_nb_move(t_list *head, t_list **stack_a, t_list **stack_b, int *data);
void    key_nodes(t_list **stack_a, t_list **stack_b, t_list **move_node, t_list **target_node);
void    rolling_engine(t_list **stack_a, t_list **stack_b);
void    reverse_rotate_loop(t_list **stack_a, t_list **stack_b, t_list **target, t_list **node);
void    rotate_loop(t_list **stack_a, t_list **stack_b, t_list **target, t_list **node);
void    diagonale_rotate_up(t_list **stack_a, t_list **stack_b, t_list **target, t_list **node);
void    diagonale_rotate_down(t_list **stack_a, t_list **stack_b, t_list **target, t_list **node);
void    rearrange_stack(t_list **stack);
void    reorder_down(t_list **stack, t_list **node);
void    reorder_up(t_list **stack, t_list **node);
void    push_swap(t_list **stack_a, t_list **stack_b);


void    print_target(t_list **stack);

#endif