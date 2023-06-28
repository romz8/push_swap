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
# include "./libft_printf/ft_printf.h"
# include "./libft_printf/libft/libft.h"

typedef struct s_stack {
    int     data;
    struct s_stack *next;
    struct s_stack *prev; 
}   t_list;


void    create_stack(int argc, char **argv, t_list **stack);
void	ft_stack_add_front(t_list **stack, t_list *new);
t_list	*ft_stack_new(int content);
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
int     stack_len(t_list **stack);
int     find_stack_max(t_list **stack);


#endif