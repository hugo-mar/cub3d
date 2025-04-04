/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugo-mar <hugo-mar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 14:06:34 by hugo-mar          #+#    #+#             */
/*   Updated: 2025/04/04 23:50:14 by hugo-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
Computes the “delta distance,” i.e., how far the ray travels between
each x or y grid boundary. It returns a very large value if the ray direction
is zero to avoid division by zero.
*/
double	get_delta_dist(double ray_dir)
{
	if (!ray_dir)
		return (1e30);
	return (fabs(1 / ray_dir));
}

/*
Draws the vertical wall slice for the current column (x).
It uses draw_start and draw_end to know where to fill pixels, and it selects a
different shade of color depending on whether the wall was hit on the x-side or
y-side.
*/
void	draw_vertical_line(t_game *g, int x)
{
	int	y;

	y = g->ray.draw_start;
	if (g->ray.side == 1)
		while (y <= g->ray.draw_end)
			my_mlx_pixel_put(&g->mlx, x, y++, 0x00FFFFFF);
	else
		while (y <= g->ray.draw_end)
			my_mlx_pixel_put(&g->mlx, x, y++, 0x00999999);
}
