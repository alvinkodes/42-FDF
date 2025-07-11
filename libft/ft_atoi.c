/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akok <akok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 06:23:43 by akok              #+#    #+#             */
/*   Updated: 2025/06/07 13:13:57 by akok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
long	ft_atoi(const char *nptr)
{
	long	nb;
	int		sign;

	while (*nptr == ' ' || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	sign = 1;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			sign *= -1;
		nptr++;
	}
	if (!(*nptr >= '0' && *nptr <= '9'))
		return (0);
	nb = 0;
	while (*nptr >= '0' && *nptr <= '9')
	{
		nb = (nb * 10) + *nptr - '0';
		nptr++;
	}
	return (sign * nb);
}
