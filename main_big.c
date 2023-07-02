#include "push_swap.h"
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
    else if (len < 0)
    {
        ft_printf("Error\n");
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
    print_stacks(&a, &b);
    print_target(&b);
    free_stack(&a);
    free(clean_input);
    //print_target(&b);
    //ft_printf("\n\n Now printing the stack a \n\n");
    //print_target(&a);
}