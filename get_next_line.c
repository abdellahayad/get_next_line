/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aayad <aayad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 15:09:38 by aayad             #+#    #+#             */
/*   Updated: 2024/12/03 10:07:45 by aayad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
        temp = ft_strjoin(left_str, buffer);
        free(left_str);
        left_str = temp;
        if (ft_strchr(buffer, '\n'))
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
      return (line);
}