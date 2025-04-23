/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: divalent <divalent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 16:15:38 by hugo-mar          #+#    #+#             */
/*   Updated: 2025/04/23 17:37:07 by divalent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "cub3d.h"

void	fill_pixels(t_game *game, float x, float y, int color)
{
	int	dy;
	int	dx;
	int	scale_x;
	int	scale_y;
	int	cell_size;

	scale_x = 200 / game->map.width;
	scale_y = 200 / game->map.height;
	if (scale_x < scale_y)
		cell_size = scale_x;
	else
		cell_size = scale_y;
	dx = 0;
	dy = 0;
	while (dy < cell_size)
	{
		while (dx < cell_size)
		{
			my_mlx_pixel_put(&game->mlx, (x * cell_size) + dx,
				(y * cell_size) + dy, color);
			dx++;
		}
		dx = 0;
		dy++;
	}
}

void	fill_background(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y <= game->map.height)
	{
		x = 0;
		while (x <= game->map.width + 1)
		{
			fill_pixels(game, x, y, 0xcccccc);
			x++;
		}
		y++;
	}
}

void	fill_minimap(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (game->map.original[y])
	{
		while (game->map.original[y][x])
		{
			if (game->map.original[y][x] == '1')
				fill_pixels(game, x + 1, y, 0x0000FF);
			x++;
		}
		x = 0;
		y++;
	}
}

void	make_minimap(t_game *game)
{
	fill_background(game);
	fill_minimap(game);
	draw_player(game);
}
