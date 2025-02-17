/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 18:21:26 by aramos            #+#    #+#             */
/*   Updated: 2025/02/10 19:22:45 by aramos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>

typedef struct s_list
{
	char			buffer[BUFFER_SIZE + 1];
	struct s_list	*next;
	int				fd;
}	t_list;

char	*get_next_line(int fd);
char	*ft_strchr(const char *s, int c);
void	*ft_calloc(size_t nmemb, size_t size);
void	*ft_fclean(t_list *current);
void	ft_putstr(char *str);
int		ft_final_len(t_list *lst);
int		ft_strlen(char *str);
t_list	*find_fd(t_list **current, int fd);
#endif
