/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akok <akok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 13:37:44 by akok              #+#    #+#             */
/*   Updated: 2025/07/11 09:46:51 by akok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	isometric(int *x, int *y, int z);
static void	rotate_x(t_point *a, t_point *b, float alpha);
static void	rotate_y(t_point *a, t_point *b, float thetha);
static void	rotate_z(t_point *a, t_point *b, float gamma);

// transfrom the coordinates
// zoom: the size of map
// rotate: rotate coordinates on x,y,z axes
// apply isometric formula
// move map to the center of screen then apply offset
void	transform_coordinates(t_point *a, t_point *b, t_fdf *fdf)
{
	a->x *= fdf->map->zoom;
	a->y *= fdf->map->zoom;
	if (a->z)
		a->z *= fdf->map->elevation;
	b->x *= fdf->map->zoom;
	b->y *= fdf->map->zoom;
	if (b->z)
		b->z *= fdf->map->elevation;
	rotate_x(a, b, fdf->map->alpha);
	rotate_y(a, b, fdf->map->thetha);
	rotate_z(a, b, fdf->map->gamma);
	if (fdf->map->is_iso)
	{
		isometric(&a->x, &a->y, a->z);
		isometric(&b->x, &b->y, b->z);
	}
	a->x += WIN_WIDTH / 2 + fdf->map->offset_x;
	b->x += WIN_WIDTH / 2 + fdf->map->offset_x;
	a->y += WIN_HEIGHT / 2 + fdf->map->offset_y;
	b->y += WIN_HEIGHT / 2 + fdf->map->offset_y;
}

// isometric projection formula
static void	isometric(int *x, int *y, int z)
{
	int	tmp;

	tmp = *x;
	*x = (tmp - *y) * ISO_COS;
	*y = (tmp + *y) * ISO_SIN - z;
}

static void	rotate_x(t_point *a, t_point *b, float alpha)
{
	int		tmp_a;
	int		tmp_b;
	float	cos_a;
	float	sin_a;

	cos_a = cos(alpha);
	sin_a = sin(alpha);
	tmp_a = a->y;
	a->y = tmp_a * cos_a - a->z * sin_a;
	a->z = tmp_a * sin_a + a->z * cos_a;
	tmp_b = b->y;
	b->y = tmp_b * cos_a - b->z * sin_a;
	b->z = tmp_b * sin_a + b->z * cos_a;
}

static void	rotate_y(t_point *a, t_point *b, float thetha)
{
	int		tmp_a;
	int		tmp_b;
	float	cos_t;
	float	sin_t;

	cos_t = cos(thetha);
	sin_t = sin(thetha);
	tmp_a = a->x;
	a->x = tmp_a * cos_t + a->z * sin_t;
	a->z = a->z * cos_t - tmp_a * sin_t;
	tmp_b = b->x;
	b->x = tmp_b * cos_t + b->z * sin_t;
	b->z = b->z * cos_t - tmp_b * sin_t;
}

static void	rotate_z(t_point *a, t_point *b, float gamma)
{
	int		tmp_a;
	int		tmp_b;
	float	cos_g;
	float	sin_g;

	cos_g = cos(gamma);
	sin_g = sin(gamma);
	tmp_a = a->x;
	a->x = tmp_a * cos_g - a->y * sin_g;
	a->y = tmp_a * sin_g + a->y * cos_g;
	tmp_b = b->x;
	b->x = tmp_b * cos_g - b->y * sin_g;
	b->y = tmp_b * sin_g + b->y * cos_g;
}
