/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugo-mar <hugo-mar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 15:08:44 by hugo-mar          #+#    #+#             */
/*   Updated: 2025/04/22 15:29:44 by hugo-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
Initializes the ray for the current column (x).
It calculates the camera plane coordinate (camera_x), sets the ray directions
(ray_dir_x, ray_dir_y), determines the map cell indices (map_x, map_y),
and computes the initial delta distances. It also resets the hit flag.
*/
void	init_ray(t_game *g, int x)
{
	g->ray.camera_x = 2 * x / (double)WIN_WIDTH - 1;
	g->ray.ray_dir_x
		= g->player.dir_x + g->player.plane_x * g->ray.camera_x;
	g->ray.ray_dir_y
		= g->player.dir_y + g->player.plane_y * g->ray.camera_x;
	g->ray.map_x = (int)g->player.pos_x;
	g->ray.map_y = (int)g->player.pos_y;
	g->ray.delta_dist_x = get_delta_dist(g->ray.ray_dir_x);
	g->ray.delta_dist_y = get_delta_dist(g->ray.ray_dir_y);
	g->ray.hit = 0;
}

/*
Determines the step direction (step_x and step_y) based on the sign of the ray
directions. It then calculates the initial distances to the next x or y side
boundary (side_dist_x, side_dist_y), which are used in the DDA loop.
*/
void	set_step_and_side_dist(t_game *g)
{
	if (g->ray.ray_dir_x < 0)
	{
		g->ray.step_x = -1;
		g->ray.side_dist_x
			= (g->player.pos_x - g->ray.map_x) * g->ray.delta_dist_x;
	}
	else
	{
		g->ray.step_x = 1;
		g->ray.side_dist_x
			= (g->ray.map_x + 1.0 - g->player.pos_x) * g->ray.delta_dist_x;
	}
	if (g->ray.ray_dir_y < 0)
	{
		g->ray.step_y = -1;
		g->ray.side_dist_y
			= (g->player.pos_y - g->ray.map_y) * g->ray.delta_dist_y;
	}
	else
	{
		g->ray.step_y = 1;
		g->ray.side_dist_y
			= (g->ray.map_y + 1.0 - g->player.pos_y) * g->ray.delta_dist_y;
	}
}

/*
Performs the Digital Differential Analyzer loop.
It advances the ray step-by-step in the appropriate direction (x or y) and
checks if a wall cell has been reached, setting the hit flag accordingly.
*/
void	perform_dda(t_game *g)
{
	while (!g->ray.hit)
	{
		if (g->ray.side_dist_x < g->ray.side_dist_y)
		{
			g->ray.side_dist_x += g->ray.delta_dist_x;
			g->ray.map_x += g->ray.step_x;
			g->ray.side = 0;
		}
		else
		{
			g->ray.side_dist_y += g->ray.delta_dist_y;
			g->ray.map_y += g->ray.step_y;
			g->ray.side = 1;
		}
		if (g->map.grid[g->ray.map_x][g->ray.map_y] > 0)
			g->ray.hit = 1;
	}
}

/*
Calculates the perpendicular distance to the wall hit by the ray
(perp_wall_dist). Based on that distance, it computes the line height in pixels
(line_height) and determines the draw range (draw_start and draw_end) on the
screen for that vertical slice.
*/
void	compute_wall_distance(t_game *g)
{
	if (g->ray.side == 0)
		g->ray.perp_wall_dist = g->ray.side_dist_x - g->ray.delta_dist_x;
	else
		g->ray.perp_wall_dist = g->ray.side_dist_y - g->ray.delta_dist_y;
	g->ray.line_height = (int)(WIN_HEIGHT / g->ray.perp_wall_dist);
	g->ray.draw_start = (WIN_HEIGHT / 2) - (g->ray.line_height / 2);
	if (g->ray.draw_start < 0)
		g->ray.draw_start = 0;
	g->ray.draw_end = (WIN_HEIGHT / 2) + (g->ray.line_height / 2);
	if (g->ray.draw_end >= WIN_HEIGHT)
		g->ray.draw_end = WIN_HEIGHT -1;
}

void	draw_floor_and_sky(t_game *game, int x)
{
	int	y;
	
	y = 0;
	if (game->ray.draw_start)
		while (y < game->ray.draw_start)
			my_mlx_pixel_put(&game->mlx, x, y++, game->sky_color);
	if (game->ray.draw_end != WIN_HEIGHT - 1)
	{
		y = game->ray.draw_end;	
		while (y < WIN_HEIGHT - 1)
			my_mlx_pixel_put(&game->mlx, x, y++, game->floor_color);
	}
}

/*
Main rendering function called each frame.
It loops through every vertical screen column (x), initializes and traces the
ray, calculates the distance to the wall, and finally draws the corresponding
vertical line on the screen.
*/
int	render_frame(t_game *game)
{
	int	x;

	x = 0;
	clear_image(&game->mlx);
	while (x < WIN_WIDTH)
	{
		init_ray(game, x);
		set_step_and_side_dist(game);
		perform_dda(game);
		compute_wall_distance(game);
		draw_floor_and_sky(game, x);
		if (TEXTURED_RAYCASTER)
			draw_textured_column(game, x);
		else
			draw_vertical_line(game, x);
		x++;
	}
	// make_minimap(game);
	// redraw_minimap(game);
	// draw_player(game);
	mlx_put_image_to_window(game->mlx.mlx, game->mlx.win, game->mlx.img, 0, 0);
	process_player_movement(game);
	return (0);
}
