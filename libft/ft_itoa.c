/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akok <akok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 17:07:30 by akok              #+#    #+#             */
/*   Updated: 2025/05/20 17:33:06 by akok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static size_t	ft_get_size(int n)
{
	long	ln;
	size_t	size;

	if (n == 0)
		return (1);
	ln = n;
	size = 0;
	if (ln < 0)
		size++;
	while (n)
	{
		size++;
		n /= 10;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	char	*mem;
	long	ln;
	size_t	size;

	size = ft_get_size(n);
	mem = (char *)malloc(size + 1);
	if (!mem)
		return (NULL);
	if (n == 0)
		mem[0] = '0';
	ln = n;
	if (ln < 0)
	{
		mem[0] = '-';
		ln = -ln;
	}
	mem[size] = '\0';
	while (ln)
	{
		mem[--size] = (ln % 10) + '0';
		ln /= 10;
	}
	return (mem);
}
