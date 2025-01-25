/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 15:25:25 by aramos            #+#    #+#             */
/*   Updated: 2025/01/08 18:16:19 by aramos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*buffer;

  buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
  if (!buffer)
    return (NULL);
	read(fd, buffer, BUFFER_SIZE);
  buffer[BUFFER_SIZE] = "\0"
  printf("%s", buffer);
  return(buffer);
}

find_line(char *str)
{
  char  *start;
  char  *finish;
  char  *line;
  int   len;

  start = str;
  finish = str;
  while (finish)
  {
    if (*finish == '\n')
    {
      line = malloc()
    }
  }
}

int	main(void)
{
	int	fd;

	fd = open("test.txt", O_RDONLY);
	printf("fd of test.txt = %d\n", fd);
  get_next_line(fd);
	return (0);
}
