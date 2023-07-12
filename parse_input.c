/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjobert <rjobert@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 18:23:41 by rjobert           #+#    #+#             */
/*   Updated: 2023/07/12 18:27:42 by rjobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

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
int	parse_input(int argc, char *argv[], int **nb_input)
{
	char	**input;
	int		flag;
	int		n;

	flag = 0;
	if (argc < 2 || !argv[1][0])
		return (0);
	else if (argc == 2 && find_non_digit(argv[1]) == 1)
		input = ft_split((const char *) argv[1], ' ');
	else
		input = &argv[1];
	n = char_to_nb_array(input, nb_input, &flag);
	check_duplicates(nb_input, &flag, n);
	if (argc == 2 && find_non_digit(argv[1]) == 1)
		parse_free(input);
	if (flag < 0)
	{
		if (*nb_input)
			free(*nb_input);
		return (-1);
	}
	return (n);
}

/* take an array of pointers to char * and convert it
to a pointer to an array of integers
1 - measure the number of char pointers in the array (argv)
2 - deref nb_input and  allcaote a number of int corresponding
3 - convert each char * to an int, using the atoi_custom
4 - if atoi_custom encounter an issue -> flag raised to -1 */
int	char_to_nb_array(char **input, int **clean_input, int *flag)
{
	int	i;
	int	len;
	int	n;

	len = 0;
	while (input[len])
		len++;
	*clean_input = malloc((len) * sizeof(int));
	if (!*clean_input)
	{
		*flag = -1;
		return (-1);
	}
	i = 0;
	while (i < len)
	{
		n = ft_atoi_custom((const char *)input[i], flag);
		if (*flag == -1)
			return (-1);
		(*clean_input)[i] = n;
		i++;
	}
	return (len);
}

/*compare each number in the (newly created) array of ints 
to all the previous numbers and return -1 if it finds itself
otherwise return array size */
void	check_duplicates(int **clean_input, int *flag, int size)
{
	int	i;
	int	j;

	if (!*clean_input)
		return ;
	i = 0;
	while (i < size)
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

void	parse_free(char **input)
{
	int	i;

	i = 0;
	if (!input)
		return ;
	while (input[i])
	{
		free(input[i]);
		i++;
	}
	free(input);
}
