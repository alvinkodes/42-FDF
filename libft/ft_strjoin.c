/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akok <akok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 11:20:03 by akok              #+#    #+#             */
/*   Updated: 2025/05/20 11:34:21 by akok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static char	*ft_strcat(char *dst, const char *src)
{
	size_t	i;
	size_t	dst_len;

	dst_len = 0;
	while (dst[dst_len])
		dst_len++;
	i = 0;
	while (src[i])
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*mem;
	size_t	px_len;
	size_t	sx_len;

	if (!s1 || !s2)
		return (NULL);
	px_len = ft_strlen(s1);
	sx_len = ft_strlen(s2);
	mem = (char *)ft_calloc(px_len + sx_len + 1, sizeof(char));
	if (!mem)
		return (NULL);
	ft_strcat(mem, s1);
	ft_strcat(mem, s2);
	return (mem);
}
