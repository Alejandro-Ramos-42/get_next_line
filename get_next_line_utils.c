/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 15:25:38 by aramos            #+#    #+#             */
/*   Updated: 2025/01/29 20:03:28 by aramos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <limits.h>
#include <string.h>
#include <stdint.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <stddef.h>

char	*ft_strdup(const char *s)
{
	char	*ptr;
	int		size_s;

	size_s = ft_strlen(s) + 1;
	if (s == NULL)
		return (NULL);
	ptr = (char *) ft_calloc(size_s, sizeof(char));
	if (ptr == NULL)
		return (NULL);
	ft_strlcpy(ptr, s, size_s);
	return (ptr);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	unsigned int	i;

	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (i < size - 1 && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (nmemb == 0 || size == 0)
		return (malloc(1));
	if (nmemb > (SIZE_MAX / size))
		return (NULL);
	ptr = malloc(nmemb * size);
	if (ptr == NULL)
		return (NULL);
	ft_memset(ptr, 0, nmemb * size);
	return (ptr);
}

void	*ft_memset(void *s, int c, size_t n)
{
	char	replace_by;
	void	*ptr;	

	ptr = s;
	replace_by = (unsigned char)c;
	while (n > 0)
	{
		*(unsigned char *)s = replace_by;
		n--;
		s++;
	}
	return (ptr);
}
