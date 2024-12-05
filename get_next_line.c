/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aayad <aayad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 15:09:38 by aayad             #+#    #+#             */
/*   Updated: 2024/12/04 22:33:27 by aayad            ###   ########.fr       */
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
        temp = left_str;
        left_str = ft_strjoin(temp, buffer);
        free(temp);
        temp = NULL;
        if (strchr(buffer, '\n'))
          break ;
    }
    return (left_str);
}

char	*ft_get_line(char *left_str)
{
	int		i;
	char	*str;

	i = 0;
	if (!left_str[i])
		return (NULL);
	while (left_str[i] && left_str[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (left_str[i] && left_str[i] != '\n')
	{
		str[i] = left_str[i];
		i++;
	}
	if (left_str[i] == '\n')
	{
		str[i] = left_str[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_new_left_str(char *left_str)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (left_str[i] && left_str[i] != '\n')
		i++;
	if (!left_str[i])
	{
		free(left_str);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(left_str) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (left_str[i])
		str[j++] = left_str[i++];
	str[j] = '\0';
	free(left_str);
	return (str);
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
      left_str = fill_buffer(fd, left_str, buffer);
      free(buffer);
      buffer = NULL;
      if (!left_str)
        return (NULL);
      line = ft_get_line(left_str);
      left_str = ft_new_left_str(left_str);
      return (line);
}