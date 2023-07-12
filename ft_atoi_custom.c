/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_custom.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjobert <rjobert@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 18:26:04 by rjobert           #+#    #+#             */
/*   Updated: 2023/07/12 18:36:18 by rjobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_non_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (1);
		i++;
	}
	return (0);
}

/* Classic atoi with a twist
1 - after traversing the string for space and taking into account 
the potential +/-, we return error if the string stop there 
(like just '-' or '+') 
2 - then, if we encounter a non-digit or a potential overflow, 
raise flag and retunr otherwise atoi classic*/
int	ft_atoi_custom(const char *str, int *flag)
{
	int		i;
	int		sign;
	long	nbr;

	sign = 1;
	nbr = 0;
	i = traverse_while_space(str, &sign);
	if (!str[i])
		*flag = -1;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (*flag = -1); 
		nbr = (str[i] - 48) + nbr * 10;
		i++;
	}
	nbr = sign * nbr;
	if (nbr > INT_MAX || nbr < INT_MIN)
		return (*flag = -1);
	return (nbr);
}

/* top optimize space as 42 school's rules state
that function needs to be less than 25 lines*/
int	traverse_while_space(const char *str, int *sign)
{
	int	i;

	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'
			|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r'))
		i++;
	if (str[i] && (str[i] == '-' || str[i] == '+'))
	{
		if (str[i] == '-')
			*sign *= -1;
		i++;
	}
	return (i);
}
