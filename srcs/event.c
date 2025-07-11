/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akok <akok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 14:01:25 by akok              #+#    #+#             */
/*   Updated: 2025/07/10 19:46:54 by akok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	handle_zoom(int button, t_fdf *fdf);

// handle keyboard event
// only re-render if specific event happened
int	handle_key_event(int keysym, t_fdf *fdf)
{
	if (keysym == XK_Escape)
		cleanup_and_exit(fdf);
	if ((handle_view(keysym, fdf))
		|| (handle_elevation(keysym, fdf))
		|| (handle_rotation(keysym, fdf))
		|| (handle_offset(keysym, fdf)))
		render(fdf);
	return (0);
}

int	handle_mouse_event(int button, int x, int y, t_fdf *fdf)
{
	(void)x;
	(void)y;
	if (handle_zoom(button, fdf))
		render(fdf);
	return (0);
}

static int	handle_zoom(int button, t_fdf *fdf)
{
	if (button == 4)
		fdf->map->zoom += 1;
	else if (button == 5 && fdf->map->zoom > 1)
		fdf->map->zoom -= 1;
	else
		return (0);
	return (1);
}
