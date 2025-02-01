/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 15:25:25 by aramos            #+#    #+#             */
/*   Updated: 2025/02/01 21:51:03 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <limits.h>
#include <string.h>
#include <stdint.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <stddef.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	size_t	len1;
	size_t	len2;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	result = (char *)malloc((len1 + len2 + 1) * sizeof(char));
	if (!result)
		return (NULL);
	ft_strlcpy(result, s1, len1 + 1);
	ft_strlcpy(result + len1, s2, len2 + 1);
	return (result);
}

int	search_line(char *str)
{
	int	i;

	if(!str)
		return(-1);
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*extract_line(char **leftover, char *buffer, int newline_i)
{
	char	*line;
	int		i;

	i = 0;
	line = (char *)malloc(newline_i + 2);
	if (!line)
		return (NULL);
	while (i <= newline_i)
	{
		line[i] = buffer[i];
		i++;
	}
	line[i] = '\0';
	if (buffer[newline_i + 1] == '\0')
		*leftover = NULL;
	else
		*leftover = ft_strdup(buffer + newline_i + 1);
	free(buffer);
	return (line);
}

char	*read_from_fd(int fd, char *leftover)
{
	char	*buffer;
	int		chars_read;
	char	*temp;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	if (read(fd, buffer, 0) < 0)
	{
		free(buffer);
		return (NULL);
	}
	chars_read = read(fd, buffer, BUFFER_SIZE);
	if (chars_read <= 0)
	{
		free(buffer);
		return (leftover);
	}
	buffer[chars_read] = '\0';
	if (leftover)
	{
		temp = ft_strjoin(leftover, buffer);
		free(leftover);
		free(buffer);
		return (temp);
	}
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*leftover = NULL;
	int			newline_i;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (leftover)
	{
		newline_i = search_line(leftover);
		if (newline_i >= 0)
			return (extract_line(&leftover, leftover, newline_i));
	}
	leftover = read_from_fd(fd, leftover);
	if (!leftover)
		return(NULL);
	newline_i = search_line(leftover);
	if (newline_i >= 0)
		return (extract_line(&leftover, leftover, newline_i));
	return (leftover);
}
