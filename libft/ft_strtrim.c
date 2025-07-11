/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akok <akok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 11:35:39 by akok              #+#    #+#             */
/*   Updated: 2025/05/20 12:08:09 by akok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_is_set(char c, char const *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*mem;
	size_t	start;
	size_t	end;
	size_t	i;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && ft_is_set(s1[start], set))
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_is_set(s1[end - 1], set))
		end--;
	mem = (char *)malloc(end - start + 1);
	if (!mem)
		return (NULL);
	i = 0;
	while (start + i < end)
	{
		mem[i] = s1[start + i];
		i++;
	}
	mem[i] = '\0';
	return (mem);
}
