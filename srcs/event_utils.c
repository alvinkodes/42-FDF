/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akok <akok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 13:20:53 by akok              #+#    #+#             */
/*   Updated: 2025/07/10 19:58:15 by akok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	handle_view(int keysym, t_fdf *fdf)
{
	if (keysym == XK_0)
		reset_view(fdf);
	else if (keysym == XK_1)
		iso_view(fdf);
	else if (keysym == XK_2)
		top_view(fdf);
	else if (keysym == XK_3 && !fdf->map->is_iso)
		front_view(fdf);
	else if (keysym == XK_4 && !fdf->map->is_iso)
		right_view(fdf);
	else if (keysym == XK_5 && !fdf->map->is_iso)
		left_view(fdf);
	else
		return (0);
	return (1);
}

int	handle_offset(int keysym, t_fdf *fdf)
{
	if (keysym == XK_Up)
		fdf->map->offset_y += 10;
	else if (keysym == XK_Down)
		fdf->map->offset_y -= 10;
	else if (keysym == XK_Left)
		fdf->map->offset_x += 10;
	else if (keysym == XK_Right)
		fdf->map->offset_x -= 10;
	else
		return (0);
	return (1);
}

int	handle_elevation(int keysym, t_fdf *fdf)
{
	if (keysym == XK_e)
		fdf->map->elevation += 1;
	else if (keysym == XK_q)
		fdf->map->elevation -= 1;
	else
		return (0);
	return (1);
}

int	handle_rotation(int keysym, t_fdf *fdf)
{
	if (keysym == XK_a)
		fdf->map->alpha += 0.1;
	else if (keysym == XK_s)
		fdf->map->thetha += 0.1;
	else if (keysym == XK_d)
		fdf->map->gamma += 0.1;
	else if (keysym == XK_z)
		fdf->map->alpha -= 0.1;
	else if (keysym == XK_x)
		fdf->map->thetha -= 0.1;
	else if (keysym == XK_c)
		fdf->map->gamma -= 0.1;
	else
		return (0);
	return (1);
}
