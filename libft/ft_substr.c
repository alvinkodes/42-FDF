/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akok <akok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 10:58:12 by akok              #+#    #+#             */
/*   Updated: 2025/05/20 11:18:35 by akok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	s_len;
	size_t	sub_len;
	char	*mem;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	sub_len = s_len - start;
	if (sub_len > len)
		sub_len = len;
	mem = (char *)malloc(sub_len + 1);
	if (!mem)
		return (NULL);
	i = 0;
	while (i < sub_len)
	{
		mem[i] = s[start + i];
		i++;
	}
	mem[i] = '\0';
	return (mem);
}
