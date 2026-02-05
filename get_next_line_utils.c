/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablodorn <ablodorn@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:49:10 by ablodorn          #+#    #+#             */
/*   Updated: 2024/11/20 15:49:11 by ablodorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	gnl_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*gnl_strchr(const char *s, int c)
{
	unsigned char	d;

	d = (unsigned char)c;
	while (*s)
	{
		if (*s == d)
			return ((char *)s);
		s++;
	}
	if (d == '\0')
		return ((char *)s);
	return (NULL);
}

char	*gnl_substr(char *s, size_t start, size_t len)
{
	size_t	sub_len;
	char	*sub;
	size_t	i;

	i = 0;
	if (!s || start >= gnl_strlen(s))
		return (gnl_strdup(""));
	if (gnl_strlen(s + start) < len)
		sub_len = gnl_strlen(s + start);
	else
		sub_len = len;
	sub = malloc(sub_len + 1);
	if (!sub)
		return (NULL);
	while (i < sub_len)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

char	*gnl_strdup(const char *src)
{
	char			*dest;
	size_t			i;

	i = 0;
	while (src[i])
		i++;
	dest = malloc((i + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*gnl_strjoin(char *s1, const char *s2)
{
	size_t	total;
	char	*new_str;
	int		i;
	int		j;

	i = 0;
	if (!s2)
		return (NULL);
	if (!s1)
		return (gnl_strdup(s2));
	total = gnl_strlen(s1) + gnl_strlen(s2);
	new_str = malloc(total + 1);
	if (!new_str)
		return (NULL);
	while (*s1)
		new_str[i++] = *s1++;
	j = 0;
	while (s2[j])
	{
		new_str[i + j] = s2[j];
		j++;
	}
	new_str[i + j] = '\0';
	return (new_str);
}
