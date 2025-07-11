/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akok <akok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 12:59:24 by akok              #+#    #+#             */
/*   Updated: 2025/07/11 09:29:06 by akok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include "libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <errno.h>
# include <stdint.h>
# include <math.h>
# include <X11/keysym.h>

# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080
# define ISO_COS 0.8660254f
# define ISO_SIN 0.5f

typedef struct s_vars
{
	void	*mlx;
	void	*mlx_win;
}	t_vars;

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
	int	color;
}	t_point;

typedef struct s_map
{
	int		height;
	int		width;
	int		zoom;
	int		offset_x;
	int		offset_y;
	int		elevation;
	int		is_iso;
	float	alpha;
	float	thetha;
	float	gamma;
	t_point	**points;
}	t_map;

typedef struct s_img
{
	void	*img;
	void	*addr;
	int		bpp;
	int		ln_len;
	int		end;
}	t_img;

typedef struct s_fdf
{
	t_vars	*vars;
	t_map	*map;
	t_img	*img;
	t_point	*a;
	t_point	*b;
}	t_fdf;

int		default_color(int z);
int		cleanup_and_exit(t_fdf *fdf);
int		handle_view(int keysym, t_fdf *fdf);
int		handle_offset(int keysym, t_fdf *fdf);
int		handle_rotation(int keysym, t_fdf *fdf);
int		handle_key_event(int keysym, t_fdf *fdf);
int		handle_elevation(int keysym, t_fdf *fdf);
int		set_color(int x, int y, t_point *a, t_point *b);
int		handle_mouse_event(int button, int x, int y, t_fdf *fdf);

void	gnl_flush(int fd);
void	render(t_fdf *fdf);
void	iso_view(t_fdf *fdf);
void	top_view(t_fdf *fdf);
void	init_map(t_map *map);
void	left_view(t_fdf *fdf);
void	front_view(t_fdf *fdf);
void	reset_view(t_fdf *fdf);
void	right_view(t_fdf *fdf);
void	init_vars(t_vars *vars);
void	free_points(t_point	**points);
void	parse_map(char *fn, t_map *map);
void	init_img(t_vars *vars, t_img *img);
void	draw_map(t_point **points, t_fdf *fdf);
void	error_exit(char *msg, t_map *map, int syserror);
void	transform_coordinates(t_point *a, t_point *b, t_fdf *fdf);
void	init_fdf(t_fdf *fdf, t_map *map, t_vars *vars, t_img *img);

#endif