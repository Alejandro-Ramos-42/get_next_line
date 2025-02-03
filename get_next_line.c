/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 18:21:05 by aramos            #+#    #+#             */
/*   Updated: 2025/02/03 19:50:38 by aramos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_create_node(t_list **current, t_list **start)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node -> next = NULL;
	if (*current == NULL)
		*start = new_node;
	else
		*current -> next = new_node;
	*current = new_node;
	return (0);

}

char	*get_next_line(fd)
{
	static t_list	*current = NULL;
	t_list			*start;
	char			*new_line_index;
	ssize_t			copied;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (1)
	{
		ft_create_node(&current, &start);
		copied = read(fd, current -> buffer, BUFFER_SIZE);
		if (copied < 0)
		{
			current = NULL;
			return (NULL);
		}
		(current -> buffer)[copied] = '\0';
		new_line_index = ft_strchr(current -> buffer, '\n');
	}
	current = ft_
}
