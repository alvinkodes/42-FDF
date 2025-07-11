/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akok <akok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 13:09:15 by akok              #+#    #+#             */
/*   Updated: 2025/07/07 15:06:57 by akok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int ac, char **av)
{
	t_map	map;
	t_vars	vars;
	t_img	img;
	t_fdf	fdf;

	if (ac != 2)
		error_exit("fdf: program takes 1 .fdf file as arguement.", NULL, 0);
	init_map(&map);
	parse_map(av[1], &map);
	init_vars(&vars);
	init_img(&vars, &img);
	init_fdf(&fdf, &map, &vars, &img);
	draw_map(map.points, &fdf);
	mlx_put_image_to_window(vars.mlx, vars.mlx_win, img.img, 0, 0);
	mlx_hook(vars.mlx_win, 2, 1L << 0, handle_key_event, &fdf);
	mlx_mouse_hook(vars.mlx_win, handle_mouse_event, &fdf);
	mlx_hook(vars.mlx_win, 17, 0, cleanup_and_exit, &fdf);
	mlx_loop(vars.mlx);
	return (0);
}
