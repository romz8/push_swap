/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjobert <rjobert@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 18:23:41 by rjobert           #+#    #+#             */
/*   Updated: 2023/07/02 18:23:44 by rjobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Read user input and react as per exercise guidelines
1 - if no argument, return prompt
2 - if argument number is 2 (ex : ./push_swap "1 2 3")
then we use a ft_split to convert it to an array of char ptrs
3 - if argument number is higher (user input each nbr)
we allocate mem for each pointer char inside argv[] 
and NULL terminate it and copy argv into it (from argv[1])
4 - then convert the new char *ptr array into a int
array and we check for duplicate value -> if issue arise 
: we raise -1, otherwise return the array sizes */
int parse_input(int argc, char *argv[], int **clean_input)
{
    int     n;
    char    **input;
    int     flag;

    input = NULL;
    flag = 0;
    if (argc < 2 || !argv[1][0]) 
        return (0);
    else if (argc == 2)
        input = ft_split((const char *) argv[1], ' ');
    else
    {
        n = 0;
        input = malloc(argc * sizeof(char *));
        if (!input)
            return (-1);
        input[argc] = NULL;
        while (n < argc - 1)
        {
            input[n] = argv[n + 1];
            n++;
        }
    }
    n = char_to_nb_array(input, clean_input, & flag);
    check_duplicates(clean_input, & flag);
    free(input);
    if (flag < 0)
        return (-1);
    return (n);
}

/* take an array of pointers to char * and convert it
to a pointer to an array of integers
1 - measure the number of char pointers in the array (argv)
2 - deref nb_input and  allcaote a number of int corresponding
3 - convert each char * to an int, using the atoi_custom
4 - if atoi_custom encounter an issue -> flag raised to -1 */
int    char_to_nb_array(char **input, int **nb_input, int *flag)
{
    int i;
    int len;
    int n;

    len = 0;
    while(input[len])
        len++;
    *nb_input = malloc((len) * sizeof(int));
    i = 0;
    while (i < len)
    {
        n = ft_atoi_custom((const char *)input[i], flag);
        if (*flag == -1)
        {
            free(*nb_input);
            return (-1);
        }
        (*nb_input)[i] = n;
        i++;
    }
    return (len);
}

/*compare each number in the (newly created) array of ints 
to all the previous numbers and return -1 if it finds itself
otherwise return array size */
void check_duplicates(int **clean_input, int *flag)
{
    int i;
    int j;

    if (!*clean_input)
        return ;
    i = 1;
    while ((*clean_input)[i])
    {
        j = 0;
        while (j < i)
        {
            if ((*clean_input)[j] == (*clean_input)[i])
            {
                *flag = -1;
                return ;
            }
            j++;
        }
        i++;
    }
}