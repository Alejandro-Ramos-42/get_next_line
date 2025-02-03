/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 18:25:55 by aramos            #+#    #+#             */
/*   Updated: 2025/02/03 18:30:16 by aramos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	int		fd;
	char	*str_returned;

	fd = open("test.txt", O_RDONLY);
	printf("%d", fd);
	str_returned = get_next_line(fd);
	printf("%s", str_returned);
	close(fd);
	return (0);
}
