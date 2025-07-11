/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akok <akok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 13:13:35 by akok              #+#    #+#             */
/*   Updated: 2025/07/10 19:51:30 by akok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// print out the error message then exit
void	error_exit(char *msg, t_map *map, int syserror)
{
	if (syserror)
		perror(msg);
	else
		ft_putendl_fd(msg, 2);
	if (map)
		free_points(map->points);
	exit(EXIT_FAILURE);
}

void	free_points(t_point	**points)
{
	int	i;

	i = 0;
	while (points[i])
		free(points[i++]);
	free(points);
}

// set the default color if no color is given
int	default_color(int z)
{
	if (z <= 0)
		return (0x264653);
	else if (z <= 10)
		return (0x2A9D8F);
	else if (z <= 25)
		return (0xE9C46A);
	else if (z <= 40)
		return (0xF4A261);
	else
		return (0xE76F51);
}

// destory image, window and display in order
// free mlx ptr to free another allocated struct
int	cleanup_and_exit(t_fdf *fdf)
{
	mlx_destroy_image(fdf->vars->mlx, fdf->img->img);
	mlx_destroy_window(fdf->vars->mlx, fdf->vars->mlx_win);
	mlx_destroy_display(fdf->vars->mlx);
	free(fdf->vars->mlx);
	free_points(fdf->map->points);
	exit(EXIT_SUCCESS);
}

void	gnl_flush(int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}
