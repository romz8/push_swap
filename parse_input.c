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

int parse_input(int argc, char *argv[], int **clean_input)
{
    int     n;
    char    **input;

    input = NULL;
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
    n = char_to_nb_array(input, clean_input);
    free(input);
    if (n < 0)
        return (-1);
    n = check_duplicates(clean_input);
    return (n);
}

int    char_to_nb_array(char **input, int **nb_input)
{
    int i;
    int len;
    int n;
    int flag;

    len = 0;
    while(input[len])
        len++;
    *nb_input = malloc((len) * sizeof(int));
    i = 0;
    flag = 0;
    while (i < len)
    {
        n = ft_atoi_custom((const char *)input[i], &flag);
        if (flag == -1)
        {
            free(*nb_input);
            return (-1);
        }
        (*nb_input)[i] = n;
        i++;
    }
    return (len);
}

int check_duplicates(int **clean_input)
{
    int i;
    int j;

    if (!*clean_input)
        return (-1);
    i = 1;
    while ((*clean_input)[i])
    {
        j = 0;
        while (j < i)
        {
            if ((*clean_input)[j] == (*clean_input)[i])
                return (-1);
            j++;
        }
        i++;
    }
    return (i);
}