#include "push_swap.h"
#include <stdio.h>
int main(int argc, char *argv[])
{
    t_list *a;
    t_list *b;
    int     len;
    int     *clean_input;

    b = NULL;
    a = NULL;
    clean_input = NULL;

    len = parse_input(argc, argv, &clean_input);
    if (len == 0)
        return (0);
    if (len < 0)
    {
        write(2,"Error\n", 6);
        return (-1);
    }
    len = create_stack(len, clean_input, &a);
    if (len < 0)
    {
        free_stack(&a);
        return (-1);
    }
    ft_printf("Init stacks\n");
    print_stacks(&a, &b);
    //sort_3_ints(&a);
    push_swap(&a, &b);
    //print_stacks(&a, &b);
    //print_target(&b);
    //ft_printf("stack a is of size %i\n",stack_len(&a));
    //ft_printf("stack b is of size %i\n",stack_len(&b));
    free_stack(&a);
    free_stack(&b);
    free(clean_input);
    //print_target(&b);
    //ft_printf("\n\n Now printing the stack a \n\n");
    //print_target(&a);
}