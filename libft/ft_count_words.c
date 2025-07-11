/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akok <akok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 14:17:24 by akok              #+#    #+#             */
/*   Updated: 2025/07/10 14:35:22 by akok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_sep(char c, char sep)
{
	return (c == sep || c == '\n');
}

int	ft_count_words(char const *s, char sep)
{
	int		count;
	size_t	i;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (!ft_is_sep(s[i], sep) && (i == 0 || ft_is_sep(s[i - 1], sep)))
			count++;
		i++;
	}
	return (count);
}
