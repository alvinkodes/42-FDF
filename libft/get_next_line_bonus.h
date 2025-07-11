/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akok <akok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 13:23:40 by akok              #+#    #+#             */
/*   Updated: 2025/06/13 11:55:52 by akok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE BUFSIZ
# endif

# ifndef MAX_FD
#  define MAX_FD 1024
# endif

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_list
{
	char			*content;
	size_t			len;
	struct s_list	*next;
}	t_list;

char	*get_next_line(int fd);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst, void (*del)(void *));
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(void *content);

#endif
