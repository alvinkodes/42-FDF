/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akok <akok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 13:17:24 by akok              #+#    #+#             */
/*   Updated: 2025/07/10 16:22:39 by akok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	iso_view(t_fdf *fdf)
{
	reset_view(fdf);
	fdf->map->is_iso = 1;
}

void	top_view(t_fdf *fdf)
{
	reset_view(fdf);
	fdf->map->is_iso = 0;
}

// radian 1.5708 ~= deg 90
void	front_view(t_fdf *fdf)
{
	fdf->map->alpha = 1.5708;
	fdf->map->thetha = 0.0;
	fdf->map->gamma = 0.0;
}

void	right_view(t_fdf *fdf)
{
	fdf->map->alpha = 1.5708;
	fdf->map->thetha = 1.5708;
	fdf->map->gamma = 0;
}

void	left_view(t_fdf *fdf)
{
	fdf->map->alpha = 1.5708;
	fdf->map->thetha = -1.5708;
	fdf->map->gamma = 0;
}
