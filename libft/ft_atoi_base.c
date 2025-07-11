/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akok <akok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 10:37:25 by akok              #+#    #+#             */
/*   Updated: 2025/04/17 14:00:53 by akok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_base_len(char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
		i++;
	return (i);
}

int	ft_valid_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i] != '\0')
	{
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-'
			|| (base[i] >= 9 && base[i] <= 13)
			|| base[i] == ' ')
			return (0);
		i++;
	}
	return (1);
}

int	ft_get_base_index(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_base_to_dec(char *str, char *base)
{
	int	base_len;
	int	index_value;
	int	number;

	base_len = ft_base_len(base);
	index_value = ft_get_base_index(*str, base);
	number = 0;
	while (index_value != -1)
	{
		number = number * base_len + index_value;
		str++;
		index_value = ft_get_base_index(*str, base);
	}
	return (number);
}

int	ft_atoi_base(char *str, char *base)
{
	int	sign;
	int	sign_count;
	int	number;

	if (!ft_valid_base(base) || ft_base_len(base) < 2)
		return (0);
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	sign_count = 0;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign_count += 1;
		str++;
	}
	sign = 1;
	if (sign_count % 2 == 1)
		sign = -1;
	number = ft_base_to_dec(str, base);
	return (sign * number);
}
/*
#include <stdio.h>

int main(void)
{
    printf("Test 1\n");
    printf("42\n");
    printf("%d\n", ft_atoi_base("42", "0123456789"));

    printf("Test 2\n");
    printf("-42\n");
    printf("%d\n", ft_atoi_base("-42", "0123456789"));

    printf("Test 3\n");
    printf("255\n");
    printf("%d\n", ft_atoi_base("ff", "0123456789abcdef"));

    printf("Test 4\n");
    printf("0\n");
    printf("%d\n", ft_atoi_base("42", ""));

    printf("Test 5\n");
    printf("0\n");
    printf("%d\n", ft_atoi_base("42", "0"));

    printf("Test 6\n");
    printf("0\n");
    printf("%d\n", ft_atoi_base("42", "00123456789"));

    printf("Test 7\n");
    printf("0\n");
    printf("%d\n", ft_atoi_base("42", "+0123456789"));

    printf("Test 8\n");
    printf("0\n");
    printf("%d\n", ft_atoi_base("42", "012-3456789"));

    printf("Test 9\n");
    printf("0\n");
    printf("%d\n", ft_atoi_base("42", "01234 56789"));

    return 0;
}
*/
