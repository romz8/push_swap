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
    sort_5_ints(&a, &b);
    print_stacks(&a, &b);
    print_target(&b);
}