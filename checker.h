/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjobert <rjobert@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 10:21:07 by rjobert           #+#    #+#             */
/*   Updated: 2023/07/18 11:29:41 by rjobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include "push_swap.h"
# include <fcntl.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*gnl_checker(int fd);
char	*get_line(char *text);
void	add_buffer(int fd, char **text);
void	measure_n_create(char **text, char **line, int *n);
char	*gnl_free(char **text);
char	*update_static(char *text, int i, int j);
char	*ft_strrchr(const char *str, int c);
char	*gnl_strjoin(char *s1, char *s2);
char	*load_input(void);
int		run_input(t_list **a, t_list **b, char *ops);
int		run_moves(t_list **a, t_list **b, char *ops);
int		run_rotations(t_list **a, t_list **b, char *ops);
int		ft_strncmp(char *s1, char *s2, size_t n);

#endif
