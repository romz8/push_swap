/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjobert <rjobert@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 17:32:50 by rjobert           #+#    #+#             */
/*   Updated: 2023/07/12 19:06:28 by rjobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

/* struct explanation
1 - data will be the number stored
2 - target will be th enode on stack_a target by node on stack_b
3 - rank is the position of the node in the stack (ascending) 
4 - move_distance is how many moves a node needds to match its target
5 - upper_half is to divide the sack in two part (to evaluate if 
move_distance needs swap & rotate OR reverse rotate)
6 - pointers to other nodes on the double linked list
*/
typedef struct s_stack {
	int				data;
	int				target;
	int				rank;
	int				move_count;
	int				upper_half;
	int				index;
	struct s_stack	*next;
	struct s_stack	*prev; 
}	t_list;

typedef struct tree {
	int			data;
	int			index;
	struct tree	*left;
	struct tree	*right;
}	t_tree;

/*======= SORTING ALGORITHM =============*/
void	sort_3_ints(t_list **stack);
void	push_swap(t_list **stack_a, t_list **stack_b);
int		check_sort(t_list **stack);
void	smart_pb(t_list **stack_a, t_list **stack_b, int stack_size);

/*======= Binary TREE & SEARCH FOR OPTIMIZATION ===*/
void	indexing_stack(t_list **stack);
t_tree	*create_tree_node(int value);
t_tree	*insert_tree(t_tree *root, t_tree *node);
int		binary_search(t_tree *root, int value);
void	tree_sort_index(t_tree *root, int *index);
void	free_binary_tree(t_tree *root);
/*====== USER INPUT CHECKING FUNCTIONS ========*/
int		char_to_nb_array(char **input, int **nb_input, int *flag);
int		parse_input(int argc, char *argv[], int **clean_input);
void	check_duplicates(int **clean_input, int *flag, int size);
int		ft_atoi_custom(const char *str, int *flag);
int		traverse_while_space(const char *str, int *sign);
void	parse_free(char **input);
int		find_non_digit(char *str);

/* ===== STACK MOVEMENT AS PER ASSIGNMENT========*/
void	push(t_list **stack_a, t_list **stack_b);
void	pa(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_b, t_list **stack_a);
void	swap(t_list **stack);
void	rotate(t_list **stack);
void	ra(t_list **a);
void	rb(t_list **b);
void	rr(t_list **a, t_list **b);
void	sa(t_list **a);
void	sb(t_list **b);
void	ss(t_list **a, t_list **b);
void	rra(t_list **a);
void	rrb(t_list **b);
void	rrr(t_list **a, t_list **b);

/*======= STACK UTILS FUNCTIONS =========*/
void	create_stack(int argc, int *argv, t_list **stack);
void	ft_stack_add_front(t_list **stack, t_list *new);
t_list	*ft_stack_new(int content);
void	free_stack(t_list **stack);
int		stack_len(t_list **stack);
int		find_stack_max(t_list **stack);
int		find_stack_min(t_list **stack);

/*======= STACK MOVEMENT FOR SORTING EFFICIENCY===*/
int		find_target(t_list **stack, int node_val);
void	move_distance(t_list **stack_a, t_list **stack_b);
void	find_target_rank(t_list **stack, int target, int *data);
void	rank_node_order(t_list **stack);
void	evaluate_node(t_list **stack_a, t_list **stack_b);
int		calculate_nb_move(t_list *head, t_list **a, t_list **b, int *data);
void	key_nodes(t_list **a, t_list **b, t_list **move_node, t_list **target);
void	rolling_engine(t_list **stack_a, t_list **stack_b);
void	rev_rotate_loop(t_list **a, t_list **b, t_list **trgt, t_list **nde);
void	rotate_loop(t_list **a, t_list **b, t_list **target, t_list **node);
void	diag_rotate_up(t_list **a, t_list **b, t_list **trgt, t_list **nde);
void	diag_rotate_down(t_list **a, t_list **b, t_list **trgt, t_list **nde);
void	rearrange_stack(t_list **stack);
void	reorder_down(t_list **stack, t_list **node);
void	reorder_up(t_list **stack, t_list **node);

/*========= LIBFT UTILS ============*/
int		ft_putstr(char *s);
int		ft_isdigit(int c);
char	**ft_split(char const *s, char c);
int		ft_putchar(int x);
size_t	ft_strlen(const char *str);

#endif
