/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_checker_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjobert <rjobert@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 14:15:01 by rjobert           #+#    #+#             */
/*   Updated: 2023/07/14 14:15:02 by rjobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/* You need to modify strjoin because it return null
if any of the char is null -> */
char	*gnl_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*concat;

	if (!s1)
	{	
		s1 = malloc(1);
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	concat = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!concat)
		return (NULL);
	i = -1;
	while (s1[++i])
		concat[i] = s1[i];
	j = -1;
	while(s2[++j])
		concat[i + j] = s2[j];
	concat[i + j] = '\0';
	return (concat);
}

char	*ft_strrchr(const char *str, int c)
{
	char	*last_ptr;

	last_ptr = NULL;
	while (*str)
	{
		if (*str == (unsigned char) c)
			last_ptr = (char *) str;
		str++;
	}
	if (*str == (unsigned char) c)
		last_ptr = (char *) str;
	return (last_ptr);
}

char *gnl_free(char **text)
{
    if (*text)
        free(*text);
    return (NULL);
}

void    measure_n_create(char **text, char **line)
{
    int  i;
    
    i = 0;
    while ((*text)[i] && (*text)[i] != '\n')
        i++;
    if ((*text)[i] == '\n')
        i++;
    *line = malloc ((i + 1) * sizeof(char));
    if (!*line)
		return ;
    (*line)[i] = '\0';
}

int	ft_strncmp(char *s1, char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char) s1[i] - (unsigned char) s2[i]);
		i++;
	}
	return (0);
}