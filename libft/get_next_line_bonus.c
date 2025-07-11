/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akok <akok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 13:22:49 by akok              #+#    #+#             */
/*   Updated: 2025/05/24 13:22:50 by akok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static int	got_new_line(t_list *lst)
{
	size_t	i;
	t_list	*last;

	last = ft_lstlast(lst);
	if (last == NULL)
		return (0);
	i = 0;
	while (last->content[i])
	{
		if (last->content[i] == '\n')
		{
			last->len = ++i;
			return (1);
		}
		i++;
	}
	last->len = i;
	return (0);
}

static void	read_line(int fd, t_list **lst)
{
	t_list	*new_node;
	ssize_t	b_read;

	while (!got_new_line(*lst))
	{
		new_node = ft_lstnew(NULL);
		new_node->content = (char *)malloc(BUFFER_SIZE + 1);
		if (!new_node->content)
		{
			ft_lstclear(lst, free);
			return ;
		}
		b_read = read(fd, new_node->content, BUFFER_SIZE);
		if (b_read == 0 || b_read == -1)
		{
			ft_lstdelone(new_node, free);
			return ;
		}
		new_node->content[b_read] = '\0';
		ft_lstadd_back(lst, new_node);
	}
}

static void	return_line(t_list *lst, char **line)
{
	size_t	i;
	size_t	tot_len;
	t_list	*cur;

	tot_len = 0;
	cur = lst;
	while (cur)
	{
		tot_len += cur->len;
		cur = cur->next;
	}
	if (!tot_len)
		return ;
	*line = (char *)malloc(tot_len + 1);
	if (!*line)
		return ;
	tot_len = 0;
	while (lst && lst->content)
	{
		i = 0;
		while (lst->content[i] && i < lst->len)
			(*line)[tot_len++] = lst->content[i++];
		lst = lst->next;
	}
	(*line)[tot_len] = '\0';
}

static void	refactor_line(t_list **lst)
{
	size_t	i;
	size_t	start;
	t_list	*last;
	t_list	*new_node;
	char	*nl_content;

	last = ft_lstlast(*lst);
	if (last == NULL)
		return ;
	nl_content = last->content;
	start = last->len;
	last->content = NULL;
	ft_lstclear(lst, free);
	i = 0;
	if (nl_content[start])
	{
		while (nl_content[start])
			nl_content[i++] = nl_content[start++];
		nl_content[i] = '\0';
		new_node = ft_lstnew(nl_content);
		ft_lstadd_back(lst, new_node);
	}
	else
		free(nl_content);
}

char	*get_next_line(int fd)
{
	static t_list	*lst[MAX_FD];
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	read_line(fd, &lst[fd]);
	if (!lst[fd])
		return (NULL);
	return_line(lst[fd], &line);
	if (!line)
		return (NULL);
	refactor_line(&lst[fd]);
	return (line);
}
