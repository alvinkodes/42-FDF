/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akok <akok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 17:34:47 by akok              #+#    #+#             */
/*   Updated: 2025/05/20 17:38:56 by akok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*mem;
	size_t			size;
	unsigned int	i;

	if (!s || !f)
		return (NULL);
	size = ft_strlen(s);
	mem = (char *)malloc(size + 1);
	if (!mem)
		return (NULL);
	i = 0;
	while (s[i])
	{
		mem[i] = f(i, s[i]);
		i++;
	}
	mem[i] = '\0';
	return (mem);
}
