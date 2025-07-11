/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akok <akok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 13:33:50 by akok              #+#    #+#             */
/*   Updated: 2025/07/10 17:22:09 by akok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static float	get_ratio(float start, float end, float p);
static float	interp(int x, int y, t_point *a, t_point *b);

// c0 stores the color info of point a
// c1 stores the color info of point b
// extract rgb values from color a and color b
// calculate how far (x,y) is between point a and point b
// calculate the color of pixel (x,y)
// combine the RGBs value back to an int
int	set_color(int x, int y, t_point *a, t_point *b)
{
	unsigned char	c0[3];
	unsigned char	c1[3];
	int				color;
	float			ratio;

	c0[0] = (a->color >> 16) & 0xFF;
	c0[1] = (a->color >> 8) & 0xFF;
	c0[2] = a->color & 0xFF;
	c1[0] = (b->color >> 16) & 0xFF;
	c1[1] = (b->color >> 8) & 0xFF;
	c1[2] = b->color & 0xFF;
	ratio = interp(x, y, a, b);
	color = ((int)(c0[0] + (c1[0] - c0[0]) * ratio) << 16
			| (int)(c0[1] + (c1[1] - c0[1]) * ratio) << 8
			| (int)(c0[2] + (c1[2] - c0[2]) * ratio));
	return (color);
}

// calculate how far p is between start and end
static float	get_ratio(float start, float end, float p)
{
	if (start != end)
		return ((p - start) / (end - start));
	return (0);
}

// linear color interpolation
// decide whether to interpolate using x-axis or y-axis
// get clear ratio from 0.0 to 1,0, smoother transiton
static float	interp(int x, int y, t_point *a, t_point *b)
{
	int		dx;
	int		dy;
	float	ratio;

	dx = b->x - a->x;
	dy = b->y - a->y;
	if (abs(dx) > abs(dy))
		ratio = get_ratio(a->x, b->x, x);
	else
		ratio = get_ratio(a->y, b->y, y);
	return (ratio);
}
