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

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*concat;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	concat = malloc(s1_len + s2_len + 1);
	if (!concat)
		return (NULL);
	ft_memmove(concat, s1, s1_len);
	ft_memmove(concat + s1_len, s2, s2_len);
	concat[s1_len + s2_len] = '\0';
	return (concat);
}

void	*ft_memmove(void *dst, const void*src, size_t len)
{
	size_t			i;
	unsigned char	*d;
	unsigned char	*s;

	if (!dst && !src)
		return (NULL);
	d = (unsigned char *) dst;
	s = (unsigned char *) src;
	if (s < d)
	{
		while (len--)
			d[len] = s[len];
	}
	else
	{
		i = 0;
		while (i < len)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (dst);
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

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char *gnl_free(char **text)
{
    if (*text)
        free(*text);
    return (NULL);
}

void    measure_n_create(char *text, char **line)
{
    int  i;
    
    i = 0;
    while (text[i] && text[i] != '\n')
        i++;
    if (text[i] == '\n')
        i++;
    *line = malloc ((i + 1) * sizeof(char));
    if (!*line)
        return;
    (*line)[i] = '\0';
}