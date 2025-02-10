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
#include <unistd.h>
#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*str_returned;

	fd = open("test.txt", O_RDONLY);
	str_returned = get_next_line(fd);
	printf("%s", str_returned);
	free(str_returned);
	str_returned = get_next_line(fd);
	printf("%s", str_returned);
	free(str_returned);
	str_returned = get_next_line(fd);
	printf("%s", str_returned);
	free(str_returned);
	close(fd);
	return (0);
}
