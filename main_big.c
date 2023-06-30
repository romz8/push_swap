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
    //sort_3_ints(&a);
    push_swap(&a, &b);
    print_stacks(&a, &b);
    print_target(&b);
    //print_target(&b);
    //ft_printf("\n\n Now printing the stack a \n\n");
    //print_target(&a);
}