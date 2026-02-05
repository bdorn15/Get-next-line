/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablodorn <ablodorn@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:49:04 by ablodorn          #+#    #+#             */
/*   Updated: 2024/11/21 13:52:15 by ablodorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*gnl_free(char **s1, char *s2)
{
	free(*s1);
	*s1 = NULL;
	free(s2);
	return (NULL);
}

static char	*gnl_newline(char **current)
{
	char	*line;
	char	*tmp;
	int		i;

	i = 0;
	if (!(*current) || gnl_strlen(*current) == 0)
		return (NULL);
	while ((*current)[i] && (*current)[i] != '\n')
		i++;
	if ((*current)[i] == '\n')
	{
		line = gnl_substr(*current, 0, i + 1);
		if (!line)
            return NULL;
		tmp = gnl_strdup(*current + i + 1);
		if (!tmp)
            return (free(line), NULL);
	}
	else
	{
		line = gnl_substr(*current, 0, i);
		if (!line)
            return NULL;
		tmp = NULL;
	}
	free(*current);
	*current = tmp;
	return (line);
}

static int load_buffer(char **current, char *buffer, int fd)
{
    ssize_t		bytes_read;
	char		*tmp;

    bytes_read = 1;
	while (bytes_read > 0)
	{
        bytes_read = read(fd, buffer, BUFFER_SIZE);
        if (bytes_read > 0)
        {
		    buffer[bytes_read] = '\0';
		    tmp = gnl_strjoin(*current, buffer);
		    if (!tmp)
			    return (0);
			free(*current);
		    *current = tmp;
		    if (gnl_strchr(*current, '\n'))
			    break ;
        }
	}
	if (bytes_read < 0)
		return (0);
    return (1);
}

char	*get_next_line(int fd)
{
	static char	*current;
	char		*buffer;
	char		*line;
    int         x;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if(!buffer)
		return (NULL);
    x = load_buffer(&current, buffer, fd);
    if (x == 0)
		return (gnl_free(&current, buffer));	
	line = gnl_newline(&current);
	if (!line)
		return (gnl_free(&current, buffer));
	free(buffer);
	return (line);
}
