/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: divalent <divalent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 15:08:44 by hugo-mar          #+#    #+#             */
/*   Updated: 2025/04/10 16:45:38 by divalent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static double	get_delta_dist(double ray_dir)
{
	if (!ray_dir)
		return (1e30);
	return (fabs(1 / ray_dir));
}

void	render_frame(t_game *game)
{
	int	x;

	x = 0;
	while (x < WIN_WIDTH)
	{
		//calculate ray position and direction
		game->ray.camera_x = 2 * x / (double)WIN_WIDTH - 1;
		game->ray.ray_dir_x = game->player.dir_x + game->player.plane_x * game->ray.camera_x;
		game->ray.ray_dir_y = game->player.dir_y + game->player.plane_y * game->ray.camera_x;

		//which box of the map we're in
		game->ray.map_x = (int)game->player.pos_x;
		game->ray.map_y = (int)game->player.pos_y;

		//length of ray from one x or y-side to next x or y-side
		game->ray.delta_dist_x = get_delta_dist(game->ray.ray_dir_x);
		game->ray.delta_dist_y = get_delta_dist(game->ray.ray_dir_y);

		game->ray.hit = 0;
  
		//calculate step and initial side_dist
		if (game->ray.ray_dir_x < 0)
		{
			game->ray.step_x = -1;
			game->ray.side_dist_x = (game->player.pos_x - game->ray.map_x) * game->ray.delta_dist_x;
		}
		else
		{
			game->ray.step_x = 1;
			game->ray.side_dist_x = (game->ray.map_x + 1.0 - game->player.pos_x) * game->ray.delta_dist_x;
		}
		if (game->ray.ray_dir_y < 0)
		{
			game->ray.step_y = -1;
			game->ray.side_dist_y = (game->player.pos_y - game->ray.map_y) * game->ray.delta_dist_y;
		}
		else
		{
			game->ray.step_y = 1;
			game->ray.side_dist_y = (game->ray.map_y + 1.0 - game->player.pos_y) * game->ray.delta_dist_y;
		}

		//perform DDA
		while (!game->ray.hit)
		{
			if (game->ray.side_dist_x < game->ray.side_dist_y)
			{
				game->ray.side_dist_x += game->ray.delta_dist_x;
				game->ray.map_x += game->ray.step_x;
				game->ray.side = 0;
			}
			else
			{
				game->ray.side_dist_y += game->ray.delta_dist_y;
				game->ray.map_y += game->ray.step_y;
				game->ray.side = 1;
			}
			if(game->map.grid[game->ray.map_x][game->ray.map_y] > 0)
				game->ray.hit = 1;
		}

		//Calculate distance projected on camera direction.
		//This is the shortest distance from the point where the wall is hit to the camera plane.
		if (game->ray.side == 0)
			game->ray.perp_wall_dist = game->ray.side_dist_x - game->ray.delta_dist_x;
		else
			game->ray.perp_wall_dist = game->ray.side_dist_y - game->ray.delta_dist_y;
		
		//Calculate height of line to draw on screen
		game->ray.line_height = (int)(WIN_HEIGHT / game->ray.perp_wall_dist);
		
		//calculate lowest and highest pixel to fill in current stripe
		game->ray.draw_start = (WIN_HEIGHT / 2) - (game->ray.line_height / 2);
		if (game->ray.draw_start < 0)
			game->ray.draw_start = 0;
		game->ray.draw_end = (WIN_HEIGHT / 2) + (game->ray.line_height / 2);
		if (game->ray.draw_end >= WIN_HEIGHT)
			game->ray.draw_end = WIN_HEIGHT -1;

		//draw the pixels of the stripe as a vertical line
		int	y;
		y = game->ray.draw_start;
		if (game->ray.side == 1)
			while (y <= game->ray.draw_end)
				my_mlx_pixel_put(&game->mlx, x, y++, 0x00FFFFFF);
		else
			while (y <= game->ray.draw_end)
				my_mlx_pixel_put(&game->mlx, x, y++, 0x00999999);
	
		x++;
	}
}
