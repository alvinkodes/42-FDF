/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printlst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: username <your@email.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 11:17:21 by username          #+#    #+#             */
/*   Updated: 2025/06/06 11:23:14 by username         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	print_int(void *data);
void	print_str(void *data);
void	print_char(void *data);

void	ft_printlst(t_list *lst, void (*f)(void *))
{
	while (lst)
	{
		f(lst->content);
		ft_putchar_fd('\n', 1);
		lst = lst->next;
	}
}

void	print_int(void *data)
{
	ft_putnbr_fd((int)(intptr_t)data, 1);
}

void	print_str(void *data)
{
	ft_putstr_fd((char *)data, 1);
}

void	print_char(void *data)
{
	ft_putchar_fd((char)(intptr_t)data, 1);
}
