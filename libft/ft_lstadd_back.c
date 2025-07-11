/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akok <akok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 19:55:56 by akok              #+#    #+#             */
/*   Updated: 2025/05/20 19:58:58 by akok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *node)
{
	t_list	*last;

	last = ft_lstlast(*lst);
	if (!last)
		*lst = node;
	else
		last->next = node;
}
