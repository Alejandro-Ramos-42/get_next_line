/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 17:18:31 by aramos            #+#    #+#             */
/*   Updated: 2025/01/30 18:18:40 by aramos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*temp;
	int		chars_read;
	int		line_i;
	char	*array;
	static int		i;

	i = 0;
	if (fd < 0 || BUFFER_SIZE == 0 || read(fd, &temp, 0) < 0)
		return (NULL);
	temp = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));//6
	chars_read = read(fd, temp, BUFFER_SIZE);//temp=qwert, chars_read=5
	temp[chars_read] = '\0';//quert\0
	line_i = check_if_line(temp);//-1
	if (line_i < 0)
	{
		array[i] = temp;
		get_next_line(fd);
		i++;
	}
	else
	cut_temp(line_i, temp);
}

char	*cut_temp(int index, char *str)
{
	char	*first;
	char	*until_line;
	int		i;

	i = 0;
	first = str;
	until_line = (char *)malloc((index + 2) * sizeof(char));
	while (index < 0)
	{
		until_line[i] = str[i];
		i++;
		index--;
	}
	until_line[i] = '\n';
	until_line[i++] = '\0';
	return (until_line);
}

int	check_if_line(char *str)
{
	int	i;

	i = 0;
	while(str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int	main(void)
{
	int		fd;
	char	*line;

	fd = open ("test.txt", O_RDONLY);//3
	line = get_next_line(fd);
	printf("%s", line);
	close(fd);
	return (0);
}
