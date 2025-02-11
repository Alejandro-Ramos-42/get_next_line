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

	new_node = calloc(1, sizeof(t_list));
	if (!new_node)
		return ((long)ft_fclean(*start));
	new_node -> next = NULL;
	if (*current == NULL)
	{
		*start = new_node;
		new_node -> node_count = 1;
	}
	else
	{
		(*current)-> next = new_node;
		(*start)-> node_count = (*start)-> node_count + 1;
	}
	*current = new_node;
	return (1);
}

void	initiate_continue(char **new_line_index,
				t_list **start, t_list *current, ssize_t *copied)
{
	*new_line_index = NULL;
	*start = NULL;
	*copied = 1;
	if (current != NULL)
	{
		*start = current;
		*new_line_index = (ft_strchr(current -> buffer, '\n'));
	}
}

t_list	*divorce(t_list *current, char *new_line_index)
{
	t_list	*brand_new;
	int		i;

	if (!current || !new_line_index)
		return (NULL);
	i = 0;
	new_line_index++;
	if (*new_line_index == '\0')
		return (NULL);
	brand_new = calloc(1, sizeof(t_list));
	if (!brand_new)
		return (NULL);
	while (new_line_index[i] != '\0')
	{
		(brand_new -> buffer)[i] = new_line_index[i];
		i++;
	}
	brand_new -> buffer[i] = '\0';
	brand_new -> next = NULL;
	brand_new -> node_count = 1;
	return (brand_new);
}

char	*join_delete(t_list	**start)
{
	char	*final_string;
	t_list	*to_delete;
	int		i;
	int		j;
	int		str_len;

	i = 0;
	str_len = ((*start)->node_count) * BUFFER_SIZE;
	final_string = calloc((str_len + 1), sizeof(char));
	if (!final_string)
		return (NULL);
	while (*start)
	{
		j = 0;
		to_delete = *start;
		while ((*start)-> buffer[j] != '\0')
		{
			final_string[i++] = (*start)-> buffer[j];
			if ((*start)-> buffer[j] == '\n')
				break ;
			j++;
		}
		*start = (*start)-> next;
		free(to_delete);
		if (final_string[i - 1] == '\n')
			break ;
	}
	final_string[i] = '\0';
	return (final_string);
}

char	*get_next_line(int fd)
{
	static t_list	*current = NULL;
	t_list			*start;
	char			*new_line_index;
	ssize_t			copied;
	char			*line_to_return;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	initiate_continue(&new_line_index, &start, current, &copied);
	while (copied >= 1 && new_line_index == NULL)
	{
		ft_create_node(&current, &start);
		copied = read(fd, current -> buffer, BUFFER_SIZE);
//		if (current != NULL)
//			ft_putstr(current -> buffer);
		if (copied == 0)
		{
			break ;
		}
		if (copied < 0)
		{
			current = NULL;
			return (ft_fclean(start));
		}
		(current -> buffer)[copied] = '\0';
		new_line_index = ft_strchr(current -> buffer, '\n');
	}
	current = divorce(current, new_line_index);
	line_to_return = join_delete(&start);
	return (line_to_return);
}
