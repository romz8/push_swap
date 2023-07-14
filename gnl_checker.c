/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjobert <rjobert@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 14:14:46 by rjobert           #+#    #+#             */
/*   Updated: 2023/07/14 14:14:50 by rjobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

char    *gnl_checker(int fd)
{
    char    *line;
    static char *text;

    if (fd < 0 || read(fd, &text, 0) < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    if (!text || text && !ft_strrchr(text, '\n')) //if first read or read and not \n
        add_buffer(fd, &text); 
    if (!text)
        return (NULL); //reached EOF or read issue
    line = get_line(text);
    if (!line)
        return(gnl_free(text));
    text = update_static(text, 0, 0);
    return(line);
}


void    add_buffer(int fd, char **text)
{
    int     byte_read;
    char    buffer[BUFFER_SIZE + 1];
    
    if (!*text)
        return;
    byte_read = 1;
    while (byte_read > 0 && !ft_strrchr(buffer, '\n'))
    {
        byte_read = read(fd, buffer, BUFFER_SIZE);
        buffer[BUFFER_SIZE] = '\0';
        *text = ft_strjoin(*text, buffer);
    }
    if (byte_read < 0)
        gnl_free(text);    
}

char    *get_line(char *text)
{
    int i;
    char *line;

    measure_n_create(text, &line);
    if (!line)
        return (NULL);
    i = -1;
    while (text[i] && text[i] != '\n')
    {
        line[i] = text[i];
        i++;
    }
    if (text[i] == '\n')
        line[i] = text[i];
    
}

char    *update_static(char *text, int i, int j)
{
    char *text_after;

    while (text[i])
        i++;
    while (text[j] && text[j] != '\n')
        j++;
    if (text[j] == '\n')
        j++;
    text_after = malloc((i - j + 1) * sizeof(char));
    if (!text_after)
        return (NULL);
    while (text[j])
    {
        text_after[j] = text[j];
        j++;
    }
    gnl_free(&text);
    return(text_after);
}