/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablodorn <ablodorn@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:48:56 by ablodorn          #+#    #+#             */
/*   Updated: 2024/11/20 15:49:00 by ablodorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

char			*get_next_line(int fd);
char			*gnl_strchr(const char *s, int c);
char			*gnl_substr(char *s, size_t start, size_t len);
char			*gnl_strdup(const char *src);
char			*gnl_strjoin(char *s1, const char *s2);
size_t	gnl_strlen(const char *s);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

#endif