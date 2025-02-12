/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 18:25:55 by aramos            #+#    #+#             */
/*   Updated: 2025/02/10 18:59:47 by aramos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

//void  ft_putstr(char *str)
//{
//  int i;
//
//  i =0;
//  while (str[i])
//  {
//    if (str[i] == '\n')
//    {
//      write (1, &str[i], 1);
//    }
//    else
//      write(1, &str[i], 1);
//    i++;
//  }
//}

int	main(void)
{
	int		fd;

  fd = open("test.txt", O_RDONLY);
  printf("%s", get_next_line(fd));
  printf("FD: %d", fd);
	close(fd);
	return (0);
}
