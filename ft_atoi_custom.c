/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_custom.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjobert <rjobert@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 19:54:04 by rjobert           #+#    #+#             */
/*   Updated: 2023/07/02 19:54:07 by rjobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

int	ft_atoi_custom(const char *str, int *flag)
{
	int	    i;
	int	    sign;
	long    nbr;

	i = 0;
	sign = 1;
	nbr = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'
			|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r'))
		i++;
	if (str[i] && (str[i] == '-' || str[i] == '+'))
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
            *flag = -1; 
        nbr = (str[i] - 48) + nbr * 10;
        if (nbr > INT_MAX || nbr < INT_MIN)
            *flag = -1;
        if (*flag == -1)
            return (-1);
		i++;
	}
	return (sign * nbr);
}	