/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 18:21:05 by aramos            #+#    #+#             */
/*   Updated: 2025/02/10 19:51:16 by aramos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_create_node(t_list **current, t_list **start)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
	{
		ft_fclean(*start);
		return (0);
	}
	new_node -> next = NULL;
	if (*current == NULL)
	{
		*start = new_node;
		new_node -> node_count = 1;
	}
	else
	{
		(*current)-> next = new_node;
		(*start)-> node_count += 1;
	}
	*current = new_node;
	return (1);
}

static void	initiate_continue(char **new_line_index,
				t_list **start, t_list *current, ssize_t *copied)
{
	*new_line_index = NULL;
	*start = NULL;
	*copied = 1;
	if (current != NULL)
	{
		*start = current;
		*new_line_index = ft_strchr(current -> buffer, '\n');
	}
}

t_list	*divorce(t_list *current, char *new_line_index)
{
	t_list	*brand_new;
	int		i;

	if (!current || !new_line_index)
		return (NULL);
	brand_new = malloc(sizeof(t_list));
	if (!brand_new)
		return (NULL);
	brand_new -> next = NULL;
	i = 0;
	new_line_index++;
	while (new_line_index[i] != '\0')
	{
		(brand_new -> buffer)[i] = new_line_index[i];
		if (i == 0)
			new_line_index[i] = '\0';
		i++;
	}
	brand_new -> buffer[i] = '\0';
	return (brand_new);
}

char	*join_delete(t_list	*start)
{
	char	*final_string;
	t_list	*to_delete;
	int		i;
	int		j;
	int		str_len;

	to_delete = start;
	str_len = ft_lstlen(start);
	if (str_len <= 0)
		return (ft_fclean(to_delete));
	final_string = (char *)malloc(str_len + 1 * sizeof(char));
	if (!final_string)
		return (ft_fclean(to_delete));
	start = to_delete;
	i = 0;
	while (start != NULL && i < str_len)
	{
		j = 0;
		while ((start->buffer)[j] != '\0')
			final_string[i++] = (start)->buffer[j++];
		start = start->next;
	}
	final_string[i] = '\0';
	ft_fclean(to_delete);
	return (final_string);
}

char	*get_next_line(int fd)
{
	static t_list	*current = NULL;
	t_list			*start;
	char			*new_line_index;
	ssize_t			copied;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	initiate_continue(&new_line_index, &start, current, &copied);
	while (copied > 0 && new_line_index == NULL)
	{
		if (ft_create_node(&current, &start) == 0)
			return (NULL);
		copied = read(fd, current -> buffer, BUFFER_SIZE);
		if (copied < 0)
		{
			current = NULL;
			return (ft_fclean(start));
		}
		(current -> buffer)[copied] = '\0';
		new_line_index = ft_strchr(current -> buffer, '\n');
	}
	current = divorce(current, new_line_index);
	return (join_delete(start));
}
