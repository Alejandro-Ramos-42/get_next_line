/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 15:25:25 by aramos            #+#    #+#             */
/*   Updated: 2025/01/29 20:19:40 by aramos           ###   ########.fr       */
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

int	search_line(char *str)
{
	int	i;

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
	*leftover = ft_strdup(buffer + newline_i + 1);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*leftover = NULL;
	char		*buffer;
	int			newline_i;
	int			chars_read;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	if (leftover)
	{
		ft_strlcpy(buffer, leftover, (BUFFER_SIZE + 1));
		free(leftover);
		leftover = NULL;
	}
	else
	{
		chars_read = read(fd, buffer, BUFFER_SIZE);
		if (chars_read <= 0)
		{
			free(buffer);
			return (NULL);
		}
		buffer[chars_read] = '\0';
	}
	newline_i = search_line(buffer);
	if (newline_i >= 0)
		return (extract_line(&leftover, buffer, newline_i));
	return (buffer);
}
//
//int	main(void)
//{
//	int		fd;
//	char	*line;
//
//	fd = open("test.txt", O_RDONLY);
//	if (fd < 0)
//		return (1);
//	while ((line = get_next_line(fd)))
//	{
//		printf("%s", line);
//		free(line);
//	}
//	close(fd);
//	return (0);
//}
