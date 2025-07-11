/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akok <akok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 14:30:26 by akok              #+#    #+#             */
/*   Updated: 2025/07/10 15:03:11 by akok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// put pixel on the image by calculating the position using pointer arithmetic
void	put_pixel(t_fdf *fdf, int x, int y, int color)
{
	t_img	*img;
	char	*dst;

	if (x < 0 || x >= WIN_WIDTH || y < 0 || y >= WIN_HEIGHT)
		return ;
	img = fdf->img;
	dst = img->addr + (y * img->ln_len + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

// p = d1 - d2
// p: decison parameter
// d1: distance between lower pixel and line
// d2: distance between higher pixel and line
// if p > 0, increase y or decrease y based on dy, else remain
// draw line slope < 1
void	bresenham_h(int dx, int dy, t_fdf *fdf)
{
	int		p;
	int		i;
	t_point	cur;

	cur = *(fdf->a);
	i = -1;
	p = 2 * abs(dy) - abs(dx);
	while (++i < abs(dx))
	{
		if (dx > 0)
			cur.x += 1;
		else
			cur.x -= 1;
		if (p < 0)
			p = p + 2 * abs(dy);
		else
		{
			if (dy > 0)
				cur.y += 1;
			else
				cur.y -= 1;
			p = p + 2 * abs(dy) - 2 * abs(dx);
		}
		put_pixel(fdf, cur.x, cur.y, set_color(cur.x, cur.y, fdf->a, fdf->b));
	}
}

// draw line slope >= 1
void	bresenham_v(int dx, int dy, t_fdf *fdf)
{
	int		p;
	int		i;
	t_point	cur;

	cur = *(fdf->a);
	i = -1;
	p = 2 * abs(dx) - abs(dy);
	while (++i < abs(dy))
	{
		if (dy > 0)
			cur.y += 1;
		else
			cur.y -= 1;
		if (p < 0)
			p = p + 2 * abs(dx);
		else
		{
			if (dx > 0)
				cur.x += 1;
			else
				cur.x -= 1;
			p = p + 2 * abs(dx) - 2 * abs(dy);
		}
		put_pixel(fdf, cur.x, cur.y, set_color(cur.x, cur.y, fdf->a, fdf->b));
	}
}

// determine if line slope is less or more than 1
void	draw_line(t_point *a, t_point *b, t_fdf *fdf)
{
	int		dx;
	int		dy;
	t_point	start;
	t_point	end;

	start = *a;
	end = *b;
	transform_coordinates(&start, &end, fdf);
	dx = end.x - start.x;
	dy = end.y - start.y;
	fdf->a = &start;
	fdf->b = &end;
	if (abs(dx) > abs(dy))
		bresenham_h(dx, dy, fdf);
	else
		bresenham_v(dx, dy, fdf);
}

// connecting the grid
void	draw_map(t_point **points, t_fdf *fdf)
{
	int		x;
	int		y;
	t_map	*map;

	map = fdf->map;
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (x < map->width - 1)
				draw_line(&points[y][x], &points[y][x + 1], fdf);
			if (y < map->height - 1)
				draw_line(&points[y][x], &points[y + 1][x], fdf);
			x++;
		}
		y++;
	}
}
