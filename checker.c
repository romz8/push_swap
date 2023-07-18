/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjobert <rjobert@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 18:50:18 by rjobert           #+#    #+#             */
/*   Updated: 2023/07/18 11:18:31 by rjobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "push_swap.h"

int	main(int argc, char *argv[])
{
	int		len;
	t_list	*a;
	t_list	*b;
	int		*clean_input;
	char	*user_ops;

	if (argc == 1)
		return (0);
	len = parse_input(argc, argv, &clean_input);
	if (len < 0)
	{
		write(2, "Error\n", 6);
		return (-1);
	}
	create_stack(len, clean_input, &a);
	user_ops = load_input();
	run_input(&a, &b, user_ops);
	free_stack(&a);
	free_stack(&b);
	free(user_ops);
	free(clean_input);
	return (0);
}

char	*load_input(void)
{
	char	*input;
	char	*all_input;

	all_input = NULL;
	while (1)
	{
		input = gnl_checker(0);
		if (!input || input[0] == '\0')
			break ;
		all_input = gnl_strjoin(all_input, input);
		free(input);
	}
	if (input)
		free(input);
	return (all_input);
}

int	run_moves(t_list **a, t_list **b, char *ops)
{
	if (!ft_strncmp(ops, "sa\n", 3) && *a)
		sa(a, 0);
	else if (!ft_strncmp(ops, "sb\n", 3) && *b)
		sb(b, 0);
	else if (!ft_strncmp(ops, "ss\n", 3) && *a && *b)
		ss(a, b, 0);
	else if (!ft_strncmp(ops, "pa\n", 3) && *b)
		pa(a, b, 0);
	else if (!ft_strncmp(ops, "pb\n", 3) && *a)
		pb(a, b, 0);
	else if (!ft_strncmp(ops, "ra\n", 3) && *a)
		ra(a, 0);
	else if (!ft_strncmp(ops, "rb\n", 3) && *b)
		rb(b, 0);
	else if (!ft_strncmp(ops, "rr\n", 3) && *a && *b)
		rr(a, b, 0);
	else
		return (-1);
	return (0);
}

int	run_rotations(t_list **a, t_list **b, char *ops)
{
	if (!ft_strncmp(ops, "rra\n", 4) && *a)
		rra(a, 0);
	else if (!ft_strncmp(ops, "rrb\n", 4) && *b)
		rrb(b, 0);
	else if (!ft_strncmp(ops, "rrr\n", 4) && *a && *b)
		rrr(a, b, 0);
	else 
		return (-1);
	return (0);
}

int	run_input(t_list **a, t_list **b, char *ops)
{
	while (ops && ops[0])
	{
		if (run_rotations(a, b, ops) != -1)
			ops = ops + 4;
		else if (run_moves(a, b, ops) != -1)
			ops = ops + 3;
		else
		{
			write(2, "Error\n", 6);
			return (-1);
		}
	}
	if (check_sort(a) == 0 && !*b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (0);
}
