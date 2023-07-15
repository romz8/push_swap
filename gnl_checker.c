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

    line = NULL;
    if (fd < 0 || read(fd, &line, 0) < 0 || BUFFER_SIZE <= 0)
        return (gnl_free(&text));
    if (!text || (text && !ft_strrchr(text, '\n')))
        add_buffer(fd, &text); 
    if (!text)
        return (NULL); 
    line = get_line(text);
    if (!line)
        return(gnl_free(&text));
    text = update_static(text, 0, 0);
    return(line);
}


void    add_buffer(int fd, char **text)
{
    int     byte_read;
    char    buffer[BUFFER_SIZE + 1];
    
    byte_read = 1;
    buffer[0] = '\0';
    while (byte_read > 0 && !ft_strrchr(buffer, '\n'))
    {
        byte_read = read(fd, buffer, BUFFER_SIZE);
        if (byte_read > 0)
        {
            buffer[byte_read] = '\0';
            *text = gnl_strjoin(*text, buffer);
        }
    }
    if (byte_read < 0)
        gnl_free(text);
}

char    *get_line(char *text)
{
    int i;
    char *line;

    measure_n_create(&text, &line);
    if (!line)
        return (NULL);
    i = 0;
    while (text[i] && text[i] != '\n')
    {
        line[i] = text[i];
        i++;
    }
    if (text[i] == '\n')
        line[i] = text[i];
    return(line);
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
    i = 0;
    while (text[j])
    {
        text_after[i] = text[j];
        i++;
        j++;
    }
    gnl_free(&text);
    return(text_after);
}