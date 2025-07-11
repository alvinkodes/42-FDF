/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akok <akok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 20:19:08 by akok              #+#    #+#             */
/*   Updated: 2025/05/20 20:35:51 by akok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*nlist;
	t_list	*new;

	if (!lst || !f || !del)
		return (NULL);
	new = NULL;
	nlist = new;
	while (lst)
	{
		new = ft_lstnew(f(lst->content));
		if (!new)
		{
			ft_lstclear(&nlist, del);
			return (NULL);
		}
		ft_lstadd_back(&nlist, new);
		lst = lst->next;
	}
	return (nlist);
}
