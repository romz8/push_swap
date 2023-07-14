/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjobert <rjobert@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 10:21:07 by rjobert           #+#    #+#             */
/*   Updated: 2023/07/14 10:21:10 by rjobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CHECKER_H
# define CHECKER_H
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE = 42
# endif

char    *gnl_checker(int fd);
char    *get_line(char *text);
void    add_buffer(int fd, char **text);
void    measure_n_create(char *text, char **line);
char    *update_static(char *text, int i, int j);
char    *ft_strrchr(const char *str, int c);
void	*ft_memmove(void *dst, const void*src, size_t len);
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);

#endif