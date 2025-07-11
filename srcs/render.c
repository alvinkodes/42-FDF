/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akok <akok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 13:16:13 by akok              #+#    #+#             */
/*   Updated: 2025/07/10 16:15:43 by akok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// rerender the image
// destroy the old image, create a new one, draw map on it then put the image
// on the window
void	render(t_fdf *fdf)
{
	t_img	*img;

	img = fdf->img;
	mlx_destroy_image(fdf->vars->mlx, img->img);
	img->img = mlx_new_image(fdf->vars->mlx, WIN_WIDTH, WIN_HEIGHT);
	img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->ln_len, &img->end);
	draw_map(fdf->map->points, fdf);
	mlx_put_image_to_window(fdf->vars->mlx, fdf->vars->mlx_win, img->img, 0, 0);
}

void	reset_view(t_fdf *fdf)
{
	fdf->map->alpha = 0.0;
	fdf->map->thetha = 0.0;
	fdf->map->gamma = 0.0;
}
