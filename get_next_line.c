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

search_line(char *buffer)
{
  s_list  *new_node;

  while(buffer)
  {
    while (*buffer != '\n')
    {
      *new_node -> content = *buffer;
    }
  }
}

char	*get_next_line(int fd)
{
	char  *buffer;
  int   chars_read;

  buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));//6
  if (!buffer)
    return (NULL);
	chars_read = read(fd, buffer, BUFFER_SIZE);//5
  buffer[BUFFER_SIZE] = '\0';//buffer = "Hello\0"
  printf("%s", buffer);
  return(buffer);
}

int	main(void)
{
	int	  fd;
  char  *buffer;

	fd = open("test.txt", O_RDONLY);
  buffer = get_next_line(fd);
  free(buffer);
	return (0);
}
