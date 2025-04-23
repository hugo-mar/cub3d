/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugo-mar <hugo-mar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 17:34:19 by hugo-mar          #+#    #+#             */
/*   Updated: 2025/04/23 16:00:28 by hugo-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
Calculates the fractional collision point along the wall (a value between 0 and
1) where the ray hits. Depending if the wall is vertical or horizontal, it uses
the appropriate player coordinate and ray direction.
*/
double	compute_wall_x(t_game *g)
{
	double	wall_x;

	if (g->ray.side == 0)
		wall_x = g->player.pos_y + g->ray.perp_wall_dist * g->ray.ray_dir_y;
	else
		wall_x = g->player.pos_x + g->ray.perp_wall_dist * g->ray.ray_dir_x;
	wall_x -= floor(wall_x);
	return (wall_x);
}

/*
Converts the fractional collision value (wall_x) into a texture column index by
multiplying it by the texture width. It adjusts the index for proper mirroring
based on the ray’s direction.
*/
int	compute_texture_x(double wall_x, t_texture *tex, t_game *g)
{
	int	tex_x;

	tex_x = (int)(wall_x * (double)tex->width);
	if (g->ray.side == 0 && g->ray.ray_dir_x > 0)
		tex_x = tex->width - tex_x - 1;
	if (g->ray.side == 1 && g->ray.ray_dir_y < 0)
		tex_x = tex->width - tex_x - 1;
	return (tex_x);
}

/*
Computes the vertical texture mapping parameters, calculating the pixel step and
the initial texture coordinate (tex_pos) to ensure proper alignment even when
clipping occurs
*/
void	compute_texture_mapping_params(t_game *g, t_tex_col *tc)
{
	tc->step = (double)tc->tex->height / g->ray.line_height;
	tc->tex_pos = (g->ray.draw_start - WIN_HEIGHT / 2
			+ g->ray.line_height / 2) * tc->step;
}

/*
Renders a vertical column of a textured wall by mapping each screen pixel to its
corresponding texture pixel and updating the texture coordinate with each
iteration.
*/
void	render_texture_column_pixels(t_game *g, t_tex_col *tc, int x)
{
	int	y;

	y = g->ray.draw_start;
	while (y < g->ray.draw_end)
	{
		tc->tex_y = (int)tc->tex_pos % tc->tex->height;
		tc->tex_pos += tc->step;
		tc->color = ((unsigned int *)tc->tex->addr)
		[tc->tex_y * tc->tex->width + tc->tex_x];
		my_mlx_pixel_put(&g->mlx, x, y, tc->color);
		y++;
	}
}

/*
This function renders a vertical textured wall column by computing the collision
point, determining the appropriate texture coordinates, and then mapping and
rendering the column pixels on screen.
*/
void	draw_textured_column(t_game *g, int x)
{
	t_tex_col	tc;

	select_wall_texture(g, &tc);
	tc.wall_x = compute_wall_x(g);
	tc.tex_x = compute_texture_x(tc.wall_x, tc.tex, g);
	compute_texture_mapping_params(g, &tc);
	render_texture_column_pixels(g, &tc, x);
}
