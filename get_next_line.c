/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aayad <aayad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 15:09:38 by aayad             #+#    #+#             */
/*   Updated: 2024/12/03 21:29:21 by aayad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char  *stract_line(char *line)
{
    ssize_t   i;
    char  *left_str;
    
    i = 0;
    while (line[i] != '\n' && line[i] != '\0')
      i++;
    if (line[i] == 0 || line[i + 1] == 0)
        return (NULL);
    left_str = ft_substr(line, i + 1, ft_strlen(line) - i);
    if(*left_str == 0)
    {
        free(left_str);
        left_str = NULL;
    }
    line[i + 1] = '\0';
    return(left_str);
}
char *fill_buffer(int fd, char *left_str, char *buffer)
{
    ssize_t   n_read;
    char      *temp;
    
    n_read = 1;
    while (n_read > 0)
    {
        n_read = read(fd, buffer, BUFFER_SIZE);
        if (n_read == -1)
        {
          free(left_str);
          return (NULL);
        }
        else if (n_read == 0)
          break ;
        buffer[n_read] = '\0';
        if (!left_str)
          left_str = ft_strdup("");
        temp = left_str;
        left_str = ft_strjoin(temp, buffer);
        free(temp);
        temp = NULL;
        if (strchr(buffer, '\n'))
          break ;
    }
    return (left_str);
}

char *get_next_line(int fd)
{
      static char *left_str;
      char *buffer;
      char *line;
      
      buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
      if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
      {
        free(left_str);
        free(buffer);
        left_str = NULL;
        buffer = NULL;
        return (NULL);
      }
      if (!buffer)
        return (NULL);
      line = fill_buffer(fd, left_str, buffer);
      free(buffer);
      buffer = NULL;
      //left_str = stract_line(line);
      return (line);
}