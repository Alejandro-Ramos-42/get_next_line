/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 18:21:26 by aramos            #+#    #+#             */
/*   Updated: 2025/02/03 19:06:14 by aramos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

#include <stdlib.h>
#include <unistd.h>

typedef struct s_list
{
	char	buffer[BUFFER_SIZE + 1];
	struct s_list	*next;
}	t_list;

char	*get_next_line(fd);
char	*ft_strchr(const char *s, int c);
#endif
