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
    if (len < 0)
    {
        write(2,"Error\n", 6);
        return (-1);
    }
    create_stack(len, clean_input, &a);
    //ft_printf("Init stacks\n");
    //print_stacks(&a, &b);

    push_swap(&a, &b);
    //print_stacks(&a, &b);
    free_stack(&a);
    free_stack(&b);
    free(clean_input);
    return (0);
}