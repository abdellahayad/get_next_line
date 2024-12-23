/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aayad <aayad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 14:39:43 by aayad             #+#    #+#             */
/*   Updated: 2024/12/19 14:48:52 by aayad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*fill_buffer(int fd, char *left_str)
{
	char		*buffer;
	ssize_t		n_read;

	buffer = (char *)malloc(BUFFER_SIZE + 1 * sizeof(char));
	if (!buffer)
		return (NULL);
	n_read = 1;
	while (!ft_strchr(left_str, '\n') && n_read != 0)
	{
		n_read = read(fd, buffer, BUFFER_SIZE);
		if (n_read == -1)
		{
			free(left_str);
			free(buffer);
			return (NULL);
		}
		buffer[n_read] = '\0';
		left_str = ft_strjoin(left_str, buffer);
	}
	free(buffer);
	if (left_str && !left_str[0] && n_read == 0)
		return (free(left_str), NULL);
	return (left_str);
}

char	*get_next_line(int fd)
{
	char			*line;
	static char		*left_str[OPEN_MAX];

	if (BUFFER_SIZE <= 0 || fd < 0 || fd >= OPEN_MAX || BUFFER_SIZE > INT_MAX)
		return (NULL);
	left_str[fd] = fill_buffer(fd, left_str[fd]);
	if (!left_str[fd])
		return (NULL);
	line = extract_line(left_str[fd]);
	if (!line)
		return (NULL);
	left_str[fd] = extract_rest(left_str[fd]);
	return (line);
}
