/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akok <akok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 15:04:57 by akok              #+#    #+#             */
/*   Updated: 2025/07/10 18:14:37 by akok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// alpha: rotation angle around x-axis
// thetha: rotation angle around y-axis
// gamma: rotation angle around z-axis
// is_iso == 1, make isometric projection the default projection
void	init_map(t_map *map)
{
	map->height = 0;
	map->width = 0;
	map->zoom = 1;
	map->elevation = 1;
	map->offset_x = 0;
	map->offset_y = 0;
	map->is_iso = 1;
	map->alpha = 0.0;
	map->thetha = 0.0;
	map->gamma = 0.0;
	map->points = NULL;
}

// call mlx_init to establish a connection between client(program) and
// server(X11 system)
void	init_vars(t_vars *vars)
{
	vars->mlx = mlx_init();
	vars->mlx_win = mlx_new_window(vars->mlx, WIN_WIDTH, WIN_HEIGHT, "FDF");
}

// call mlx_get_data_addr to initialize the img data
void	init_img(t_vars *vars, t_img *img)
{
	img->img = mlx_new_image(vars->mlx, WIN_WIDTH, WIN_HEIGHT);
	img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->ln_len, &img->end);
}

void	init_fdf(t_fdf *fdf, t_map *map, t_vars *vars, t_img *img)
{
	fdf->map = map;
	fdf->vars = vars;
	fdf->img = img;
}
