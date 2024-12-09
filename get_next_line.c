/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aayad <aayad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 15:09:38 by aayad             #+#    #+#             */
/*   Updated: 2024/12/08 20:41:28 by aayad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	free_that(char *s)
{
	if (s)
	{
		free(s);
		s = NULL;
	}
}

static char	*fill_buffer(int fd, char *left_str)
{
	char		*buffer;
	ssize_t		n_read;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	n_read = 1;
	while (!ft_strchr(left_str, '\n') && n_read != 0)
	{
		n_read = read(fd, buffer, BUFFER_SIZE);
		if (n_read == -1)
		{
			free_that(left_str);
			free_that(buffer);
			return (NULL);
		}
		buffer[n_read] = '\0';
		left_str = ft_strjoin(left_str, buffer);
	}
	free(buffer);
	if (left_str && !left_str[0] && n_read == 0)
		return (free_that(left_str), NULL);
	return (left_str);
}

char	*get_next_line(int fd)
{
	char			*line;
	static char		*left_str;

	if (BUFFER_SIZE <= 0 || fd < 0 || BUFFER_SIZE >= 2147483647)
		return (NULL);
	left_str = fill_buffer(fd, left_str);
	if (!left_str)
		return (NULL);
	line = extract_line(left_str);
	if (!line)
		return (NULL);
	left_str = extract_rest(left_str);
	return (line);
}
