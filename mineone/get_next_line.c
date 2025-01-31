/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Alejandro Ramos <your@email.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 08:25:32 by Alejandro Ram     #+#    #+#             */
/*   Updated: 2025/01/31 12:44:31 by Alejandro Ram    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*until(char *str, int index, char **n_line);
//static void	ft_putstr(char *str);
static int	scan_line(char *str);
static char *join_leftover(char *leftover, char *buffer);
static int str_len(char *str);

char	*get_next_line(int fd)
{
	static char	*leftover = NULL;
	char		*buffer;
	int			chars_read;
	int			line_index;
	char		*new_line = NULL;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
    while (1)
    {
        chars_read = read(fd, buffer, BUFFER_SIZE);
        if (chars_read <= 0)
        {
            if (buffer)
                free(buffer);
            if(leftover)
            {
                new_line = leftover;
                leftover = NULL;
                return (new_line);
            }
            return (NULL);
        }
        buffer[chars_read] = '\0';
        if (leftover)
        {
            char    *temp = join_leftover(leftover, buffer);
            buffer = temp;
            leftover = NULL;
        }
        line_index = scan_line(buffer);
        if (line_index >= 0)
        {
            leftover = until(buffer, line_index, &new_line);
            if (buffer)
                free(buffer);
            break ;
        }
        else
        {
            leftover = buffer;
            if (buffer)
                free(buffer);
            buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
            if (!buffer)
            {
                if (leftover)
                    free(leftover);
                return (NULL);
            }
        }
    }
  //  ft_putstr(new_line);
	return (new_line);
}

static char *join_leftover(char *leftover, char *buffer)
{
    char    *joined;
    int     len;
    int     buf_len;
    int     i;
    int     j;

    i = 0;
    j = 0;
    len = str_len(leftover);
    buf_len = str_len(buffer);
    joined = malloc((len + buf_len + 1) * sizeof(char));
    if (!joined)
        return (NULL);
    while (leftover[i] != '\0')
    {
        joined[i] = leftover[i];
        i++;
    }
    while (j < buf_len)
    {
        joined[i] = buffer[j];
        i++;
        j++;
    }
    joined[i] = '\0';
    if (leftover)
        free(leftover);
    if (buffer)
        free(buffer);
    return (joined);
}

static int str_len(char *str)
{
    int i;

    i = 0;
    if (str == NULL)
        return (0);
    while (str[i])
    {
        i++;
    }
    return (i);
}

static char	*until(char *str, int index, char **n_line)
{
	char	*leftover;
	int		i;
	int		j;

	*n_line = (char *)malloc((index + 2) * sizeof(char));
	if(!(*n_line))
    {
	    return (NULL);
    }
    i = 0;
	while (i <= index)
	{
		(*n_line)[i] = str[i];
		i++;
	}
	(*n_line)[i] = '\0';
	leftover = (char *)malloc((str_len(str) - index) * sizeof(char));
	if (!leftover)
	{
        if ((*n_line))
            free(*n_line);
		return (NULL);
	}
    j = 0;
	while (str[i] != '\0')
		leftover[j++] = str[i++];
	leftover[j] = '\0';
	return (leftover);
}

static int	scan_line(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
				return (i);
		i++;
	}
	return (-1);
}

//static void	ft_putstr(char *str)
//{
//		while (*str != '\0')
//		{
//				if (*str == '\n')
//						write(1, "\\n", 2);
//				else if (*str == '\0')
//						write(1, "\\0", 2);
//				else
//						write(1, str, 1);
//				str++;
//		}
//		if (*str == '\0')
//		 write(1, "\\0", 2);
//}
//
//int	main(void)
//{
//		int	fd;
//        char    *str;
//
//		fd = open("text.txt", O_RDONLY | O_CREAT);
//		str = get_next_line(fd);
//        free(str);
//		return (0);
//}
