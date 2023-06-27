/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjobert <rjobert@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:12:41 by rjobert           #+#    #+#             */
/*   Updated: 2023/05/23 19:53:39 by rjobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "./libft/libft.h"

int	ft_putchar(int c);
int	ft_putstr(char *s);
int	ft_print_nbr(int y);
int	ft_hexprint(unsigned int nb, int maj);
int	ft_print_ui(unsigned int n);
int	ft_print_ptr(void *ptr);
int	ft_printf(const char *s, ...);

#endif
