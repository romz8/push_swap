/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjobert <rjobert@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 16:14:02 by rjobert           #+#    #+#             */
/*   Updated: 2023/06/27 16:14:05 by rjobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char *argv[])
{
    t_list *a;
    t_list *b;

    b = NULL;
    a = NULL;
    create_stack(argc, argv, &a);
     ft_printf("Init stacks\n");
    print_stacks(&a, &b);
    sa(&a);
    print_stacks(&a, &b);
    pb(&a, &b);
    pb(&a, &b);
    pb(&a, &b);
    print_stacks(&a, &b);
    rr(&a, &b);
    print_stacks(&a, &b);
    rrr(&a, &b);
    print_stacks(&a, &b);
    sa(&a);
    print_stacks(&a, &b);
    pa(&a, &b);
    pa(&a, &b);
    pa(&a, &b);
    print_stacks(&a, &b);
    ft_printf("\n");
    print_reverse_stacks(&a, &b);
    ft_printf("\n");
}