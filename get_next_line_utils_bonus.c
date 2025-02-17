/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 18:21:37 by aramos            #+#    #+#             */
/*   Updated: 2025/02/10 19:18:55 by aramos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strchr(const char *s, int c)
{
	if (s == NULL || c < 0)
		return (NULL);
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == '\0' && c == '\0')
		return ((char *)s);
	return (NULL);
}

void	*ft_fclean(t_list *start)
{
	t_list	*temp;

	while (start)
	{
		temp = (start)->next;
		free(start);
		start = temp;
	}
	start = NULL;
	return (NULL);
}

int	ft_final_len(t_list *lst)
{
	int	size;

	size = 0;
	while (lst)
	{
		size += ft_strlen(lst->buffer);
		lst = lst -> next;
	}
	return (size);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
