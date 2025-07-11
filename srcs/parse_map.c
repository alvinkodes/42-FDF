/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akok <akok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 10:04:16 by akok              #+#    #+#             */
/*   Updated: 2025/07/10 16:13:01 by akok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		set_height_and_width(char *fn, t_map *map);
static t_point	**extract_points(char *fn, t_map *map);

void	parse_map(char *fn, t_map *map)
{
	set_height_and_width(fn, map);
	map->points = extract_points(fn, map);
}

// check if line len equals to map width
static int	check_width(char *line, int map_width)
{
	int	width;

	width = ft_count_words(line, ' ');
	free(line);
	return (width == map_width);
}

// set the height and width of the map
// if the map is not retangular, flush gnl,
// exit and print error msg
static void	set_height_and_width(char *fn, t_map *map)
{
	int		fd;
	int		height;
	char	*line;

	fd = open(fn, O_RDONLY);
	if (fd < 0)
		error_exit("fdf: open error", NULL, 1);
	line = get_next_line(fd);
	if (line == NULL)
		error_exit("fdf: empty file", NULL, 0);
	map->width = ft_count_words(line, ' ');
	height = 0;
	while (line)
	{
		if (!check_width(line, map->width))
		{
			gnl_flush(fd);
			error_exit("fdf: map should be rectangular", NULL, 0);
		}
		height++;
		line = get_next_line(fd);
	}
	close(fd);
	map->height = height;
}

// get points coordinates x,y,z. If color is given, parse it,
// else set default colors
static void	fill_points(char *line, t_point **points, t_map *map, int row)
{
	int		i;
	char	*hex;
	char	*base_16;
	char	**arr;

	base_16 = "0123456789ABCDEF";
	*points = (t_point *)malloc(map->width * sizeof(t_point));
	if (!*points)
		return ;
	arr = ft_split(line, ' ');
	i = 0;
	while (i < map->width && arr[i])
	{
		(*points)[i].x = i;
		(*points)[i].y = row;
		(*points)[i].z = ft_atoi(arr[i]);
		hex = ft_strchr(arr[i], ',');
		ft_strtoupper(hex);
		if (hex)
			(*points)[i].color = ft_atoi_base(hex + 3, base_16);
		else
			(*points)[i].color = default_color((*points)[i].z);
		i++;
	}
	ft_free_2arr(arr);
}

t_point	**extract_points(char *fn, t_map *map)
{
	int		i;
	int		fd;
	char	*line;
	t_point	**points;

	fd = open(fn, O_RDONLY);
	if (fd == -1)
		error_exit("fdf: open error", NULL, 1);
	points = (t_point **)malloc((map->height + 1) * sizeof(t_point *));
	if (!points)
		error_exit("fdf: failed to malloc points", NULL, 1);
	i = 0;
	while (i < map->height)
	{
		line = get_next_line(fd);
		fill_points(line, &points[i], map, i);
		if (!points[i])
			error_exit("fdf: failed to fill points", map, 1);
		free(line);
		i++;
	}
	points[i] = NULL;
	close(fd);
	return (points);
}
