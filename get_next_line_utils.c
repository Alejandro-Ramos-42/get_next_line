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

#include "get_next_line.h"

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

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	int		n;
	int		i;

	i = 0;
	n = nmemb * size;
	if (nmemb == 0 || size == 0)
		return (malloc(1));
	if (nmemb > (SIZE_MAX / size))
		return (NULL);
	ptr = malloc(nmemb * size);
	if (ptr == NULL)
		return (NULL);
	while (n > 0)
	{
		((unsigned char *)ptr)[i] = '\0';
		n--;
		i++;
	}
	return (ptr);
}

void	*ft_fclean(t_list *current)
{
	t_list	*tmp;

	while (current)
	{
		tmp = (current)->next;
		free(current);
		current = tmp;
	}
	return (NULL);
	current = NULL;
}
